// Brandon Bauer and Tyler Hoover
// 14 March 2023
// BeetCode -- AbstractDatabase Header

#ifndef ABSTRACT_DATABASE_H
#define ABSTRACT_DATABASE_H

#include <string>
#include <vector>

#include "User"
#include "Assignment"
#include "Submission"

class AbstractDatabase {
public:

  virtual ~AbstractDatabase() = default;

  virtual std::vector<Assignment> get_assignments() = 0;
  virtual std::vector<User> get_users() = 0;
  virtual std::vector<Submission> get_submissions() = 0;
  
  virtual void add_user(User& user) = 0;
  virtual void add_assignment(Assignment& assignment) = 0;
  virtual void add_submission(Submission& submission) = 0;

  virtual void del_user(User& user) = 0;
  virtual void del_assignment(Assignment& assignment) = 0;
  virtual void del_submission(Submission& submission) = 0;
  
};

#endif