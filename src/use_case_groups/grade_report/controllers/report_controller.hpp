#ifndef REPORT_CONTROLLER_HPP
#define REPORT_CONTROLLER_HPP

#include "../interactors/instructor/instructor_report.hpp"
#include "../interactors/student/student_report.hpp"
#include "input_request_models.hpp"

#include <string>

class ReportController {
public:
    ReportController(InstructorReportInteractor, StudentReportInteractor);

    void get_instructor_report(instructor_report_input);
    void get_student_report(std::string);

private:
    InstructorReportInteractor instructor_report_interactor;
    StudentReportInteractor student_report_interactor;
};

#endif
