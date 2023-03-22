#ifndef CREATE_ASSIGNMENT_PRESENTER_INTERFACE_HPP
#define CREATE_ASSIGNMENT_PRESENTER_INTERFACE_HPP

#include "../../request_response_models/create_assignment_models.hpp"

class CreateAssignmentPresenterInterface {

public:
    virtual void presentResult(create_assignment_response data) = 0;
};

#endif