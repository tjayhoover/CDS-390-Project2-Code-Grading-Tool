#include "create_user.hpp"

CreateUserInteractor::CreateUserInteractor(AbstractDatabase* d, AbstractAuthenticator* a, CreateUserPresenterInterface* p):
    storage(d), authenticator(a), presenter(p) {}

void CreateUserInteractor::createUser(create_user_request data) {

    // Create the response model object
    create_user_response response;

    // Create the new user
    User user(data.permission_level, data.username);

    // Not sure how this will be handled yet
    user.set_password("password");

    // Add the user to the database
    storage->add_user(user);

    response.success = true;
    presenter->presentResult(response);
}