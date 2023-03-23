#ifndef STUDENT_VIEW_ASSIGNMENTS_HPP
#define STUDENT_VIEW_ASSIGNMENTS_HPP

#include "abstract_database.hpp"
#include "sa_presenter_interface.hpp"
#include "../../request_response_models/student_view_assignments_models.hpp"

class StudentViewAssignmentsInteractor {

public:
    StudentViewAssignmentsInteractor(AbstractDatabase*, SAPresenterInterface*);

    void view_assignments(student_view_assignments_request);

private:
    AbstractDatabase* storage;
    SAPresenterInterface* presenter;
};

#endif