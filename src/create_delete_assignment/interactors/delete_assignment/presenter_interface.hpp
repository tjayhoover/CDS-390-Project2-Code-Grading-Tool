#ifndef DELETE_ASSIGNMENT_PRESENTER_INTERFACE_HPP
#define DELETE_ASSIGNMENT_PRESENTER_INTERFACE_HPP

#include "../../request_response_models/delete_assignment_models.hpp"

class DeleteAssignmentPresenterInterface {

public:
    virtual void presentResult(delete_assignment_response data) = 0;
};

#endif