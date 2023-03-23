#include "change_password.hpp"

ChangePasswordInteractor::ChangePasswordInteractor(AbstractDatabase* db, AbstractAuthenticator* auth, ChangePasswordPresenterInterface* pres) :
    storage(db), authenticator(auth), presenter(pres) {}

void ChangePasswordInteractor::change_password(change_password_request request) {

    // Initialize response model object
    change_password_response response;

    // Change the password
    User user = storage->get_user(request.username);
    user.set_password(request.new_password);
    storage->add_user(user);

    response.success = true;

    presenter->presentResult(response);
}