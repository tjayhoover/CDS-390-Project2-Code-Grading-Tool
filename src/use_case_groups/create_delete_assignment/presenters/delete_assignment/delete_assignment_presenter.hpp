#ifndef DELETE_ASSIGNMENT_PRESENTER_HPP
#define DELETE_ASSIGNMENT_PRESENTER_HPP

#include "../../interactors/delete_assignment/presenter_interface.hpp"
#include "view_interface.hpp"
#include <memory>

class DeleteAssignmentPresenter: public DeleteAssignmentPresenterInterface {

public:
    void presentResult(delete_assignment_response) override;

    template <class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    std::unique_ptr<ViewInterface> view;
};

#endif