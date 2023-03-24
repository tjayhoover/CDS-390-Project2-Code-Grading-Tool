#ifndef GRADE_REPORT_INPUT_REQUEST_MODELS_HPP
#define GRADE_REPORT_INPUT_REQUEST_MODELS_HPP

#include <string>

struct instructor_report_input {
    std::string assignmentname;
};

struct student_report_input {
    std::string studentname;
};

#endif