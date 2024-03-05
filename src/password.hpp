#include <string>


class Password {
    private:
        std::string username;
        std::string password;
        std::string serviceName;
    public:
        Password::Password(const std::string& username, const std::string& password, const std::string& serviceName);
        std::string getUsername() const;
        std::string getPassword() const;
        std::string getServiceName() const;
        void setPassword(const std::string& newPassword);
        
};