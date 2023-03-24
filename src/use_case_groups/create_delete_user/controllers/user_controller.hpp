#ifndef USER_CONTROLLER_HPP
#define USER_CONTROLLER_HPP

#include "../interactors/create_user/create_user.hpp"
#include "../interactors/delete_user/delete_user.hpp"
#include "../interactors/change_password/change_password.hpp"
#include "input_request_models.hpp"

#include <string>

class UserController {
public:
    UserController(CreateUserInteractor, DeleteUserInteractor, ChangePasswordInteractor);

    void create_user(create_user_input);
    void delete_user(delete_user_input);
    void change_password(change_password_input);

private:
    CreateUserInteractor create_user_interactor;
    DeleteUserInteractor delete_user_interactor;
    ChangePasswordInteractor change_password_interactor;
};

#endif