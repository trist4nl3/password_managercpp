#include "PasswordManager.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <openssl/evp.h>

#define AES_BLOCK_SIZE 16
#define AES_KEY_SIZE 32
#define PASSWORD_FILE "passwords.txt"


PasswordManager::PasswordManager()
{
    isLoggedin = false;
}

bool PasswordManager::login(const std::string & username, const std::string & password)
{
return false;
}

void PasswordManager::loadPasswordsFromFile()
{
    std::ifstream file(PASSWORD_FILE);
    if (!file.is_open())
    {
        std::cerr << "Error: Password file was unable to open." << std::endl;
        return;
    }

    passwords.clear();
    

    std::string serviceName, encrpytedPassword;
    while (file >> serviceName >> encrpytedPassword)
    {
        passwords.push_back(std::make_pair(serviceName, encrpytedPassword));
    }

    file.close();
}

void PasswordManager::savePasswordsToFile()
{
    std::ofstream file(PASSWORD_FILE);
    if (!file.is_open())
    {
        std::cerr << "Error: Password file was unable to open." << std::endl;
        return;
    }

    for (const auto& entry : passwords)
    {
        file << entry.first << "" << entry.second << std::endl;
    }

    file.close();
}





