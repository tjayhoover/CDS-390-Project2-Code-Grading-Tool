#include "view_assignments_controller.hpp"

ViewAssignmentsController::ViewAssignmentsController(StudentViewAssignmentsInteractor svi) :
    student_view_assignments_interactor(svi) {}

void ViewAssignmentsController::student_view_assignments() {

    // Initialize request model object
    student_view_assignments_request request;
    
    // The request actually doesn't need to contain data as of now
    // I anticipate it will in the future, which is why I laid the groundwork

    // Hand the request to the interactor
    student_view_assignments_interactor.view_assignments(request);
}