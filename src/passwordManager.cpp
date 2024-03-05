#include "passwordManager.hpp"

bool PasswordManager::userExists(const std::string &username) const
{
    return users.find(username) != users.end();
}

bool PasswordManager::passwordExists(const std::string &username, const std::string &password) const
{
    if (users.find(username) != users.end())
    {
        for (const auto& pass: passwords)
        {
            if (pass.getUsername)
        }
    }
}
