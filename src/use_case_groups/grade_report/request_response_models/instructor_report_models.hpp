#ifndef INSTRUCTOR_REPORT_MODELS_HPP
#define INSTRUCTOR_REPORT_MODELS_HPP

#include <string>
#include <vector>
#include <boost/date_time/posix_time/posix_time.hpp>

struct instructor_report_request {
    std::string assignment_name;
};

struct instructor_report_response {
    std::vector<std::string> student_names;
    std::vector<boost::posix_time::ptime> submission_dates;
    std::vector<int> cases_passed;
    int total_cases;
};


#endif