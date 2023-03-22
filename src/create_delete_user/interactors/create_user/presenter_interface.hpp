#ifndef CREATE_USER_PRESENTER_INTERFACE_HPP
#define CREATE_USER_PRESENTER_INTERFACE_HPP

#include "../../request_response_models/create_user_models.hpp"

class CreateUserPresenterInterface {

public:
    virtual void presentResult(create_user_response data) = 0;
};

#endif