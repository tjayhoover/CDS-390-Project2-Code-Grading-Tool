#include "submission_controller.hpp"
#include "../request_response_models/submission_models.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// This is the controller. It takes the input, assembles it into a nice
// package for the use case (interactor) and hands it over, along with control.

void SubmissionController::start_submission(SubmissionUseCase* suc) {
    // Request data from the user
    cout << "Enter the full path of the file containing your code:" << endl;
    string path;

    // Receive the data
    cin >> path;

    // Read the source code into a string
    // ifstream src(path);
    // stringstream buffer;
    // buffer << src.rdbuf();
    // string source_code = buffer.str();
    // src.close();

    // Assemble the data in a format the interactor can use, agnostic of any UI details
    incoming_submission data;
    data.assignment_name = "Name";
    data.program = "python code";
    data.student_name = "Student Name";
    data.submission_time = boost::posix_time::second_clock::local_time();

    // Give the data to the interactor (use case):
    // This should be the final act of the controller, right?
    // Passing control to the interactor (Use Case)?
    suc->submit_assignment(data);
}