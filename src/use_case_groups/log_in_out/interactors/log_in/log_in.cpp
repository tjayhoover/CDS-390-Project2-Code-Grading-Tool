#include "log_in.hpp"

LoginInteractor::LoginInteractor(AbstractDatabase* d, AbstractAuthenticator* a, LoginPresenterInterface* p) :
    storage(d), authenticator(a), presenter(p) {}

void LoginInteractor::log_in(login_request data) {

    //authenticator->authenticate_user(data.username, data.password);

    // Initialize the return data struct
    login_response return_data;

    // Check if the user exists
    if(storage->exists(data.username)) {
        User user = storage->get_user(data.username);
        return_data.success = true;
        return_data.name = user.get_username();
        return_data.role = user.get_permission();
    }
    else return_data.success = false;

    // Present the result
    presenter->presentResult(return_data);
}