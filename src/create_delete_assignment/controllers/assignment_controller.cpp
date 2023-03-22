#include "assignment_controller.hpp"

AssignmentController::AssignmentController(CreateAssignmentInteractor ci, DeleteAssignmentInteractor di) :
    create_assignment_interactor(ci), delete_assignment_interactor(di) {}

void AssignmentController::create_assignment() {

    create_assignment_request request;


    create_assignment_interactor.createAssignment(request);
}

void AssignmentController::delete_assignment() {

    delete_assignment_request request;
    

    delete_assignment_interactor.deleteAssignment(request);
}