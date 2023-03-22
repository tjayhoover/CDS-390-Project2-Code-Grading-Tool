#ifndef LOGOUT_VIEW_HPP
#define LOGOUT_VIEW_HPP

#include "../../presenters/log_out/view_interface.hpp"

// This is the dirty dirty detail which cannot be tested.
// It moves the data from the presenter into the UI
// In this case it literally writes it to the command line
class LogoutView: public ViewInterface {

public:

    LogoutView() = default;
    void display(ViewModel data) override;
};

#endif
