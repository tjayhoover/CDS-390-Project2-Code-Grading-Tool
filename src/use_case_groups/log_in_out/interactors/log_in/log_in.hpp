#ifndef LOG_IN_HPP
#define LOG_IN_HPP

#include "abstract_authenticator.hpp"
#include "abstract_database.hpp"
#include "presenter_interface.hpp"

class LoginInteractor {

public:
    LoginInteractor(AbstractDatabase*, AbstractAuthenticator*, LoginPresenterInterface*);

    std::pair<bool, User> log_in(login_request);

private:
    // Interface to database
    AbstractDatabase* storage;
    // Interface to presenter
    LoginPresenterInterface* presenter;
    // Interface to authentication service
    AbstractAuthenticator* authenticator;
};

#endif