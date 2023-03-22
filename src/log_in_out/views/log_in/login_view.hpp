#ifndef LOGIN_VIEW_HPP
#define LOGIN_VIEW_HPP

#include "../../presenters/log_in/view_interface.hpp"

// This is the dirty dirty detail which cannot be tested.
// It moves the data from the presenter into the UI
// In this case it literally writes it to the command line
class LoginView: public ViewInterface {

public:

    LoginView() = default;
    void display(ViewModel data) override;
};

#endif
