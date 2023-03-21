#include "log_in.hpp"

LoginInteractor::LoginInteractor(AbstractDatabase* d, AbstractAuthenticator* a, LoginPresenterInterface* p) :
    storage(d), authenticator(a), presenter(p) {}