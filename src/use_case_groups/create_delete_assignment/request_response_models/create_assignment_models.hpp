#ifndef CREATE_ASSIGNMENT_MODELS_HPP
#define CREATE_ASSIGNMENT_MODELS_HPP

#include <string>
#include <vector>
#include <boost/date_time/posix_time/posix_time.hpp>

struct create_assignment_request {
    std::string assignment_name;
    std::string description;
    std::vector<std::string> input_files;
    std::vector<std::string> output_files;
    boost::posix_time::ptime due_date;
};

struct create_assignment_response {
    bool success;
};

#endif