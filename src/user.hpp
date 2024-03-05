#include <string>

class User {
    private:
        std::string username;
        std::string masterPassword;
    public:
        User(const std::string& username, const std::string& masterPassword);
        bool validateMasterPassword(const std::string& masterPassword) const;
        std::string getUsername() const;
        void setMasterPassword(const std::string& newMasterPassword);
}