#ifndef STUDENT_REPORT_HPP
#define STUDENT_REPORT_HPP

#include "abstract_authenticator.hpp"
#include "abstract_database.hpp"
#include "presenter_interface.hpp"

#include "../../request_response_models/student_report_models.hpp"

class StudentReportInteractor {

public:
    StudentReportInteractor(AbstractDatabase*, AbstractAuthenticator*, StudentReportPresenterInterface*);

    void compileReport(student_report_request);

private:
 // Interface to database
    AbstractDatabase* storage;
    // Interface to presenter
    StudentReportPresenterInterface* presenter;
    // Interface to authentication service
    AbstractAuthenticator* authenticator;
};

#endif
