#ifndef PRESENTER_INTERFACE_HPP
#define PRESENTER_INTERFACE_HPP

#include "../../request_response_models/logout_models.hpp"

class PresenterInterface {

public:
    virtual void presentResult(logout_response data) = 0;
};

#endif