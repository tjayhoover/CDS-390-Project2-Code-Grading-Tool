// Adam Rilatt
// 30 January 2023
// BeetCode -- Minimal Database Test

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "database.h"
#include "../User/user.h"
#include "../ClassAndContent/assignment.h"

using namespace std;

int main() {

  Database d;
  
  cout << "Created database." << endl;
  
  vector<User> users;
  
  users.emplace_back(PermissionLevel::Student, "AdamRilatt");
  users.emplace_back(PermissionLevel::Instructor, "RonDowey");
  users.emplace_back(PermissionLevel::Admin, "GrandmasterKenneth");
  
  cout << "Created user list." << endl;
  
  d.save_users(users);
  
  cout << "Saved users to their respective files." << endl;
  
  users.clear();
  
  vector<User> new_users = d.load_users();
  
  cout << "Loaded new users:" << endl;
  
  for (User& u : new_users)
    cout << u.get_username() << endl;
  cout << endl;
  
  vector<Assignment> assignments;
  
  assignments.emplace_back("Dobra", time(nullptr));
  assignments[0].set_description("God, I hated this problem.");
  assignments.emplace_back("Project 1", time(nullptr));
  assignments[1].set_description("Smooth jazz");
  
  cout << "Created assignment list." << endl;
  
  d.save_assignments(assignments);
  
  cout << "Saved assignments to their respective files." << endl;
  
  assignments.clear();
  
  vector<Assignment> new_assignments = d.load_assignments();
  
  cout << "Loaded new assignments:" << endl;
  
  for (Assignment& a : new_assignments)
    cout << a.get_name() << " with description " << a.get_description()
         << ", out of " << a.get_max_grade() << " points. " << endl;  

}
