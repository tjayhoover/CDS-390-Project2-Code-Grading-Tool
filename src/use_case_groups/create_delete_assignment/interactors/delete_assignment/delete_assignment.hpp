#ifndef DELETE_ASSIGNMENT_HPP
#define DELETE_ASSIGNMENT_HPP

#include "abstract_authenticator.hpp"
#include "abstract_database.hpp"
#include "presenter_interface.hpp"

class DeleteAssignmentInteractor {

public:
    DeleteAssignmentInteractor(AbstractDatabase*, AbstractAuthenticator*, DeleteAssignmentPresenterInterface*);

    void deleteAssignment(delete_assignment_request);

private:
    // Interface to database
    AbstractDatabase* storage;
    // Interface to presenter
    DeleteAssignmentPresenterInterface* presenter;
    // Interface to authentication service
    AbstractAuthenticator* authenticator;
};


#endif