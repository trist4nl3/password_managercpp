#include <string>
#include "passwordManager.hpp"

class CLI {
private:
    const std::string menuOptions = "1. Add Password\n2. Retrieve Password\n3. Update Password\n4. Delete Password\n5. Change Master Password\n6. Logout\n7. Exit";
    const std::string prompt = "Enter your choice: ";
    PasswordManager passwordManager;

    void clearScreen();
    void displayMenu();

public:
    int getUserChoice();
    void displayPrompt(const std::string& message);
};