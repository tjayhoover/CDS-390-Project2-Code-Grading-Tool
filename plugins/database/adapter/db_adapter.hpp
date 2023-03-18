// Brandon Bauer
// 17 March 2023
// BeetCode -- Database plugin

#ifndef DB_ADAPTER_H
#define DB_ADAPTER_H

#include <string>
#include <vector>

#include "../database.hpp"

#include "../../../src/entities/user/user.hpp"
#include "../../../src/entities/assignment/assignment.hpp"
#include "../../../src/entities/submission/submission.hpp"

class DB_adapter {
    
  public:

  DB_adapter() = default;
  ~DB_adapter() = default;

  // Adds to database
  virtual std::string add_user(User& user) = 0;
  virtual std::string add_assignment(Assignment& assignment) = 0;
  virtual std::string add_submission(Submission& submission) = 0;

  // Removes from database
  virtual void del_user(const std::string& ID) = 0;
  virtual void del_assignment(const std::string& ID) = 0;
  virtual void del_submission(const std::string& ID) = 0;

  // Gets all from database
  virtual std::vector<Assignment> get_assignments() = 0;
  virtual std::vector<User> get_users() = 0;
  virtual std::vector<Submission> get_submissions() = 0;

  // Gets single based on ID
  virtual Assignment get_assignment(const std::string& ID) = 0;
  virtual User get_user(const std::string& ID) = 0;
  virtual Submission get_submission(const std::string& ID) = 0;

  private:

  // create y DB object and use it
  // "cache"
  // etc



};

#endif