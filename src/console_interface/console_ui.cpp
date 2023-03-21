#include "console_ui.hpp"

#include <string>
#include <iostream>

using namespace std;

ConsoleUserInterface::ConsoleUserInterface(LogInOutController lc, SubmissionController sc) 
    : log_in_out_controller(lc), submission_controller(sc) {}

void ConsoleUserInterface::run() {

    // Start the event loop

    while(true) {
        cout << "Welcome to Beetcode!" << endl;
        cout << main_menu << endl;
        string response;
        cin >> response;
        if(tolower(response[0]) == 'a') {
            log_in_out_controller.start_login_process();
        }
        else if(tolower(response[0] == 'b')) {
            break;
        }


    }
    cout << "Thanks for using Beetcode!" << endl;
}