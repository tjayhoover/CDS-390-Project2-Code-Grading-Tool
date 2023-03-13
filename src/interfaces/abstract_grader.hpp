#ifndef ABSTRACT_GRADER_HPP
#define ABSTRACT_GRADER_HPP

#include <string>
class AbstractGrader {

public:

    // Runs the code contained in the "code" string using the input from the "input" string.
    // If the program output matches the text in the "output" string, it returns "true."
    // In any other case, it will return "false."
    virtual bool grade_code(std::string code, std::string input, std::string output) = 0;
};


#endif