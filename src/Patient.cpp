#include "Patient.h"

Patient::Patient(int patientID, const std::string& firstName, const std::string& lastName, const Contact& contact)
    : m_patientID(patientID), m_firstName(firstName), m_lastName(lastName), m_contact(contact) {}

int Patient::getPatientID() const { 
    return m_patientID; 
}
std::string Patient::getFullName() const { 
    return m_firstName + " " + m_lastName; 
}
const Contact& Patient::getContact() const { 
    return m_contact; 
}