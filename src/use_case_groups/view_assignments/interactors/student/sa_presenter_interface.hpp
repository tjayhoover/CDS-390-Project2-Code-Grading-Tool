#ifndef SA_PRESENTER_INTERFACE_HPP
#define SA_PRESENTER_INTERFACE_HPP

#include "../../request_response_models/student_view_assignments_models.hpp"

class SAPresenterInterface {

public:
    virtual void presentResult(student_view_assignments_response data) = 0;
};

#endif