#ifndef CREATE_USER_PRESENTER_HPP
#define CREATE_USER_PRESENTER_HPP

#include "../../interactors/create_user/presenter_interface.hpp"
#include "view_interface.hpp"
#include <memory>

class CreateUserPresenter: CreateUserPresenterInterface {

public:
    void presentResult(create_user_response) override;

    template <class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    ViewInterface* view;
};

#endif