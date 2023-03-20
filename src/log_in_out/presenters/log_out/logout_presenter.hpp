#ifndef LOGOUT_PRESENTER_HPP
#define LOGOUT_PRESENTER_HPP

#include "../interactors/log_out/presenter_interface.hpp"
#include "view_interface.hpp"
#include "../../request_response_models/logout_models.hpp"
#include <memory>

#include <iostream>

class LogOutPresenter: public PresenterInterface {

public:
    void presentResult(logout_response data) override;

    template<class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    std::unique_ptr<ViewInterface> view;
};

#endif