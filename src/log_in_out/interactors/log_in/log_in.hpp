#ifndef LOG_IN_HPP
#define LOG_IN_HPP

#include "src/interfaces/abstract_authenticator.hpp"
#include "src/interfaces/abstract_database.hpp"
#include "presenter_interface.hpp"


class LogInUseCase {

public:
    

private:
    AbstractDatabase* storage;
    std::unique_ptr<PresenterInterface> presenter;
};

#endif