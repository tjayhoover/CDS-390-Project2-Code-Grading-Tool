#include "grader.hpp"

grader::grade_code(pythonGrader pg) {
    this.pg = pg;
}

bool grader::grade_code(std::string code, std::string input, std::string output) {
    return pg.grade_code(std::string code, std::string input, std::string output);
}