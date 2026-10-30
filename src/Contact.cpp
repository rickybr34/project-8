#include "Contact.h"
#include <cctype>

Contact::Contact(const std::string& phoneNum, const std::string& address, const std::string& email)
    : m_phoneNum(phoneNum), m_address(address), m_email(email) {}

bool Contact::isPhoneValid(const std::string& phoneNum) {
    int digits = 0;
    for (char c : phoneNum) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            digits++;
        }
    }
    return digits == 10;
}

const std::string& Contact::getPhoneNum() const { 
    return m_phoneNum;
}
const std::string& Contact::getEmail() const { 
    return m_email;
}
const std::string& Contact::getAddress() const { 
    return m_address;
}