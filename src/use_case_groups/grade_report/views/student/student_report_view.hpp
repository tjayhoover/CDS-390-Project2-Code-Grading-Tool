#ifndef STUDENT_REPORT_VIEW_HPP
#define STUDENT_REPORT_VIEW_HPP

#include "../../presenters/student/view_interface.hpp"

// This is the dirty dirty detail which cannot be tested.
// It moves the data from the presenter into the UI
// In this case it literally writes it to the command line
class StudentReportView: public ViewInterface {

public:

    StudentReportView() = default;
    void display(ViewModel data) override;
};

#endif