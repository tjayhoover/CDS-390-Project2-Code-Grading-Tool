#ifndef SUBMISSION_PRESENTER_HPP
#define SUBMISSION_PRESENTER_HPP

#include "../interactors/presenter_interface.hpp"
#include "view_interface.hpp"

class SubmissionPresenter: public PresenterInterface {

public:
    SubmissionPresenter(ViewInterface*);

    void presentResult(return_data data) override;

private:
    ViewInterface* view;
};

#endif
