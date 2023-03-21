#ifndef PRESENTER_INTERFACE1_HPP
#define PRESENTER_INTERFACE1_HPP

#include "../../request_response_models/logout_models.hpp"

class LogoutPresenterInterface {

public:
    virtual void presentResult(logout_response data) = 0;
};

#endif