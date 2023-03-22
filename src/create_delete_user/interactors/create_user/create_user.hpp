#ifndef CREATE_USER_HPP
#define CREATE_USER_HPP

#include "abstract_authenticator.hpp"
#include "abstract_database.hpp"
#include "presenter_interface.hpp"

class CreateUserInteractor {

public:
    CreateUserInteractor(AbstractDatabase*, AbstractAuthenticator*, CreateUserPresenterInterface*);

    void createUser(create_user_request);

private:
 // Interface to database
    AbstractDatabase* storage;
    // Interface to presenter
    CreateUserPresenterInterface* presenter;
    // Interface to authentication service
    AbstractAuthenticator* authenticator;
};

#endif