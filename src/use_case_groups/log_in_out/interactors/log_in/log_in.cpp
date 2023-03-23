#include "log_in.hpp"

LoginInteractor::LoginInteractor(AbstractDatabase* d, AbstractAuthenticator* a, LoginPresenterInterface* p) :
    storage(d), authenticator(a), presenter(p) {}

std::pair<bool, User> LoginInteractor::log_in(login_request data) {

    //authenticator->authenticate_user(data.username, data.password);

    // Initialize the return data struct
    login_response return_data;

    // Create a default initialized user
    User user;
    bool success = false;
    // Check if the user exists
    if(storage->exists(data.username)) {
        user = storage->get_user(data.username);

        // Authentication needs to be implemented
        
        success = true;
        return_data.name = user.get_username();
        return_data.role = user.get_permission();
    }
    return_data.success = success;
    // Present the result
    presenter->presentResult(return_data);

    // Return a copy of the user to the controller so it can give it to the UI
    return {success, user};
}