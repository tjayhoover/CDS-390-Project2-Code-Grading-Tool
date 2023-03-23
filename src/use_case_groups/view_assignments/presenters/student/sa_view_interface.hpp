#ifndef SA_VIEW_INTERFACE_HPP
#define SA_VIEW_INTERFACE_HPP

#include "view_model.hpp"

class SAViewInterface {

public:
    virtual void display(ViewModel data) = 0;
};


#endif