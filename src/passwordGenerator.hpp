#include <string>
#include "passwordManager.hpp"

class PasswordGenerator {
private:
    int minLength = 8;
    bool includeSpecialCharacters = true;
    PasswordManager passwordManager;

    char generateRandomCharacter();

public:
    std::string generatePassword();
    void setPasswordLength(int length);
    void includeSpecialCharacters(bool include);
};