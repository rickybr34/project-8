#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
    Contact(const std::string& phoneNum, const std::string& address, const std::string& email);

    // True if phone number only has 10 digits
    static bool isPhoneValid(const std::string& phoneNum);

    const std::string& getPhoneNum() const;
    const std::string& getEmail() const;
    const std::string& getAddress() const;

private:
    std::string m_phoneNum;
    std::string m_address;
    std::string m_email;
};
#endif