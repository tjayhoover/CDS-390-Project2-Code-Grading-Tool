#include "console_ui.hpp"

#include <string>
#include <iostream>

using namespace std;

char ConsoleUserInterface::get_response() {
    char c;
    cin >> c;
    return c;
}

ConsoleUserInterface::ConsoleUserInterface(LogInOutController lc, SubmissionController sc) 
    : log_in_out_controller(lc), submission_controller(sc), user(PermissionLevel::Null, "") {}

void ConsoleUserInterface::run() {
    // Start the event loop
    while(true) {
        // If someone is logged in, do this
        if(logged_in) {
            if(user.get_permission() == PermissionLevel::Admin) {
                cout << admin_menu << endl;
                char response = get_response();
                if(response == 'a') {
                    cout << "You chose a!" << endl;
                }
                else if(response == 'b'){
                    cout << "You chose b!" << endl;
                }
                else if(response == 'c') {
                    cout << "You chose c!" << endl;
                }
                else if(response == 'd') {
                    break;
                }
            }
            else if(user.get_permission() == PermissionLevel::Instructor) {
                cout << instructor_menu << endl;
                char response = get_response();
                if(response == 'a') {
                    cout << "You chose a!" << endl;
                }
                else if(response == 'b'){
                    cout << "You chose b!" << endl;
                }
                else if(response == 'c') {
                    cout << "You chose c!" << endl;
                }
                else if(response == 'd') {
                    break;
                }
            }
            else if(user.get_permission() == PermissionLevel::Student) {
                cout << student_menu << endl;
                char response = get_response();
                if(response == 'a') {
                    cout << "You chose a!" << endl;
                }
                else if(response == 'b'){
                    cout << "You chose b!" << endl;
                }
                else if(response == 'c') {
                    cout << "You chose c!" << endl;
                }
                else if(response == 'd') {
                    break;
                }
            }
            else break;
        }

        // If nobody is logged in, do this
        else{
            cout << "Welcome to Beetcode!" << endl;
            cout << main_menu << endl;
            string response;
            cin >> response;
            if(tolower(response[0]) == 'a') {
                pair<bool, User> user_data = log_in_out_controller.start_login_process();
                user = user_data.second;
                logged_in = user_data.first;
            }
            else if(tolower(response[0] == 'b')) {
                break;
            }
        }
        
    }
    cout << "Thanks for using Beetcode!" << endl;
}