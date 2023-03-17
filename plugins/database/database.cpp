// Adam Rilatt
// 30 January 2023
// BeetCode -- Database Implementation

#include <stdexcept>
#include <fstream>
#include <filesystem> // for remove(); C++17 required
#include <iostream>

#include "database.h"

using std::string;
using std::vector;

vector<string> Database::read(const string& location) { 
  
  std::ifstream ifs(location);
  
  if (!ifs.is_open())
    throw std::runtime_error("Database file not found.");
  
  vector<string> data;
  string temp;
  while (std::getline(ifs, temp))
    data.push_back(temp);
  
  ifs.close();
  
  return data;
  
}

void Database::delete_data(const string& location) {
  
  if (std::filesystem::remove(location))
    return;
  
  else
    throw std::runtime_error("Database file not found and could not be deleted.");
  
}

void Database::delete_user(const std::string& username) {

  string home = DATABASE_HOME + "Users/";
  delete_data(home + username);

}

void Database::delete_assignment(const std::string& assignment) {

  string home = DATABASE_HOME + "Assignments/";
  delete_data(home + assignment);

}

void Database::write(const string& location, const vector<string>& data) {
  
  std::ofstream ofs(location);
  
  for (const string& line : data)
    ofs << line << std::endl;
  
}

vector<Assignment> Database::load_assignments() {
  
  vector<Assignment> assignments;
  
  string home = DATABASE_HOME + "Assignments/";
  
  for (const auto& entry : std::filesystem::directory_iterator(home)) {
    
    string filename = entry.path().filename().string();
    vector<string> assignment_params = read(home + filename);
    assignments.emplace_back(assignment_params);
  
  }
  
  return assignments;
  
}

vector<User> Database::load_users() {
  
  vector<User> users;
  
  string home = DATABASE_HOME + "Users/";
  
  for (const auto& entry : std::filesystem::directory_iterator(home)) {
    
    string filename = entry.path().filename().string();
    vector<string> user_params = read(home + filename);
    users.emplace_back(user_params);
    
  }
  
  return users;
  
}

void Database::save_assignments(vector<Assignment>& assignments) {
  
  string home = DATABASE_HOME + "Assignments/";
  
  for (Assignment& a : assignments) {
    
    write(home + a.get_name(), a.save());
    
  }
  
}

void Database::save_users(vector<User>& user_list) {
  
  string home = DATABASE_HOME + "Users/";
  
  for (User& u: user_list) {
    
    write(home + u.get_username(), u.save());
    
  }
  
}
