#ifndef DELETE_USER_PRESENTER_INTERFACE_HPP
#define DELETE_USER_PRESENTER_INTERFACE_HPP

#include "../../request_response_models/delete_user_models.hpp"

class DeleteUserPresenterInterface {

public:
    virtual void presentResult(delete_user_response data) = 0;
};

#endif