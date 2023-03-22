#ifndef SUBMISSION_MODELS_HPP
#define SUBMISSION_MODELS_HPP

#include "boost/date_time/posix_time/posix_time.hpp"
#include <string>

struct incoming_submission {
    std::string student_name;
    std::string assignment_name;
    std::string program;
    boost::posix_time::ptime submission_time;
};

struct return_data {
    int grade;
};

#endif