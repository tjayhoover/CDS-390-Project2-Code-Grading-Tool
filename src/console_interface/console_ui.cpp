#include "console_ui.hpp"

#include <string>
#include <iostream>

using namespace std;

void ConsoleUserInterface::log_out() {
    this->logged_in = false;
    this->user = User();
    cout << "You have successfully logged out." << endl;
}

// Get a one character response from the user
char ConsoleUserInterface::get_response() {
    string c;
    cin >> c;
    return tolower(c.front());
}

ConsoleUserInterface::ConsoleUserInterface(LogInOutController lc, SubmissionController sc, ReportController rc, UserController uc, AssignmentController ac)
    : log_in_out_controller(lc), submission_controller(sc), report_controller(rc), user_controller(uc), assignment_controller(ac), user(PermissionLevel::Null, "") 
    {}

void ConsoleUserInterface::run() {
    // Start the event loop
    while(true) {
        // If someone is logged in, do this
        if(logged_in) {
            if(user.get_permission() == PermissionLevel::Admin) {
                cout << admin_menu << endl;
                char response = get_response();

                // Add user option
                if(response == 'a') {
                    user_controller.create_user();
                }

                // Delete user option
                else if(response == 'b'){
                    cout << "You chose b!" << endl;
                }

                // Change password
                else if(response == 'c') {
                    user_controller.change_password(this->user.get_username());
                }

                // log out option
                else if(response == 'd') {
                    this->log_out();
                }

                // quit
                else if(response == 'e') {
                    break;
                }
            }
            else if(user.get_permission() == PermissionLevel::Instructor) {
                cout << instructor_menu << endl;
                char response = get_response();

                // View Grade Report option
                if(response == 'a') {
                    cout << "You chose a!" << endl;
                }

                // Upload Assignment option
                else if(response == 'b'){
                    assignment_controller.create_assignment();
                }

                // Change password
                else if(response == 'c') {
                    user_controller.change_password(this->user.get_username());
                }

                // Log out
                else if(response == 'd') {
                    this->log_out();
                }

                // Quit
                else if(response == 'e') {
                    break;
                }
            }
            else if(user.get_permission() == PermissionLevel::Student) {
                cout << student_menu << endl;
                char response = get_response();

                // View Grades option
                if(response == 'a') {
                    cout << "You chose a!" << endl;
                }

                // Submit assignment option
                else if(response == 'b'){
                    submission_controller.start_submission(this->user.get_username());
                }

                // Change password
                else if(response == 'c') {
                    user_controller.change_password(this->user.get_username());
                }

                // Log out option
                else if(response == 'd') {
                    this->log_out();
                }

                // Quit option
                else if(response == 'e') {
                    break;
                }
            }
            else break;
        }

        // If nobody is logged in, do this
        else {
            cout << "Welcome to Beetcode!" << endl;
            cout << main_menu << endl;
            char response = get_response();
            if(response == 'a') {
                pair<bool, User> user_data = log_in_out_controller.start_login_process();
                user = user_data.second;
                logged_in = user_data.first;
            }
            else if(tolower(response == 'b')) {
                break;
            }
        }
    }
    cout << "Thanks for using Beetcode!" << endl;
}