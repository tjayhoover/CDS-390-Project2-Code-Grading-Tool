#include "delete_user.hpp"

DeleteUserInteractor::DeleteUserInteractor(AbstractDatabase* d, AbstractAuthenticator* a, DeleteUserPresenterInterface* p):
    storage(d), authenticator(a), presenter(p) {}

void DeleteUserInteractor::deleteUser(delete_user_request data) {

    delete_user_response response;
    response.message = "success";
    presenter->presentResult(response);
}