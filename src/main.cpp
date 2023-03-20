#include <iostream>
#include <string>

// Is this what will happen?
#include "plugin_glue/grader/grader.hpp"
#include "plugin_glue/database/database.hpp"
#include "plugin_glue/authenticator/authenticator.hpp"

#include "submit_assignment/interactors/submit_assignment.hpp"
#include "submit_assignment/views/view.hpp"
#include "submit_assignment/request_response_models/submission_models.hpp"
#include "submit_assignment/controllers/submission_controller.hpp"
#include "submit_assignment/presenters/submission_presenter.hpp"

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace std;

int main(int, char**) {

    // Initialize the dependencies
    Grader* g = new Grader();
    Database* db = new Database();
    Authenticator* auth = new Authenticator();

    // Initialize the use cases
    View* view = new View();
    Presenter* p = new Presenter(view);
    SubmissionUseCase* sb = new SubmissionUseCase(db, g, p);

    cout << "Welcome to Beetcode." << endl;
    // Start the submission use case
    start_submission(sb);

    cout << "Exiting Program" << endl;
    
    // while(true) {
    //     cout << "Welcome to Beetcode." << endl;

    //     cout << "Would you like to log in? (Y/N)" << endl;
    //     string response;
    //     cin >> response;

    //     if(tolower(response[0]) == 'y') {
    //         // start the login use case
    //     }
    //     else {
    //         cout << "Exiting Program" << endl;
    //         // Delete everything
    //         break;
    //     }


        // cout << "Type in your username: " << endl;
        // string username;
        // cin >> username;
        // cout << "Type in your password: " << endl;
        // string password;
        // cin >> password;
        // log_in_controller.log_in()
        
        // Log in

        // Depending on user, do other stuff
    //}
}