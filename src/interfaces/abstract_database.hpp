// Brandon Bauer and Tyler Hoover
// 14 March 2023
// BeetCode -- AbstractDatabase Header

#ifndef ABSTRACT_DATABASE_H
#define ABSTRACT_DATABASE_H

#include <string>
#include <vector>

// Could add these include paths to cmake
#include "../entities/user/user.hpp"
#include "../entities/assignment/assignment.hpp"
#include "../entities/submission/submission.hpp"

class AbstractDatabase {
public:

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

    // Gets all names for from database
  virtual std::vector<std::string> get_assignment_names() = 0;
  virtual std::vector<std::string> get_user_names() = 0 ;
  virtual std::vector<std::string> get_submission_names() = 0;

};

#endif