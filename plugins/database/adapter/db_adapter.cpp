// Brandon Bauer
// 17/3/2023
// 

#include <string>
#include <vector>

#include "../../../src/entities/user/user.hpp"
#include "../../../src/entities/assignment/assignment.hpp"
#include "../../../src/entities/submission/submission.hpp"


///////////// Might use these with modifications ////////////////

void DB_adapter::delete_user(const std::string& username) {

  string home = DATABASE_HOME + "Users/";
  delete_data(home + username);

}

void DB_adapter::delete_assignment(const std::string& assignment) {

  string home = DATABASE_HOME + "Assignments/";
  delete_data(home + assignment);

}

vector<Assignment> DB_adapter::load_assignments() {
  
  vector<Assignment> assignments;
  
  string home = DATABASE_HOME + "Assignments/";
  
  for (const auto& entry : std::filesystem::directory_iterator(home)) {
    
    string filename = entry.path().filename().string();
    vector<string> assignment_params = read(home + filename);
    assignments.emplace_back(assignment_params);
  
  }
  
  return assignments;
  
}

vector<User> DB_adapter::load_users() {
  
  vector<User> users;
  
  string home = DATABASE_HOME + "Users/";
  
  for (const auto& entry : std::filesystem::directory_iterator(home)) {
    
    string filename = entry.path().filename().string();
    vector<string> user_params = read(home + filename);
    users.emplace_back(user_params);
    
  }
  
  return users;
  
}

void DB_adapter::save_assignments(vector<Assignment>& assignments) {
  
  string home = DATABASE_HOME + "Assignments/";
  
  for (Assignment& a : assignments) {
    
    write(home + a.get_name(), a.save());
    
  }
  
}

void DB_adapter::save_users(vector<User>& user_list) {
  
  string home = DATABASE_HOME + "Users/";
  
  for (User& u: user_list) {
    
    write(home + u.get_username(), u.save());
    
  }
  
}