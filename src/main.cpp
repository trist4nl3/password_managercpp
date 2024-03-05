#include <iostream>
#include <string>
#include "PasswordManager.hpp"

void printMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Login\n";
    std::cout << "2. Add Password\n";
    std::cout << "3. Remove Password\n";
    std::cout << "4. Get Password\n";
    std::cout << "5. Generate Password\n";
    std::cout << "6. Logout\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    PasswordManager manager;
    bool loggedIn = false;

    int choice;
    while (true) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character from input buffer

        switch (choice) {
            case 1: {
                if (!loggedIn) {
                    std::string username, password;
                    std::cout << "Enter username: ";
                    std::getline(std::cin, username);
                    std::cout << "Enter master password: ";
                    std::getline(std::cin, password);

                    if (manager.login(username, password)) {
                        loggedIn = true;
                        std::cout << "Login successful." << std::endl;
                    } else {
                        std::cout << "Login failed. Please try again." << std::endl;
                    }
                } else {
                    std::cout << "Already logged in. Please logout first." << std::endl;
                }
                break;
            }
            case 2: {
                if (loggedIn) {
                    std::string serviceName, password;
                    std::cout << "Enter service name: ";
                    std::getline(std::cin, serviceName);
                    std::cout << "Enter password: ";
                    std::getline(std::cin, password);

                    manager.addPassword(serviceName, password);
                    std::cout << "Password added successfully." << std::endl;
                } else {
                    std::cout << "Please login first." << std::endl;
                }
                break;
            }
            case 3: {
                if (loggedIn) {
                    std::string serviceName;
                    std::cout << "Enter service name to remove password: ";
                    std::getline(std::cin, serviceName);

                    manager.removePassword(serviceName);
                } else {
                    std::cout << "Please login first." << std::endl;
                }
                break;
            }
            case 4: {
                if (loggedIn) {
                    std::string serviceName;
                    std::cout << "Enter service name to get password: ";
                    std::getline(std::cin, serviceName);

                    std::cout << "Password for " << serviceName << ": " << manager.getPassword(serviceName) << std::endl;
                } else {
                    std::cout << "Please login first." << std::endl;
                }
                break;
            }
            case 5: {
                int length;
                std::cout << "Enter password length to generate: ";
                std::cin >> length;
                std::cin.ignore(); // Clear newline character from input buffer

                std::cout << "Generated password: " << manager.generatePassword(length) << std::endl;
                break;
            }
            case 6: {
                manager.logout();
                loggedIn = false;
                std::cout << "Logged out successfully." << std::endl;
                break;
            }
            case 7: {
                std::cout << "Exiting program." << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}