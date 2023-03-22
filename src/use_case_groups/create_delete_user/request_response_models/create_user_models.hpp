#ifndef CREATE_USER_MODELS_HPP
#define CREATE_USER_MODELS_HPP

#include <string>

struct create_user_request {
    std::string username;
};

struct create_user_response {
    std::string message;
};

#endif
