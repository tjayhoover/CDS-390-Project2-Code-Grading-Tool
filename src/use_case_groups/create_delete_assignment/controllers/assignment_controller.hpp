#ifndef ASSIGNMENT_CONTROLLER_HPP
#define ASSIGNMENT_CONTROLLER_HPP

#include "../interactors/create_assignment/create_assignment.hpp"
#include "../interactors/delete_assignment/delete_assignment.hpp"

class AssignmentController {
public:
    AssignmentController(CreateAssignmentInteractor, DeleteAssignmentInteractor);

    void create_assignment();
    void delete_assignment();

private:
    CreateAssignmentInteractor create_assignment_interactor;
    DeleteAssignmentInteractor delete_assignment_interactor;
};

#endif
