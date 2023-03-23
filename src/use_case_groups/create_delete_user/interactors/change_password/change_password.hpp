#ifndef CHANGE_PASSWORD_HPP
#define CHANGE_PASSWORD_HPP

#include "abstract_authenticator.hpp"
#include "abstract_database.hpp"
#include "presenter_interface.hpp"
#include "../../request_response_models/change_password_models.hpp"

class ChangePasswordInteractor {

public:
    ChangePasswordInteractor(AbstractDatabase*, AbstractAuthenticator*, ChangePasswordPresenterInterface*);

    void change_password(change_password_request);

private:
 // Interface to database
    AbstractDatabase* storage;
    // Interface to presenter
    ChangePasswordPresenterInterface* presenter;
    // Interface to authentication service
    AbstractAuthenticator* authenticator;
};

#endif
