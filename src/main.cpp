#include "passwordManager.hpp"
#include "encryption.hpp"
#include "fileHandling.hpp"
#include "userAuthentication.hpp"
#include "passwordGenerator.hpp"
#include "cli.hpp"

int main() {
    // Instantiate objects
    PasswordManager passwordManager;
    Encryption encryption;
    FileHandling fileHandling;
    UserAuthentication userAuth;
    PasswordGenerator passwordGenerator;
    CLI cli;


    return 0;
}