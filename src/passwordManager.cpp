#include "PasswordManager.hpp"
#include "AES.hpp"
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
    isLoggedIn = false;
}

bool PasswordManager::login(const std::string & username, const std::string & password)
{
    this->username = username;
    this->masterPassword = password;

    loadPasswordsFromFile();

    isLoggedIn = true;
    return true;
}

void PasswordManager::logout()
{
    isLoggedIn = false;
    username.clear();
    masterPassword.clear();
}

void PasswordManager::addPassword(const std::string & username, const std::string & password)
{
    if(!isLoggedIn)
    {
        std::cerr << "Error: Must be logged in to add a password." << std::endl;
        return;
    }

    // Encrypting the password using AES
    unsigned char key[AES_KEY_SIZE];
    strncpy((char*)key, masterPassword.c_str(), AES_KEY_SIZE);

    unsigned char ciphertext[password.length() + AES_BLOCK_SIZE];
    if (!aesEncrypt((const unsigned char*)password.c_str(), password.length(), key, ciphertext))
    {
        std::cerr << "Error: Unable to encrypt password." << std::endl;
        return;
    }

    // Convert the ciphertext to hexadecimal string
    std::string encryptedPassword;
    for (int i = 0; i < AES_BLOCK_SIZE; ++i)
    {
        char hex[3];
        sprintf(hex, "%02x", ciphertext[i]);
        encryptedPassword += hex;
    }

    passwords.push_back(std::make_pair(serviceName, encryptedPassword));
    savePasswordsToFile();
}

void PasswordManager::removePassword(const std::string & serviceName)
{
    if(!isLoggedIn)
    {
        std::cerr << "Error: Must be logged in to remove a password." << std::endl;
        return;
    }

    for (auto it = passwords.begin(); it != passwords.end(); ++it)
    {
        if (it->first == serviceName)
        {
            passwords.erase(it);
            savePasswordsToFile();
            return;

        }
    }
}

std::string PasswordManager::getPassword(const std::string & serviceName)
{
    if(!isLoggedIn)
    {
        std::cerr << "Error: Must be logged in to get a password." << std::endl;
        return "";
    }

    for (const auto& entry : passwords)
    {
        if (entry.first == serviceName)
        {
            // Decrypt Password using AES

            unsigned char key[AES_KEY_SIZE];
            strncpy((char*)key, masterPassword.c_str(), AES_KEY_SIZE);

            unsigned char ciphertext[AES_BLOCK_SIZE];

            for (int i = 0; i < AES_BLOCK_SIZE; i += 2)
            {
                std::string hex = entry.second.substr(i, 2);
                ciphertext[i / 2] = (unsigned char)strtol(hex.c_str(), NULL, 16);
            }

            unsigned char decryptedPassword[AES_BLOCK_SIZE];
            if (!aesDecrypt(ciphertext, AES_BLOCK_SIZE, key, decryptedPassword))
            {
                std::cerr << "Error: Unable to decrypt password." << std::endl;
                return "";
            }

            return std::string((char*)decryptedPassword);
        }
    }
    std::cerr << "Error: Password for service '" << serviceName << "' not found." << std::endl;
    return "";
}

std::string PasswordManager::generatePassword(int length)
{
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+";
    std::string password;
    for (int i = 0; i < length; ++i)
    {
        password += characters[rand() % characters.length()];
    }
    return password;
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





