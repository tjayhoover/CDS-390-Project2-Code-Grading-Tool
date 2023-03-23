#ifndef CHANGE_PASSWORD_PRESENTER_INTERFACE_HPP
#define CHANGE_PASSWORD_PRESENTER_INTERFACE_HPP

#include "../../request_response_models/change_password_models.hpp"

class ChangePasswordPresenterInterface {

public:
    virtual void presentResult(change_password_response data) = 0;
};

#endif