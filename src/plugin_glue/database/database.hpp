#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "abstract_database.hpp"
#include <string>
#include <vector>

class database: public abstract_database {

public:
  std::vector<Assignment> get_assignments();
  std::vector<User> get_users();
  std::vector<Submission> get_submissions();
  
  void add_user(User& user);
  void add_assignment(Assignment& assignment);
  void add_submission(Submission& submission);

  void del_user(User& user);
  void del_assignment(Assignment& assignment);
  void del_submission(Submission& submission);
};

#endif
