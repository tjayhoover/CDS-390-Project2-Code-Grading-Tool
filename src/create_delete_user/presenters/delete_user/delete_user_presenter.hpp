#ifndef DELETE_USER_PRESENTER_HPP
#define DELETE_USER_PRESENTER_HPP

#include "../../interactors/delete_user/presenter_interface.hpp"
#include "view_interface.hpp"
#include <memory>

class DeleteUserPresenter: DeleteUserPresenterInterface {

public:
    void presentResult(delete_user_response) override;

    template <class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    std::unique_ptr<ViewInterface> view;
};

#endif