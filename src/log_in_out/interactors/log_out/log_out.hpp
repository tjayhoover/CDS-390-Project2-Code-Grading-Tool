#ifndef LOG_OUT_HPP
#define LOG_OUT_HPP

#include "presenter_interface.hpp"

class LogoutInteractor {

public:
    LogoutInteractor(LogoutPresenterInterface*);

private:
    LogoutPresenterInterface* presenter;
};

#endif
