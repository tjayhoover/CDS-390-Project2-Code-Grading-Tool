#include "report_controller.hpp"

ReportController::ReportController(InstructorReportInteractor iri, StudentReportInteractor sri) :
    instructor_report_interactor(iri), student_report_interactor(sri) {}

void ReportController::get_instructor_report() {

    instructor_report_request request;

    instructor_report_interactor.compileReport(request);
}

void ReportController::get_student_report(std::string name) {

    // Initialize the request object
    student_report_request request;
    request.username = name;

    // Hand the request to the interactor
    student_report_interactor.compileReport(request);
}