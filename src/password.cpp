#include "password.hpp"

// Initalizing, trying new method
Password::Password(const std::string &username, const std::string &password, const std::string &serviceName) 
    : username(username), password(password), serviceName(serviceName) {}

std::string Password::getUsername() const
{
    return username;
}

std::string Password::getPassword() const
{
    return password;
}

std::string Password::getServiceName() const
{
    return serviceName;
}

void Password::setPassword(const std::string &newPassword)
{
    password = newPassword;
}
