#ifndef INSTRUCTOR_REPORT_VIEW_HPP
#define INSTRUCTOR_REPORT_VIEW_HPP

#include "../../presenters/instructor/view_interface.hpp"

// This is the dirty dirty detail which cannot be tested.
// It moves the data from the presenter into the UI
// In this case it literally writes it to the command line
class InstructorReportView: public ViewInterface {

public:

    InstructorReportView() = default;
    void display(ViewModel data) override;
};

#endif