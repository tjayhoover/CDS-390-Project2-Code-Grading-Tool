#ifndef DELETE_USER_MODELS_HPP
#define DELETE_USER_MODELS_HPP

#include <string>

struct delete_user_request {
    std::string username;
};

struct delete_user_response {
    std::string message;
};

#endif