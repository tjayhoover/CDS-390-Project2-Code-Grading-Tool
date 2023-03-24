#include "instructor_report.hpp"

InstructorReportInteractor::InstructorReportInteractor(AbstractDatabase* d, AbstractAuthenticator* a, InstructorReportPresenterInterface* p):
    storage(d), authenticator(a), presenter(p) {}

void InstructorReportInteractor::compileReport(instructor_report_request data) {

    // Initialize the response
    instructor_report_response response;

    // Ask the database a copy of the assignment in question
    Assignment assignment = storage->get_assignment(data.assignment_name);

    auto submission_names = assignment.get_submissions();

    response.total_cases = assignment.get_max_grade();

    // Should do try catch since this is io bound
    for(const auto& sub: submission_names) {
        Submission submission = storage->get_submission(sub);
        response.student_names.push_back(submission.get_student_name());
        response.submission_dates.push_back(submission.get_submission_time());
        response.cases_passed.push_back(submission.get_grade());
        if(submission.get_submission_time() > assignment.get_deadline()) {
            response.on_time.push_back(false);
            response.durations_late.push_back(to_simple_string(submission.get_submission_time() - assignment.get_deadline()));
        }
        else {
            response.durations_late.push_back("");
            response.on_time.push_back(true);
        }
    }
    
    presenter->presentResult(response);
}