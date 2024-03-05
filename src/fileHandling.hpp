#include <string>
#include "encryption.hpp"

class FileHandling {
private:
    const std::string userDataFilePath = "userdata.txt";
    const std::string encryptionKeyFilePath = "encryptionkey.txt";
    Encryption encryption;

    void encryptFile(const std::string& filePath);
    void decryptFile(const std::string& filePath);

public:
    void loadUserData();
    void saveUserData();
    void saveEncryptionKey();
    void loadEncryptionKey();
};