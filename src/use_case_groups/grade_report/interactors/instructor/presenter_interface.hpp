#ifndef INSTRUCTOR_REPORT_PRESENTER_INTERFACE_HPP
#define INSTRUCTOR_REPORT_PRESENTER_INTERFACE_HPP

#include "../../request_response_models/instructor_report_models.hpp"

class InstructorReportPresenterInterface {

public:
    virtual void presentResult(instructor_report_response data) = 0;
};

#endif
