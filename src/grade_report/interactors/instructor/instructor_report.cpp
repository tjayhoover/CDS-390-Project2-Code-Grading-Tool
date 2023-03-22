#include "instructor_report.hpp"

InstructorReportInteractor::InstructorReportInteractor(AbstractDatabase* d, AbstractAuthenticator* a, InstructorReportPresenterInterface* p):
    storage(d), authenticator(a), presenter(p) {}

void InstructorReportInteractor::compileReport(instructor_report_request data) {

    instructor_report_response response;
    
    presenter->presentResult(response);
}