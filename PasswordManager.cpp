#include "PasswordManager.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define PASSWORD_FILE "passwords.txt"
#define CAESAR_SHIFT 3

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

void PasswordManager::addPassword(const std::string & serviceName, const std::string & password)
{
    if(!isLoggedIn)
    {
        std::cerr << "Error: Must be logged in to add a password." << std::endl;
        return;
    }

    // Encrypting the password using Caesar cipher
    std::string encryptedPassword = caesarCipherEncrypt(password, CAESAR_SHIFT);

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

    passwords.erase(std::remove_if(passwords.begin(), passwords.end(),
        [&](const auto& entry) { return entry.first == serviceName; }), passwords.end());

    savePasswordsToFile();
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
            // Decrypt Password using Caesar cipher
            return caesarCipherDecrypt(entry.second, CAESAR_SHIFT);
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

std::string PasswordManager::caesarCipherEncrypt(const std::string &text, int shift)
{
    std::string result = text;
    for (char &c : result)
    {
        if (isalpha(c))
        {
            c = (c - 'a' + shift) % 26 + 'a';
        }
    }
    return result;
}

std::string PasswordManager::caesarCipherDecrypt(const std::string &text, int shift)
{
    return caesarCipherEncrypt(text, 26 - shift);
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
    

    std::string serviceName, encryptedPassword;
    while (file >> serviceName >> encryptedPassword)
    {
        passwords.push_back(std::make_pair(serviceName, encryptedPassword));
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
        file << entry.first << " " << entry.second << std::endl;
    }

    file.close();
}
