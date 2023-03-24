#ifndef CREATE_DELETE_INPUT_REQUEST_MODELS_HPP
#define CREATE_DELETE_INPUT_REQUEST_MODELS_HPP

#include <string>

struct create_user_input {
    std::string permission_level;
    std::string username;
};

struct delete_user_input {
    std::string username;
};

struct change_password_input {
    std::string username;
    std::string new_password;
    std::string old_password;
};

#endif