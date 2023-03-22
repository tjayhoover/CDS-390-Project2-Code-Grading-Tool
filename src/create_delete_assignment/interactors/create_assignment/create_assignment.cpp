#include "create_assignment.hpp"

CreateAssignmentInteractor::CreateAssignmentInteractor(AbstractDatabase* d, AbstractAuthenticator* a, CreateAssignmentPresenterInterface* p):
    storage(d), authenticator(a), presenter(p) {}

void CreateAssignmentInteractor::createAssignment(create_assignment_request data) {

    create_assignment_response response;
    response.message = "success";
    presenter->presentResult(response);
}