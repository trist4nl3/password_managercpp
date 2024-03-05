#include <vector>
#include <unordered_map>
#include <string>
#include "password.hpp"
#include "user.hpp"
#include "encryption.hpp"
#include "fileHandling.hpp"
#include "userAuthentication.hpp"

class PasswordManager {
private:
    std::vector<Password> passwords;
    std::unordered_map<std::string, User> users;
    Encryption encryption;
    FileHandling fileHandling;
    UserAuthentication userAuth;

    bool userExists(const std::string& username) const;
    bool passwordExists(const std::string& username, const std::string& password) const;

public:
    void addUser(const std::string& username, const std::string& masterPassword);
    bool loginUser(const std::string& username, const std::string& masterPassword);
    void addPassword(const std::string& username, const std::string& password, const std::string& serviceName);
    std::string getPassword(const std::string& username, const std::string& serviceName) const;
    void updatePassword(const std::string& username, const std::string& oldPassword, const std::string& newPassword);
    void deletePassword(const std::string& username, const std::string& serviceName);
    void changeMasterPassword(const std::string& username, const std::string& oldMasterPassword, const std::string& newMasterPassword);
};