#include "assignment_controller.hpp"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace std;

AssignmentController::AssignmentController(CreateAssignmentInteractor ci, DeleteAssignmentInteractor di) :
    create_assignment_interactor(ci), delete_assignment_interactor(di) {}


// Write validation for all the input data sometime
void AssignmentController::create_assignment() {

    // Initialize the request struct
    create_assignment_request request;

    cout << "Type the name of your assignment:" << endl;

    string assignment_name;
    getline(cin, assignment_name);

    cout << "Type the description of your assignment on one line:" << endl;

    string description;
    
    getline(cin, description);

    // Make sure this formatting works
    cout << "Type the due date of your assignment in this format: (YYYY-MM-DD hh:mm:ss)" << endl;

    string date_string;
    getline(cin, date_string);

    cout << "Type the absolute path to the folder containing the input files:" << endl;

    string input_files_path;
    getline(cin, input_files_path);

    cout << "Type the absolute path to the folder containing the output files:" << endl;

    string output_files_path;
    getline(cin, output_files_path);

    vector<string> input_strings;
    vector<string> output_strings;
    
    // Loop through input files directory and grab the input files as strings
    for(const auto& entry: std::filesystem::directory_iterator(input_files_path)) {
        if(entry.is_regular_file()) {
            fstream strm(entry.path());
            std::stringstream buffer;
            buffer << strm.rdbuf();
            input_strings.push_back(buffer.str());
        }
    }

    // Loop through the output files directory and grab the output files as strings
    for(const auto& entry: std::filesystem::directory_iterator(output_files_path)) {
        if(entry.is_regular_file()) {
            fstream strm(entry.path());
            std::stringstream buffer;
            buffer << strm.rdbuf();
            output_strings.push_back(buffer.str());
        }
    }

    // Put the data into the request model object
    request.assignment_name = assignment_name;
    request.description = description;
    request.due_date = boost::posix_time::time_from_string(date_string);
    request.input_files = input_strings;
    request.output_files = output_strings;

    create_assignment_interactor.createAssignment(request);
}

void AssignmentController::delete_assignment() {

    delete_assignment_request request;
    

    delete_assignment_interactor.deleteAssignment(request);
}