#ifndef LOGIN_MODELS_HPP
#define LOGIN_MODELS_HPP

#include "../entities/user/user.hpp"
#include <string>

struct login_request {
    std::string username;
    std::string password;
};

struct login_response {
    bool success;
    std::string name;
    PermissionLevel role;
};

#endif