#ifndef SUBMISSION_VIEW_HPP
#define SUBMISSION_VIEW_HPP

#include "../presenters/view_interface.hpp"

// This is the dirty dirty detail which cannot be tested.
// It moves the data from the presenter into the UI
// In this case it literally writes it to the command line
class SubmissionView: public ViewInterface {

public:

    SubmissionView() = default;
    void display(ViewModel data) override;
};

#endif
