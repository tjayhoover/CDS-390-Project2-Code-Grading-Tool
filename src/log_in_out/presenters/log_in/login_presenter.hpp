#ifndef LOGIN_PRESENTER_HPP
#define LOGIN_PRESENTER_HPP

#include "../../interactors/log_in/presenter_interface.hpp"
#include "view_interface.hpp"
#include "../../request_response_models/login_models.hpp"
#include <memory>

#include <iostream>

class LoginPresenter: public LoginPresenterInterface {

public:
    void presentResult(login_response data) override;

    template<class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    std::unique_ptr<ViewInterface> view;
};

#endif
