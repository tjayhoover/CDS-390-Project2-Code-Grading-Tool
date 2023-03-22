#ifndef CREATE_ASSIGNMENT_HPP
#define CREATE_ASSIGNMENT_HPP

#include "abstract_authenticator.hpp"
#include "abstract_database.hpp"
#include "presenter_interface.hpp"

class CreateAssignmentInteractor {

public:
    CreateAssignmentInteractor(AbstractDatabase*, AbstractAuthenticator*, CreateAssignmentPresenterInterface*);

    void createAssignment(create_assignment_request);

private:
 // Interface to database
    AbstractDatabase* storage;
    // Interface to presenter
    CreateAssignmentPresenterInterface* presenter;
    // Interface to authentication service
    AbstractAuthenticator* authenticator;
};

#endif