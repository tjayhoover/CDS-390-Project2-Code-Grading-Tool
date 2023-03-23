#ifndef CHANGE_PASSWORD_PRESENTER_HPP
#define CHANGE_PASSWORD_PRESENTER_HPP

#include "../../interactors/change_password/presenter_interface.hpp"
#include "view_interface.hpp"
#include <memory>

class ChangePasswordPresenter: public ChangePasswordPresenterInterface {

public:
    void presentResult(change_password_response) override;

    template <class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    std::unique_ptr<ViewInterface> view;
};

#endif
