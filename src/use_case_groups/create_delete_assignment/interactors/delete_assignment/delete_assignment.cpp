#include "delete_assignment.hpp"

DeleteAssignmentInteractor::DeleteAssignmentInteractor(AbstractDatabase* d, AbstractAuthenticator* a, DeleteAssignmentPresenterInterface* p) :
    storage(d), authenticator(a), presenter(p) {}

void DeleteAssignmentInteractor::deleteAssignment(delete_assignment_request data) {

    // Initialize the response
    delete_assignment_response response;

    // Ask the database to delete the assignment
    try {
        storage->del_assignment(data.assignment_name);
        response.success = true;
    }
    catch (std::exception e) {
        response.success = false;
        response.error = e.what();
    }

    // Hand the presenter the response
    presenter->presentResult(response);
}