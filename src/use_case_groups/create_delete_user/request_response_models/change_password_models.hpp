#ifndef CHANGE_PASSWORD_MODELS_HPP
#define CHANGE_PASSWORD_MODELS_HPP

#include <string>

struct change_password_request {
    std::string username;
    std::string current_password;
    std::string new_password;
};

struct change_password_response {
    bool success;
};

#endif