#ifndef AUTHENTICATOR_HPP
#define AUTHENTICATOR_HPP

#include "abstract_authenticator.hpp"

#include <string>

class Authenticator: public AbstractAuthenticator {

public:
    std::pair<int,std::string> authenticate_user(const std::string& username, const std::string& password, int permission) override;

};


#endif