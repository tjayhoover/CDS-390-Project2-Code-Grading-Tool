#ifndef USER_CONTROLLER_HPP
#define USER_CONTROLLER_HPP

#include "../interactors/create_user/create_user.hpp"
#include "../interactors/delete_user/delete_user.hpp"

class UserController {
public:
    UserController(CreateUserInteractor, DeleteUserInteractor);

    void create_user();
    void delete_user();

private:
    CreateUserInteractor create_user_interactor;
    DeleteUserInteractor delete_user_interactor;
};

#endif