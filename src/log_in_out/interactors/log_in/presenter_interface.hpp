#ifndef PRESENTER_INTERFACE2_HPP
#define PRESENTER_INTERFACE2_HPP

#include "../../request_response_models/login_models.hpp"

class LoginPresenterInterface {

public:
    virtual void presentResult(login_response data) = 0;
};

#endif