// Brandon Bauer and Tyler Hoover
// 14 March 2023
// BeetCode -- AbstractDatabase Header

#ifndef ABSTRACT_DATABASE_H
#define ABSTRACT_DATABASE_H

#include <string>
#include <vector>

// Could add these include paths to cmake
#include "./entities/user/user.hpp"
#include "./entities/assignment/assignment.hpp"
#include "./entities/submission/submission.hpp"

class AbstractDatabase {
public:

  virtual ~AbstractDatabase() = default;

  // I don't think any use case will every need in memory lists of 
  // all assignments, submissions, and users. Thus, I think
  // we need to reimagine our interface 
  // Database logic should be done in a lower level; the use case
  // shouldn't have to sort through stuff 

  virtual std::vector<Assignment> get_assignments() = 0;
  virtual std::vector<User> get_users() = 0;
  virtual std::vector<Submission> get_submissions() = 0;


  // These, however, are required:

  // Should these return booleans indicating the success or
  // failure of the database operation?
  // - pro: The use case ought to be aware of whether it succeeded or not
  // - con: The use case doesn't need to worry about details like that
  // but that is actually a pretty big bleeping detail. IO operations can fail,
  // and that is relevant to the business logic
  virtual void add_user(User& user) = 0;
  virtual void add_assignment(Assignment& assignment) = 0;
  virtual void add_submission(Submission& submission) = 0;

  virtual void del_user(User& user) = 0;
  virtual void del_assignment(Assignment& assignment) = 0;
  virtual void del_submission(Submission& submission) = 0;
};

#endif