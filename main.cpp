#include "PasswordManager.hpp"
#include <iostream>
#include <iomanip>

void printMenu() {
    std::cout << "Password Manager CLI" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Add Password" << std::endl;
    std::cout << "3. Retrieve Password" << std::endl;
    std::cout << "4. Remove Password" << std::endl;
    std::cout << "5. Logout" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    PasswordManager manager;
    bool loggedIn = false;

    while (true) {
        printMenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character

        switch (choice) {
            case 1: {
                std::string username, password;
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                loggedIn = manager.login(username, password);
                if (loggedIn) {
                    std::cout << "Login successful." << std::endl;
                } else {
                    std::cout << "Login failed. Please try again." << std::endl;
                }
                break;
            }
            case 2: {
                if (!loggedIn) {
                    std::cout << "Please login first." << std::endl;
                    break;
                }
                std::string serviceName, password;
                std::cout << "Enter service name: ";
                std::getline(std::cin, serviceName);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                manager.addPassword(serviceName, password);
                std::cout << "Password added successfully." << std::endl;
                break;
            }
            case 3: {
                if (!loggedIn) {
                    std::cout << "Please login first." << std::endl;
                    break;
                }
                std::string serviceName;
                std::cout << "Enter service name: ";
                std::getline(std::cin, serviceName);
                std::cout << "Password: " << manager.getPassword(serviceName) << std::endl;
                break;
            }
            case 4: {
                if (!loggedIn) {
                    std::cout << "Please login first." << std::endl;
                    break;
                }
                std::string serviceName;
                std::cout << "Enter service name: ";
                std::getline(std::cin, serviceName);
                manager.removePassword(serviceName);
                std::cout << "Password removed successfully." << std::endl;
                break;
            }
            case 5: {
                manager.logout();
                loggedIn = false;
                std::cout << "Logged out." << std::endl;
                break;
            }
            case 6: {
                std::cout << "Exiting..." << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}