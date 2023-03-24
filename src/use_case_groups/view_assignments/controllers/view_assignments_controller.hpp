#ifndef VIEW_ASSIGNMENTS_CONTROLLER_HPP
#define VIEW_ASSIGNMENTS_CONTROLLER_HPP

#include "../interactors/student/student_view_assignments.hpp"
#include "input_request_models.hpp"

class ViewAssignmentsController {

public:
    ViewAssignmentsController(StudentViewAssignmentsInteractor);

    void student_view_assignments(student_view_assignments_input);
    //void instructor_view_assignments();

private:
    StudentViewAssignmentsInteractor student_view_assignments_interactor;
    //InstructorViewAssignmentsInteractor instructor_view_assignments_interactor;
};

#endif