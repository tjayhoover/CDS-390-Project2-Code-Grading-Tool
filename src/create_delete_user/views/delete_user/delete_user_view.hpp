#ifndef DELETE_USER_VIEW_HPP
#define DELETE_USER_VIEW_HPP

#include "../../presenters/delete_user/view_interface.hpp"

// This is the dirty dirty detail which cannot be tested.
// It moves the data from the presenter into the UI
// In this case it literally writes it to the command line
class DeleteUserView: public ViewInterface {

public:

    DeleteUserView() = default;
    void display(ViewModel data) override;
};


#endif