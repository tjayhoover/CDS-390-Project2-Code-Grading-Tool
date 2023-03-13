// Adam Rilatt & Brandon Bauer
// 8 February 2023
// BeetCode -- Assignment Implementation

#include <stdlib.h>
#include <fstream>

#include "assignment.hpp"

Assignment::Assignment(const std::string& name, time_t deadline)
: name(name), deadline(deadline) { 

  description = "No description is available.";
  
}

Assignment::Assignment(const std::vector<std::string>& params) {
  
  name = params[0];
  description = params[1];
  deadline = std::stoll(params[2]); // time_t == long long
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
  data.push_back(std::to_string(deadline));
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

void Assignment::set_deadline(time_t new_deadline) {
  deadline = new_deadline;
}


std::string Assignment::get_name() {
  return name;
}

std::string Assignment::get_description() {
  return description;
}

time_t Assignment::get_deadline() {
  return deadline;
}

int Assignment::get_max_grade() {
  return max_grade;
}

int Assignment::grade_work(const Submission& submission){
  std::string program = submission.get_program();

  int correct_cases {0};

  for(auto& case : test_cases){
    std::string input  = case.first;
    std::string output = case.second;

    std::string command_1 = " cat " + input + " | python " + program + " >> ../DatabaseFiles/Grading/program_output.txt";
    std::string command_2 = "diff -q ../DatabaseFiles/Grading/program_output.txt " + output + " >> ../DatabaseFiles/Grading/results.txt";

    system(command_1.c_str());
    system(command_2.c_str());

    ifstream results {"../DatabaseFiles/Grading/results.txt"};
    if(results.peek() == std::ifstream::traits_type::eof();) ++correct_cases;

    system("rm ../DatabaseFiles/Grading/results.txt");
    system("rm ../DatabaseFiles/Grading/program_output.txt");
    }


    return correct_cases;
}

std::pair<std::string,Submission> Assignment::submit_work(const std::string& username, const std::string& program){
  Submission submission(username, program);
  submission.set_grade(grade_work(submission));
  std::string path = "../DatabaseFiles/Submissions/" + name + "_" + username + "_" + std::to_string(size(submissions));
  submissions.push_back(path);
  return {path,submission};
}

void Assignment::add_test_case(std::pair<std::string, std::string> test_case){
  test_cases.push_back(test_case);
  ++max_grade;
}