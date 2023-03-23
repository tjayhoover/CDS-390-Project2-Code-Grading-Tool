// Adam Rilatt & Brandon Bauer
// 8 February 2023
// BeetCode -- Assignment Implementation

#include <stdlib.h>
#include <fstream>

#include "boost/date_time/posix_time/posix_time.hpp"
// https://www.boost.org/doc/libs/1_81_0/doc/html/date_time/posix_time.html#date_time.posix_time.ptime_class


#include "assignment.hpp"

Assignment::Assignment(const std::string& name, boost::posix_time::ptime deadline)
: name(name), deadline(deadline) { 

  description = "No description is available.";
  
}

Assignment::Assignment(const std::vector<std::string>& params) {
  
  name = params[0];
  description = params[1];
  deadline = boost::posix_time::time_from_string(params[2]);
  max_grade = std::stoi(params[3]);
  
  int n_submissions = std::stoi(params[4]);
  for (int i = 5; i < n_submissions + 5; ++i)
    submissions.push_back(params[i]);
  
  for (int i = n_submissions + 5; i < params.size(); ++i) {
    
    std::pair<std::string, std::string> temp;
    
    size_t separator_idx = params[i].find(",");
    
    temp.first  = params[i].substr(0, separator_idx);
    temp.second = params[i].substr(separator_idx + 1);
    
    test_cases.push_back(temp);
    
  }
  
}

std::vector<std::string> Assignment::save() {
  
  std::vector<std::string> data;
  data.push_back(name);
  data.push_back(description);
  data.push_back(boost::posix_time::to_simple_string(deadline));
  data.push_back(std::to_string(max_grade));
  
  // We have to store a list of submissions and a list of test cases. How
  // do we know where one begins and the other ends? The submission list
  // comes first, starting with an integer specifying the number of submissions
  // to follow. Everything after that will be test cases, where each line
  // contains an input file path and an output file path separated by a comma.
  data.push_back(std::to_string(submissions.size())); 
  for (std::string& s : submissions)
    data.push_back(s);
  
  for (std::pair<std::string, std::string>& p : test_cases)
    data.push_back(p.first + "," + p.second);
  
  return data;
  
}

void Assignment::set_name(const std::string& new_name) {
  name = new_name;
}

void Assignment::set_description(const std::string& new_description) {
  description = new_description;
}

void Assignment::set_deadline(boost::posix_time::ptime new_deadline) {
  deadline = new_deadline;
}

std::vector<std::string> Assignment::get_submissions() {
  return submissions;
}

std::string Assignment::get_name() {
  return name;
}

std::string Assignment::get_description() {
  return description;
}

boost::posix_time::ptime Assignment::get_deadline() {
  return deadline;
}

int Assignment::get_max_grade(){
  return max_grade;
}

void Assignment::add_submission(const std::string& sub_name){
  submissions.push_back(sub_name);
}

void Assignment::add_test_case(std::pair<std::string, std::string> test_case){
  test_cases.push_back(test_case);
  ++max_grade;
}

int Assignment::get_num_submissions() {
  return submissions.size();
}

std::vector<std::pair<std::string, std::string>> Assignment::get_test_cases() {
  return test_cases;
}