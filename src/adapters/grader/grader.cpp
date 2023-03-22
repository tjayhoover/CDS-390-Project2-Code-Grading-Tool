#include "grader.hpp"

Grader::Grader() {
    pythonGrader pg;
    this->pg = pg;
}

bool Grader::grade_code(std::string code, std::string input, std::string output) {
    return (this->pg).grade_code(code, input, output);
}