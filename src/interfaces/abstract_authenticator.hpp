#ifndef ABSTRACT_AUTHENTICATOR_HPP
#define ABSTRACT_AUTHENTICATOR_HPP

#include <string>

class AbstractAuthenticator {

public:
    virtual ~AbstractAuthenticator() = default;
    virtual std::pair<int,std::string> authenticate_user(const std::string& username, const std::string& password, int permission) = 0;

};

#endif