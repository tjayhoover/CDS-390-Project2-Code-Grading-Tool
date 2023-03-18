#ifndef DTABASE_HPP
#define DTABASE_HPP

#include "abstract_database.hpp"
#include <string>
#include <vector>

#include <iostream>

class Database: public AbstractDatabase {

public:

  Database();

  //~Database() {}

  std::vector<Assignment> get_assignments() override;
  std::vector<User> get_users() override;
  std::vector<Submission> get_submissions() override;

  Assignment get_assignment(std::string name) override;
  User get_user(std::string username) override;
  
  void add_user(User& user) override;
  void add_assignment(Assignment& assignment) override;
  void add_submission(Submission& submission) override;

  void del_user(User& user) override;
  void del_assignment(Assignment& assignment) override;
  void del_submission(Submission& submission) override;
};

#endif