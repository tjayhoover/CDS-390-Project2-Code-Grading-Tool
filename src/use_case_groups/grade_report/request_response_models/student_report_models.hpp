#ifndef STUDENT_REPORT_MODELS_HPP
#define STUDENT_REPORT_MODELS_HPP

#include <string>
#include <vector>
#include <boost/date_time/posix_time/posix_time.hpp>

struct student_report_request {
    std::string username;

    // Start and end dates of period the student wants their grades from
    boost::posix_time::ptime start_date;
    boost::posix_time::ptime end_data;
};

struct student_report_response {
    std::vector<std::string> assignment_names;
    std::vector<boost::posix_time::ptime> due_dates;
    std::vector<bool> on_time;
    std::vector<std::string> durations_late;
    std::vector<boost::posix_time::ptime> submission_dates;
    std::vector<int> cases_passed;
    std::vector<int> total_cases;
};

#endif