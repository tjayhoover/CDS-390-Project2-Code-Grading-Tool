#include "report_controller.hpp"

#include <iostream>

using namespace std;

ReportController::ReportController(InstructorReportInteractor iri, StudentReportInteractor sri) :
    instructor_report_interactor(iri), student_report_interactor(sri) {}

void ReportController::get_instructor_report() {

    // Initialize the request
    instructor_report_request request;

    cout << "Type the name of the assignment you want a report for:" << endl;
    string name;
    
    // Hotfix I don't like
    string newline;
    getline(cin, newline);
    getline(cin, name);

    request.assignment_name = name;

    instructor_report_interactor.compileReport(request);
}

void ReportController::get_student_report(std::string name) {

    // Initialize the request object
    student_report_request request;
    request.username = name;

    // Hand the request to the interactor
    student_report_interactor.compileReport(request);
}