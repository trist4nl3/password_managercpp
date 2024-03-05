#include <string>

#include <string>
#include "password.hpp"
#include "fileHandling.hpp"

class Encryption {
private:
    std::string encryptionKey;
    FileHandling fileHandling;

    std::string generateEncryptionKey();
    void initializeAES();
    void initializeRSA();

public:
    std::string encryptPassword(const std::string& password);
    std::string decryptPassword(const std::string& encryptedPassword);
    std::string encryptKey(const std::string& key);
    std::string decryptKey(const std::string& encryptedKey);
};