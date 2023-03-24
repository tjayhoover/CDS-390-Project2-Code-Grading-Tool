#ifndef SUBMISSION_INPUT_REQUEST_MODELS_HPP
#define SUBMISSION_INPUT_REQUEST_MODELS_HPP

#include <string>

struct submit_assignment_input {
    std::string assignment_name;
    std::string code_path;
    std::string username;
};

#endif