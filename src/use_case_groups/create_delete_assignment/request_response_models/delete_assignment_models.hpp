#ifndef DELETE_ASSIGNMENT_MODELS_HPP
#define DELETE_ASSIGNMENT_MODELS_HPP

#include <string>

struct delete_assignment_request {
    std::string assignment_name;
};

struct delete_assignment_response {
    bool success;
    std::string error;
};

#endif