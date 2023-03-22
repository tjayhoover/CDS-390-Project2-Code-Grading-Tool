#ifndef STUDENT_REPORT_PRESENTER_HPP
#define STUDENT_REPORT_PRESENTER_HPP

#include "../../interactors/student/presenter_interface.hpp"
#include "view_interface.hpp"
#include <memory>

class StudentReportPresenter: StudentReportPresenterInterface {

public:
    void presentResult(student_report_response) override;

    template <class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    ViewInterface* view;
};

#endif
