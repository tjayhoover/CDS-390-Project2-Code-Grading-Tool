#ifndef CREATE_ASSIGNMENT_VIEW_HPP
#define CREATE_ASSIGNMENT_VIEW_HPP

#include "../../presenters/create_assignment/view_interface.hpp"

// This is the dirty dirty detail which cannot be tested.
// It moves the data from the presenter into the UI
// In this case it literally writes it to the command line
class CreateAssignmentView: public ViewInterface {

public:

    CreateAssignmentView() = default;
    void display(ViewModel data) override;
};

#endif