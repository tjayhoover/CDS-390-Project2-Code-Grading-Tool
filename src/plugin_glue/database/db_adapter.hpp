// Brandon Bauer
// 17 March 2023
// BeetCode -- Database plugin

#ifndef DB_ADAPTER_H
#define DB_ADAPTER_H

#include <string>
#include <vector>
#include <unordered_map>

#include "database.hpp"

#include "abstract_database.hpp"

#include "../../../src/entities/user/user.hpp"
#include "../../../src/entities/assignment/assignment.hpp"
#include "../../../src/entities/submission/submission.hpp"

class DB_adapter : public AbstractDatabase {
    
  public:

  DB_adapter(bauer_DB* db);
  ~DB_adapter();

  // Adds to database
  void add_user(User user);
  void add_assignment(Assignment assignment);
  void add_submission(Submission submission);

  // Removes from database
  void del_user(const std::string& ID);
  void del_assignment(const std::string& ID);
  void del_submission(const std::string& ID);

  // Gets all from database
  std::vector<Assignment> get_assignments();
  std::vector<User> get_users();
  std::vector<Submission> get_submissions();

  // Gets single based on ID
  Assignment get_assignment(const std::string& ID);
  User get_user(const std::string& ID);
  Submission get_submission(const std::string& ID);

  // Gets all names for from database
  std::vector<std::string> get_assignment_names();
  std::vector<std::string> get_user_names();
  std::vector<std::string> get_submission_names();

  private:

  bauer_DB db;
  
  // user.get_username()
  // assignment.get_name()
  // submission.get_sub_name()
  std::unordered_map<std:: string,Assignment> assignments;
  std::unordered_map<std:: string,User> users;
  std::unordered_map<std:: string,Submission> submissions;

};

#endif