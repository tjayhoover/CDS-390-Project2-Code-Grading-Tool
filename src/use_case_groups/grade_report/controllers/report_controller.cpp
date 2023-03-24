#include "report_controller.hpp"

#include <iostream>

using namespace std;

ReportController::ReportController(InstructorReportInteractor iri, StudentReportInteractor sri) :
    instructor_report_interactor(iri), student_report_interactor(sri) {}

void ReportController::get_instructor_report(instructor_report_input input_data) {

    // Initialize the request
    instructor_report_request request;

    // Get data from input and use it to fill request
    request.assignment_name = input_data.assignmentname;

    instructor_report_interactor.compileReport(request);
}

void ReportController::get_student_report(student_report_input input_data) {

    // Initialize the request object
    student_report_request request;
    request.username = input_data.studentname;

    cout << request.username << endl;

    // Hand the request to the interactor
    student_report_interactor.compileReport(request);
}