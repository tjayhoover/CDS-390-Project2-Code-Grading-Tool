#ifndef CONSOLE_UI_HPP
#define CONSOLE_UI_HPP

// This should not be included
#include "../entities/user/user.hpp"

// Include the use case controllers (direct control flow dependency)
#include "../use_case_groups/log_in_out/controllers/log_in_out_controller.hpp"
#include "../use_case_groups/submit_assignment/controllers/submission_controller.hpp"
#include "../use_case_groups/create_delete_assignment/controllers/assignment_controller.hpp"
#include "../use_case_groups/create_delete_user/controllers/user_controller.hpp"
#include "../use_case_groups/grade_report/controllers/report_controller.hpp"
#include "../use_case_groups/view_assignments/controllers/view_assignments_controller.hpp"

// Include the input data structs
#include "../use_case_groups/log_in_out/controllers/input_request_models.hpp"
#include "../use_case_groups/submit_assignment/controllers/input_request_models.hpp"
#include "../use_case_groups/create_delete_assignment/controllers/input_request_models.hpp"
#include "../use_case_groups/create_delete_user/controllers/input_request_models.hpp"
#include "../use_case_groups/grade_report/controllers/input_request_models.hpp"
#include "../use_case_groups/view_assignments/controllers/input_request_models.hpp"

#include <string>

class ConsoleUserInterface {
public:
    ConsoleUserInterface(LogInOutController, SubmissionController, ReportController, UserController, AssignmentController, ViewAssignmentsController);
    
    char get_response();

    void log_out();

    void run();

private:
    // Session info
    User user;
    bool logged_in = false;

    // Use case controllers
    LogInOutController log_in_out_controller;
    SubmissionController submission_controller;
    ReportController report_controller;
    UserController user_controller;
    AssignmentController assignment_controller;
    ViewAssignmentsController view_assignments_controller;

    // Menu strings
    const std::string main_menu = "(a) Log in\n(b) Quit";
    const std::string student_menu = "(a) View Grades\n(b) View Assignments\n(c) Submit Assignment\n(d) Change Password\n(e) Log Out\n(f) Quit";
    const std::string instructor_menu = "(a) View Grade Report\n(b) Upload Assignment\n(c) Delete Assignment\n(d) Change Password\n(e) Log Out\n(f) Quit";
    const std::string admin_menu = "(a) Add User\n(b) Delete User\n(c) Change Password\n(d) Log Out\n(e) Quit";
};

#endif