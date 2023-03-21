#include "log_in.hpp"

LoginInteractor::LoginInteractor(AbstractDatabase* d, AbstractAuthenticator* a, LoginPresenterInterface* p) :
    storage(d), authenticator(a), presenter(p) {}

void LoginInteractor::log_in(login_request data) {

    authenticator->authenticate_user(data.username, data.password);

    login_response return_data;
    return_data.name = data.username;
    return_data.role = "Admin";
    return_data.menu = "(1) View Assignments\n(2) Submit Assignment\n(3) Log Out";

    presenter->presentResult(return_data);
}