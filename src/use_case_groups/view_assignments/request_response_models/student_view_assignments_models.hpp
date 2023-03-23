#ifndef STUDENT_VIEW_ASSIGNMENTS_MODELS_HPP
#define STUDENT_VIEW_ASSIGNMENTS_MODELS_HPP

#include <string>
#include <vector>
#include <boost/date_time/posix_time/posix_time.hpp>

struct student_view_assignments_request {

    // Name of student requesting assignments
    std::string username;

    // Get only assignments from after this date
    boost::posix_time::ptime start_date;

    // Get only assignments from before this date
    boost::posix_time::ptime end_date;
};

struct student_view_assignments_response {
    
    // List of assignment name/description pairs
    std::vector<std::string> names;
    std::vector<std::string> descriptions;
    std::vector<boost::posix_time::ptime> due_dates;
};


#endif
