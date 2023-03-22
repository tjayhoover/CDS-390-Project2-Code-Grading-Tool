#ifndef INSTRUCTOR_REPORT_PRESENTER_HPP
#define INSTRUCTOR_REPORT_PRESENTER_HPP

#include "../../interactors/instructor/presenter_interface.hpp"
#include "view_interface.hpp"
#include <memory>

class InstructorReportPresenter: InstructorReportPresenterInterface {

public:
    void presentResult(instructor_report_response) override;

    template <class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    std::unique_ptr<ViewInterface> view;
};

#endif