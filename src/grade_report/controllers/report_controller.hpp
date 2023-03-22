#ifndef REPORT_CONTROLLER_HPP
#define REPORT_CONTROLLER_HPP

#include "../interactors/instructor/instructor_report.hpp"
#include "../interactors/student/student_report.hpp"

class ReportController {
public:
    ReportController(InstructorReportInteractor, StudentReportInteractor);

    void get_instructor_report();
    void get_student_report();

private:
    InstructorReportInteractor instructor_report_interactor;
    StudentReportInteractor student_report_interactor;
};

#endif
