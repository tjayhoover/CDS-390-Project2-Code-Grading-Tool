#ifndef CREATE_USER_MODELS_HPP
#define CREATE_USER_MODELS_HPP

#include "../entities/user/user.hpp"

#include <string>

struct create_user_request {
    std::string username;
    PermissionLevel permission_level;
};

struct create_user_response {
    bool success;
};

#endif
