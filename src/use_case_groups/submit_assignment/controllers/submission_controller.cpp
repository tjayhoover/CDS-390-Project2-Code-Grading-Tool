#include "submission_controller.hpp"
#include "../request_response_models/submission_models.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

// This is the controller. It takes the input, assembles it into a nice
// package for the use case (interactor) and hands it over, along with control.

SubmissionController::SubmissionController(SubmissionInteractor s) :
    submission_interactor(s) {}

void SubmissionController::start_submission(string student_name) {
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

    string source_code = "";

    if(filesystem::exists(path)) {
        // Read the source code into a string
        ifstream src(path);
        stringstream buffer;
        buffer << src.rdbuf();
        source_code = buffer.str();
        src.close();
    }
    else {
        cout << "Your file path was invalid." << endl;
        return;
    }

    // Assemble the data in a format the interactor can use, agnostic of any UI details
    submission_request data;
    data.assignment_name = assignment_name;
    data.program = source_code;
    data.student_name = student_name;
    data.submission_time = boost::posix_time::second_clock::local_time();

    // Give the data to the interactor (use case)
    submission_interactor.submit_assignment(data);
}