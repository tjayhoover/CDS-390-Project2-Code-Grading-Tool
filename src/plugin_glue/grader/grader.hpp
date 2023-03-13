#ifndef GRADER_HPP
#define GRADER_HPP

#include "abstract_grader.hpp"
#include "python_grader.hpp"
#include <string>

class Grader: public AbstractGrader {

public:
    Grader();
    bool grade_code(std::string code, std::string input, std::string output) override;
private:
    pythonGrader pg;
};


#endif