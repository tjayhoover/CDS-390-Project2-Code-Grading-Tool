#include "create_user.hpp"

CreateUserInteractor::CreateUserInteractor(AbstractDatabase* d, AbstractAuthenticator* a, CreateUserPresenterInterface* p):
    storage(d), authenticator(a), presenter(p) {}

void CreateUserInteractor::createUser(create_user_request data) {

    create_user_response response;
    response.message = "success";
    presenter->presentResult(response);
}