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

ConsoleUserInterface::ConsoleUserInterface(LogInOutController lc, SubmissionController sc, ReportController rc, UserController uc, AssignmentController ac, ViewAssignmentsController vac)
    : log_in_out_controller(lc), submission_controller(sc), report_controller(rc), user_controller(uc), assignment_controller(ac), view_assignments_controller(vac), user(PermissionLevel::Null, "") 
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
                    cout << "Type the permission level of the new user (admin, instructor, or student):" << endl;
                    string permission_level;
                    cin >> permission_level;
                    
                    cout << "Type the username of the new user:" << endl;
                    string username;
                    cin >> username;

                    create_user_input input_data;
                    input_data.permission_level = permission_level;
                    input_data.username = username;

                    // Hand the input data to the controller
                    user_controller.create_user(input_data);
                }

                // Delete user option
                else if(response == 'b'){
                    cout << "Type the name of the user you want to delete:" << endl;
                    string username;
                    cin >> username;
                    delete_user_input input_data;
                    input_data.username = username;
                    user_controller.delete_user(input_data);
                }

                // Change password
                else if(response == 'c') {
                    cout << "Please type your new password: " << endl;
                    string new_password;
                    cin >> new_password;

                    cout << "Please type it again:" << endl;
                    string new_password_copy;
                    cin >> new_password_copy;

                    change_password_input input_data;

                    input_data.username = user.get_username();

                    if(new_password == new_password_copy) {
                        input_data.new_password = new_password;
                        // input_data.old_password = user.get_password();
                        // Hand off the request to the interactor
                        user_controller.change_password(input_data);
                    }
                    else cout << "The passwords did not match. Try again." << endl;
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

                    // Get the required data from the user
                    cout << "Type the name of the assignment you want a report for:" << endl;
                    string name;

                    // Hotfix I don't like
                    string newline;
                    getline(cin, newline);
                    getline(cin, name);

                    // Make an input data object
                    instructor_report_input input_data;

                    // Put the data in the object
                    input_data.assignmentname = name;

                    // Send data to controller
                    report_controller.get_instructor_report(input_data);
                }

                // Upload Assignment option
                else if(response == 'b'){
                    cout << "Type the name of your assignment:" << endl;

                    string assignment_name;

                    // bad hotfix
                    string newline;
                    getline(cin, newline);
                    getline(cin, assignment_name);

                    cout << "Type the description of your assignment on one line:" << endl;

                    string description;
                    
                    getline(cin, description);

                    // Make sure this formatting works
                    cout << "Type the due date of your assignment in this format: (YYYY-MM-DD hh:mm:ss.sss)" << endl;

                    string date_string;
                    getline(cin, date_string);

                    cout << "Type the absolute path to the folder containing the input files:" << endl;

                    string input_files_path;
                    getline(cin, input_files_path);

                    cout << "Type the absolute path to the folder containing the output files:" << endl;

                    string output_files_path;
                    getline(cin, output_files_path);

                    // Create the input data struct and fill out out
                    create_assignment_input input_data;
                    input_data.name = assignment_name;
                    input_data.description = description;
                    input_data.due_date = date_string;
                    input_data.input_files_path = input_files_path;
                    input_data.output_files_path = output_files_path;

                    // Hand the data to the controller
                    assignment_controller.create_assignment(input_data);
                }

                // Delete Assignment option
                else if(response == 'c') {
                    cout << "Type the name of the assignment you want to delete:" << endl;
                    string name;

                    // Hot fix that I don't like
                    string newline;
                    getline(cin, newline);
                    getline(cin, name);

                    // Create and fill out the input_data model
                    delete_assignment_input input_data;
                    input_data.assignment_name = name;

                    // Hand the data to the controller
                    assignment_controller.delete_assignment(input_data);
                }

                // Change password
                else if(response == 'd') {
                    cout << "Please type your new password: " << endl;
                    string new_password;
                    cin >> new_password;

                    cout << "Please type it again:" << endl;
                    string new_password_copy;
                    cin >> new_password_copy;

                    change_password_input input_data;

                    input_data.username = user.get_username();

                    if(new_password == new_password_copy) {
                        input_data.new_password = new_password;
                        // input_data.old_password = user.get_password();
                        // Hand off the request to the interactor
                        user_controller.change_password(input_data);
                    }
                    else cout << "The passwords did not match. Try again." << endl;
                }

                // Log out
                else if(response == 'e') {
                    this->log_out();
                }

                // Quit
                else if(response == 'f') {
                    break;
                }
            }
            else if(user.get_permission() == PermissionLevel::Student) {
                cout << student_menu << endl;
                char response = get_response();

                // View Grades option
                if(response == 'a') {
                    student_report_input input_data;
                    input_data.studentname = user.get_username();
                    report_controller.get_student_report(input_data);
                }

                // View Assignments option
                else if(response == 'b') {
                    student_view_assignments_input input_data;
                    view_assignments_controller.student_view_assignments(input_data);
                }

                // Submit assignment option
                else if(response == 'c'){
                    // Request assignment name from the user
                    cout << "Enter the name of the assignment" << endl;
                    string assignment_name;

                    // Recieve name
                    cin >> assignment_name;

                    // Prompt for path
                    cout << "Enter the full path of the file containing your code:" << endl;
                    string path;

                    // Receive the data
                    cin >> path;

                    submit_assignment_input input_data;
                    input_data.assignment_name = assignment_name;
                    input_data.code_path = path;
                    input_data.username = user.get_username();

                    submission_controller.start_submission(input_data);
                }

                // Change password
                else if(response == 'd') {
                    cout << "Please type your new password: " << endl;
                    string new_password;
                    cin >> new_password;

                    cout << "Please type it again:" << endl;
                    string new_password_copy;
                    cin >> new_password_copy;

                    change_password_input input_data;

                    input_data.username = user.get_username();

                    if(new_password == new_password_copy) {
                        input_data.new_password = new_password;
                        // input_data.old_password = user.get_password();
                        // Hand off the request to the interactor
                        user_controller.change_password(input_data);
                    }
                    else cout << "The passwords did not match. Try again." << endl;
                }

                // Log out option
                else if(response == 'e') {
                    this->log_out();
                }

                // Quit option
                else if(response == 'f') {
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

                // Get input from user
                cout << "Please type in your username:" << endl;
                string username;
                cin >> username;
                cout << "Please type in your password:" << endl;
                string password;
                cin >> password;

                // Initialize the input data struct to hand to controller
                log_in_input input_data;
                input_data.username = username;
                input_data.password = password;

                // Ask the controller to start the login use case
                pair<bool, User> user_data = log_in_out_controller.start_login_process(input_data);

                // Set the session tokens
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