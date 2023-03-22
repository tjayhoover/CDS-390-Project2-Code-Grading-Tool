#include "submit_assignment.hpp"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

SubmissionInteractor::SubmissionInteractor(AbstractDatabase* d, AbstractGrader* g, PresenterInterface* p)
 : presenter(p), storage(d), grader(g) {}

void SubmissionInteractor::submit_assignment(submission_request sub) {

    // Initialize a response object
    submission_response data;

    // First check if the assignment exists:
    bool assignment_found = storage->exists(sub.assignment_name);

    if(!assignment_found) {
        data.success = false;
        presenter->presentResult(data);
        return;
    }

    // The assignment exitst, so get the assigment corresponding to this submission:
    Assignment assignment = storage->get_assignment(sub.assignment_name);

    std::string submission_name = sub.assignment_name + sub.student_name + std::to_string(assignment.get_num_submissions());

    // Create the submission object
    Submission submission(submission_name, sub.student_name, sub.program, boost::posix_time::second_clock::local_time());
    
    std::vector<std::pair<std::string, std::string>> test_cases = assignment.get_test_cases();

    int num_test_cases = test_cases.size();
    int num_passed = 0;

    // Grade each test case
    for(auto& test_case_pair: test_cases) {
        std::string input = storage->get_input_case(test_case_pair.first);
        std::string output = storage->get_output_case(test_case_pair.second);
        if(grader->grade_code(sub.program, input, output)) {
            ++num_passed;
        }
    }

    submission.set_grade(num_passed);

    storage->add_submission(submission);

    // Compile the output data
    data.success = true;
    data.num_cases = num_test_cases;
    data.num_passed = num_passed;

    // Now hand that struct, and control, to the presenter,
    // which will format the data for the view
    presenter->presentResult(data);
}