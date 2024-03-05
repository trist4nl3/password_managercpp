#include <string>
#include <vector>
#include <cstring>
class PasswordManager 
{
    public:
        PasswordManager();

        bool login(const std::string& username, const std::string& password);
        void logout();

        void addPassword(const std::string& username, const std::string& password);
        void removePassword(const std::string& serviceName);
        std::string getPassword(const std::string& serviceName);

        std::string generatePassword(int length);

    private:
        std::string username;
        std::string masterPassword;
        std::string serviceName;
        bool isLoggedIn;
        std::vector<std::pair<std::string, std::string>> passwords; 
        void loadPasswordsFromFile();
        void savePasswordsToFile();
};