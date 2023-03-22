#ifndef CREATE_ASSIGNMENT_MODELS_HPP
#define CREATE_ASSIGNMENT_MODELS_HPP

#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>

struct create_assignment_request {
    std::string assignment_name;
    std::string description;
    std::string input_files_path;
    std::string output_files_path;
    boost::posix_time::ptime due_date;
};

struct create_assignment_response {
    std::string message;
};

#endif