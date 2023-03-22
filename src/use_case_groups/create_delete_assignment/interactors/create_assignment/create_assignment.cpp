#include "create_assignment.hpp"

using namespace std;

CreateAssignmentInteractor::CreateAssignmentInteractor(AbstractDatabase* d, AbstractAuthenticator* a, CreateAssignmentPresenterInterface* p):
    storage(d), authenticator(a), presenter(p) {}

void CreateAssignmentInteractor::createAssignment(create_assignment_request data) {

    // Initialize response struct
    create_assignment_response response;

    // Create the assignment
    Assignment assignment(data.assignment_name, data.due_date);
    assignment.set_description(data.description);

    // Add test cases to the database
    for(int i = 0; i < data.input_files.size(); ++i) {
        string input_id = data.assignment_name + "input_case_" + to_string(i);
        string output_id = data.assignment_name + "output_case_" + to_string(i);
        assignment.add_test_case({input_id, output_id});
        storage->add_input_case(input_id, data.input_files[i]);
        storage->add_output_case(output_id, data.output_files[i]);
    }

    // Add assignment to the database
    storage->add_assignment(assignment);

    response.success = true;

    // Present the result
    presenter->presentResult(response);
}