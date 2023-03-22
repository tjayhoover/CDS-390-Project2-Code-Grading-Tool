#include "delete_assignment.hpp"

DeleteAssignmentInteractor::DeleteAssignmentInteractor(AbstractDatabase* d, AbstractAuthenticator* a, DeleteAssignmentPresenterInterface* p) :
    storage(d), authenticator(a), presenter(p) {}

void DeleteAssignmentInteractor::deleteAssignment(delete_assignment_request data) {

    delete_assignment_response response;

    response.message = "Success";
    presenter->presentResult(response);
}