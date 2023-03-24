#ifndef CREATE_DELETE_ASSIGNMENT_INPUT_REQUEST_MODELS_HPP
#define CREATE_DELETE_ASSIGNMENT_INPUT_REQUEST_MODELS_HPP

#include <string>

struct create_assignment_input {
    std::string name;
    std::string description;
    std::string due_date;
    std::string input_files_path;
    std::string output_files_path;
};

struct delete_assignment_input {
    std::string assignment_name;
};

#endif