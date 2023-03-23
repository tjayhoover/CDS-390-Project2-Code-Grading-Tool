#ifndef STUDENT_ASSIGNMENTS_PRESENTER_HPP
#define STUDENT_ASSIGNMENTS_PRESENTER_HPP

#include "../../interactors/student/sa_presenter_interface.hpp"
#include "sa_view_interface.hpp"
#include "../../request_response_models/student_view_assignments_models.hpp"
#include <memory>

#include <iostream>

class StudentAssignmentsPresenter: public SAPresenterInterface {

public:
    void presentResult(student_view_assignments_response data) override;

    template<class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    std::unique_ptr<SAViewInterface> view;
};


#endif