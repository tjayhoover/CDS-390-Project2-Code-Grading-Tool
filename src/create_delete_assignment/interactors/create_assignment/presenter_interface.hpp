#ifndef PRESENTER_INTERFACE_HPP
#define PRESENTER_INTERFACE_HPP

#include "../../request_response_models/login_models.hpp"

class PresenterInterface {

public:
    virtual void presentResult(login_response data) = 0;
};

#endif
