#include <string>
#include <vector>

class PasswordManager {
public:
    PasswordManager();
    bool login(const std::string& username, const std::string& password);
    void logout();
    void addPassword(const std::string& serviceName, const std::string& password);
    void removePassword(const std::string& serviceName);
    std::string getPassword(const std::string& serviceName);
    std::string generatePassword(int length);

private:
    std::string username;
    std::string masterPassword;
    bool isLoggedIn;
    std::vector<std::pair<std::string, std::string>> passwords;

    void loadPasswordsFromFile();
    void savePasswordsToFile();
    std::string caesarCipherEncrypt(const std::string& text, int shift);
    std::string caesarCipherDecrypt(const std::string& text, int shift);
};