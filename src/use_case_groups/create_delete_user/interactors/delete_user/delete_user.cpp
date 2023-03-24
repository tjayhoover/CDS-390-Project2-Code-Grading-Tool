#include "delete_user.hpp"

DeleteUserInteractor::DeleteUserInteractor(AbstractDatabase* d, AbstractAuthenticator* a, DeleteUserPresenterInterface* p):
    storage(d), authenticator(a), presenter(p) {}

void DeleteUserInteractor::deleteUser(delete_user_request data) {

    // Initialize the response object
    delete_user_response response;

    // Ask the database to delete the user
    bool success = false;
    try {
        storage->del_user(data.username);
        success = true;
    } catch(std::exception x) {
        // If it fails hand back the error message for the user to see
        response.error = x.what();
    }

    response.success = success;
    presenter->presentResult(response);
}