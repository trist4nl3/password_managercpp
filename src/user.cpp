#include "user.hpp"

User::User(const std::string &username, const std::string &masterPassword)
    : username(username), masterPassword(masterPassword) {}

bool User::validateMasterPassword(const std::string &masterPassword) const
{
    return this->masterPassword == masterPassword;
}

std::string User::getUsername() const
{
    return username;
}

void User::setMasterPassword(const std::string &newMasterPassword)
{
    masterPassword = newMasterPassword;
}
