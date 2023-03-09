#ifndef GRADER_HPP
#define GRADER_HPP

#include "abstract_grader.hpp"
#include <string>

class pythonGrader: public grader::grader {

public:
    // Constructor
    pythonGrader();

    // Code grading function
    bool grade_code(std::string code, std::string input, std::string output) override;
};

#endif