// Adam Rilatt
// 6 February 2023
// BeetCode -- Submission Implementation

#include "submission.hpp"

Submission::Submission(const std::string& student_name, const std::string& program, boost::posix_time::ptime time)
: student_name(student_name), program(program), submission_time(time) {}

Submission::Submission(const std::vector<std::string>& params) {
  
  student_name = params[1];
  program = params[2];
  grade = std::stoi(params[3]);
  submission_time = boost::posix_time::time_from_string(params[4]);  
}

std::vector<std::string> Submission::save() {
  
  std::vector<std::string> data;
  
  data.push_back(student_name);
  data.push_back(program);
  data.push_back(std::to_string(grade));
  data.push_back(boost::posix_time::to_simple_string(submission_time));
  
  return data;
  
}

void Submission::set_grade(int new_grade) {
  
  grade = new_grade;
  
}

std::string Submission::get_name() {
  return student_name;
}

std::string Submission::get_program() {
  return program;
}

int Submission::get_grade() {
  return grade;
}

boost::posix_time::ptime Submission::get_submission_time() {
  return submission_time;
}
