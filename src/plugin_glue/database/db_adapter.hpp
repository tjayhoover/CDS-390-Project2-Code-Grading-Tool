// Brandon Bauer
// 17 March 2023
// BeetCode -- Database plugin

#ifndef DB_ADAPTER_H
#define DB_ADAPTER_H

#include <string>
#include <vector>

//#include "../database.hpp"

#include "../../../src/entities/user/user.hpp"
#include "../../../src/entities/assignment/assignment.hpp"
#include "../../../src/entities/submission/submission.hpp"

class DB_adapter {
    
  public:

  DB_adapter() = default;
  ~DB_adapter() = default;

  // Adds to database
  std::string add_user(User& user);
  std::string add_assignment(Assignment& assignment);
  std::string add_submission(Submission& submission);

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

  private:

  // create y DB object and use it
  // "cache"
  // etc



};

#endif