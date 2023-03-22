#ifndef CREATE_USER_VIEW_HPP
#define CREATE_USER_VIEW_HPP

#include "../../presenters/create_user/view_interface.hpp"

// This is the dirty dirty detail which cannot be tested.
// It moves the data from the presenter into the UI
// In this case it literally writes it to the command line
class CreateUserView: public ViewInterface {

public:

    CreateUserView() = default;
    void display(ViewModel data) override;
};

#endif