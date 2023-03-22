#ifndef CREATE_ASSIGNMENT_PRESENTER_HPP
#define CREATE_ASSIGNMENT_PRESENTER_HPP

#include "../../interactors/create_assignment/presenter_interface.hpp"
#include "view_interface.hpp"
#include <memory>

class CreateAssignmentPresenter: CreateAssignmentPresenterInterface {

public:
    void presentResult(create_assignment_response) override;

    template <class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    ViewInterface* view;
};


#endif