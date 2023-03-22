#ifndef SUBMISSION_PRESENTER_HPP
#define SUBMISSION_PRESENTER_HPP

#include "../interactors/presenter_interface.hpp"
#include "view_interface.hpp"
#include <memory>

#include <iostream>

class SubmissionPresenter: public PresenterInterface {

public:
    //SubmissionPresenter();

    void presentResult(submission_response data) override;

    template<class V>
    void setView() {
        view = std::make_unique<V>();
    }

private:
    std::unique_ptr<ViewInterface> view;
};

#endif