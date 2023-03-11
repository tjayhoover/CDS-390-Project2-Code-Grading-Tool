#ifndef GRADER_HPP
#define GRADER_HPP

#include <string>

class pythonGrader {

public:
    // Constructor
    pythonGrader();

    // Code grading function
    bool grade_code(std::string code, std::string input, std::string output);
};

#endif