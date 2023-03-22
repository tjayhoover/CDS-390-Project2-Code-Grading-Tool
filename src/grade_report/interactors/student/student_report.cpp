#include "student_report.hpp"

StudentReportInteractor::StudentReportInteractor(AbstractDatabase* d, AbstractAuthenticator* a, StudentReportPresenterInterface* p):
    storage(d), authenticator(a), presenter(p) {}

void StudentReportInteractor::compileReport(student_report_request data) {

    student_report_response response;
    
    presenter->presentResult(response);
}