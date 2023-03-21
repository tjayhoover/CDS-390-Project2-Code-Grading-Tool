#ifndef CONSOLE_UI_HPP
#define CONSOLE_UI_HPP

#include "../entities/user/user.hpp"
#include "../log_in_out/controllers/log_in_out_controller.hpp"
#include "../submit_assignment/controllers/submission_controller.hpp"

#include <string>

class ConsoleUserInterface {
public:
    ConsoleUserInterface(LogInOutController, SubmissionController);

    char get_response();

    void run();

private:
    User user;
    bool logged_in = false;

    LogInOutController log_in_out_controller;
    SubmissionController submission_controller;

    const std::string main_menu = "(a) Log in\n(b) Quit";
    const std::string student_menu = "(a) View Grades\n(b) Submit Assignment\n(c) Log Out\n(d) Quit";
    const std::string instructor_menu = "(a) View Grade Report\n(b)Upload Assignment\n(c) Log Out\n(d) Quit";
    const std::string admin_menu = "(a) Add User\n(b) Delete User\n(c) Log Out\n(d) Quit";
};

#endif