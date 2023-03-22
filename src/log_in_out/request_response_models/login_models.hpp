#ifndef LOGIN_MODELS_HPP
#define LOGIN_MODELS_HPP

#include <string>

struct login_request {

    std::string username;
    std::string password;
};

struct login_response {
    std::string name;
    std::string role;
};

#endif