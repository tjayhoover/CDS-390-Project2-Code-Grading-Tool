#ifndef PRESENTER_INTERFACE_HPP
#define PRESENTER_INTERFACE_HPP

#include "../request_response_models/submission_models.hpp"

class PresenterInterface {

public:

    virtual void presentResult(return_data data) = 0;


};

#endif