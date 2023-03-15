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

  // I don't think any use case will every need in memory lists of 
  // all assignments, submissions, and users.
  // Database logic should be done in a lower level; the use case
  // shouldn't have to sort through stuff 

  // I propose adding these:
  // virtual Assignment get_assignment(some kind of ID. Either name or ID number) = 0;
  // Virtual User get_user(some kind of ID. Either name or ID number) = 0;
  // Virtual Submission get_submission(some kind of ID. Either name or ID number) = 0;

  virtual std::vector<Assignment> get_assignments() = 0;
  virtual std::vector<User> get_users() = 0;
  virtual std::vector<Submission> get_submissions() = 0;


  // These, however, are required:

  virtual void add_user(User& user) = 0;
  virtual void add_assignment(Assignment& assignment) = 0;
  virtual void add_submission(Submission& submission) = 0;

  virtual void del_user(User& user) = 0;
  virtual void del_assignment(Assignment& assignment) = 0;
  virtual void del_submission(Submission& submission) = 0;
};

#endif