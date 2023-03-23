#include "student_view_assignments.hpp"

StudentViewAssignmentsInteractor::StudentViewAssignmentsInteractor(AbstractDatabase* d, SAPresenterInterface* p) :
    storage(d), presenter(p) {}

void StudentViewAssignmentsInteractor::view_assignments(student_view_assignments_request request) {

    // Initialize the response object
    student_view_assignments_response response;

    // Get the list of assignments from the database
    auto assignments = storage->get_assignments();

    for(auto& assignment: assignments) {
        response.names.push_back(assignment.get_name());
        response.descriptions.push_back(assignment.get_description());
        response.due_dates.push_back(assignment.get_deadline());
    }

    // Hand the response to the presenter
    presenter->presentResult(response);
}