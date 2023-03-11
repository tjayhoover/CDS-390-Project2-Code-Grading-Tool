// Adam Rilatt
// 6 February 2023
// BeetCode -- Submission Implementation

#include "submission.h"

Submission::Submission(const std::string& name, const std::string& program)
: student_name(name), program(program) {
  
  std::chrono::system_clock::time_point time_p = std::chrono::system_clock::now();
  submission_time = std::chrono::system_clock::to_time_t(time_p);
  
}

Submission::Submission(const std::vector<std::string>& params) {
  
  student_name = params[1];
  program = params[2];
  grade = std::stoi(params[3]);
  submission_time = std::stoll(params[4]);
  
}

std::vector<std::string> Submission::save() {
  
  std::vector<std::string> data;
  
  data.push_back(student_name);
  data.push_back(program);
  data.push_back(std::to_string(grade));
  data.push_back(std::to_string(submission_time));
  
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

time_t Submission::get_submission_time() {
  return submission_time;
}
