#ifndef INSTRUCTOR_REPORT_HPP
#define INSTRUCTOR_REPORT_HPP

#include "abstract_authenticator.hpp"
#include "abstract_database.hpp"
#include "presenter_interface.hpp"

class InstructorReportInteractor {

public:
    InstructorReportInteractor(AbstractDatabase*, AbstractAuthenticator*, InstructorReportPresenterInterface*);

    void compileReport(instructor_report_request);

private:
 // Interface to database
    AbstractDatabase* storage;
    // Interface to presenter
    InstructorReportPresenterInterface* presenter;
    // Interface to authentication service
    AbstractAuthenticator* authenticator;
};

#endif
