#ifndef STUDENT_REPORT_PRESENTER_INTERFACE_HPP
#define STUDENT_REPORT_PRESENTER_INTERFACE_HPP

#include "../../request_response_models/student_report_models.hpp"

class StudentReportPresenterInterface {

public:
    virtual void presentResult(student_report_response data) = 0;
};

#endif