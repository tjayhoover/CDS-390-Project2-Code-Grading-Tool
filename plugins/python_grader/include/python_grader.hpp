#ifndef PYTHON_GRADER_HPP
#define PYTHON_GRADER_HPP

#include <string>

class pythonGrader {

public:
    // Constructor
    pythonGrader() = default;

    // Code grading function
    bool grade_code(std::string code, std::string input, std::string output);
};

#endif