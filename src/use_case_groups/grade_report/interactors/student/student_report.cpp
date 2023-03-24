#include "student_report.hpp"


StudentReportInteractor::StudentReportInteractor(AbstractDatabase* d, AbstractAuthenticator* a, StudentReportPresenterInterface* p):
    storage(d), authenticator(a), presenter(p) {}

void StudentReportInteractor::compileReport(student_report_request data) {

    // Initialize the response object
    student_report_response response;

    // Get a list of all assignments from storage
    auto assignments = storage->get_assignments();

    // Some of this is database logic and should not be here
    for(auto& assignment: assignments) {
        for(const auto& name: assignment.get_submissions()) {
            Submission submission = storage->get_submission(name);
            if(submission.get_student_name() == data.username) {
                response.assignment_names.push_back(assignment.get_name());
                response.cases_passed.push_back(submission.get_grade());
                response.total_cases.push_back(assignment.get_max_grade());
                response.submission_dates.push_back(submission.get_submission_time());
                response.due_dates.push_back(assignment.get_deadline());

                // If the assignment was late, add some info
                if(submission.get_submission_time() > assignment.get_deadline()) {
                    response.on_time.push_back(false);
                    response.durations_late.push_back(to_simple_string(submission.get_submission_time() - assignment.get_deadline()));
                }
                else {
                    response.on_time.push_back(true);
                    response.durations_late.push_back("");
                }
            }
        }
    }

    // Hand the response to the presenter
    presenter->presentResult(response);
}