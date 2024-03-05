#include <unordered_set>
#include <string>
#include "passwordManager.hpp"

class UserAuthentication {
private:
    std::unordered_set<std::string> loggedInUsers;
    PasswordManager passwordManager;

    bool validateUsername(const std::string& username) const;
    bool validateMasterPassword(const std::string& masterPassword) const;

public:
    bool loginUser(const std::string& username, const std::string& masterPassword);
    void logoutUser(const std::string& username);
    void registerUser(const std::string& username, const std::string& masterPassword);
    bool isLoggedIn(const std::string& username) const;
};