#include "AppointmentManager.h"

int AppointmentManager::addPatient(const std::string& firstName, const std::string& lastName, const Contact& contact) {
    // input validation before assigning new id
    if (firstName.empty() || lastName.empty()) {
        return -1;
    }
    if (!Contact::isPhoneValid(contact.getPhoneNum())){
        return -1;
    }
    int id = m_nextPatientId++;
    m_patients.insert({id, Patient(id, firstName, lastName, contact)});
    return id;

}