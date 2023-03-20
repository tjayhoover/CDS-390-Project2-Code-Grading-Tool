#ifndef SUBMISSION_PRESENTER_HPP
#define SUBMISSION_PRESENTER_HPP

#include "../interactors/presenter_interface.hpp"
#include "view_interface.hpp"

class Presenter: public PresenterInterface {

public:
    Presenter(ViewInterface*);

    void presentResult(return_data data) override;

private:
    ViewInterface* view;
};

#endif
