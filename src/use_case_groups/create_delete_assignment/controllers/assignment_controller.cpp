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
void AssignmentController::create_assignment(create_assignment_input input_data) {

    // Initialize the request struct
    create_assignment_request request;

    vector<string> input_strings;
    vector<string> output_strings;
    
    // Loop through input files directory and grab the input files as strings
    for(const auto& entry: std::filesystem::directory_iterator(input_data.input_files_path)) {
        if(entry.is_regular_file()) {
            fstream strm(entry.path());
            std::stringstream buffer;
            buffer << strm.rdbuf();
            input_strings.push_back(buffer.str());
        }
    }

    // Loop through the output files directory and grab the output files as strings
    for(const auto& entry: std::filesystem::directory_iterator(input_data.output_files_path)) {
        if(entry.is_regular_file()) {
            fstream strm(entry.path());
            std::stringstream buffer;
            buffer << strm.rdbuf();
            output_strings.push_back(buffer.str());
        }
    }

    // Put the data into the request model object
    request.assignment_name = input_data.name;
    request.description = input_data.description;
    request.due_date = boost::posix_time::time_from_string(input_data.due_date);
    request.input_files = input_strings;
    request.output_files = output_strings;

    create_assignment_interactor.createAssignment(request);
}

void AssignmentController::delete_assignment(delete_assignment_input input_data) {
    delete_assignment_request request;
    request.assignment_name = input_data.assignment_name;
    delete_assignment_interactor.deleteAssignment(request);
}