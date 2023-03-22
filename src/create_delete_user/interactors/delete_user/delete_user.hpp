#ifndef Delete_USER_HPP
#define Delete_USER_HPP

#include "abstract_authenticator.hpp"
#include "abstract_database.hpp"
#include "presenter_interface.hpp"

class DeleteUserInteractor {

public:
    DeleteUserInteractor(AbstractDatabase*, AbstractAuthenticator*, DeleteUserPresenterInterface*);

    void deleteUser(delete_user_request);

private:
 // Interface to database
    AbstractDatabase* storage;
    // Interface to presenter
    DeleteUserPresenterInterface* presenter;
    // Interface to authentication service
    AbstractAuthenticator* authenticator;
};

#endif