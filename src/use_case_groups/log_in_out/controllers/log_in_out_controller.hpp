#ifndef LOG_IN_OUT_CONTROLLER_HPP
#define LOG_IN_OUT_CONTROLLER_HPP

#include "../interactors/log_in/log_in.hpp"
#include "../interactors/log_out/log_out.hpp"

#include "input_request_models.hpp"

class LogInOutController {

public:
    LogInOutController(LoginInteractor, LogoutInteractor);

    std::pair<bool, User> start_login_process(log_in_input);
    void start_logout_process();

private:
    LoginInteractor login_interactor;
    LogoutInteractor logout_interactor;
};

#endif