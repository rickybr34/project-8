#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "Contact.h"

// A patient registered with the clinic
class Patient {
public:
    Patient(int patientID, const std::string& firstName, const std::string& lastName, const Contact& contact);

    int getPatientID() const;
    std::string getFullName() const;
    const Contact& getContact() const;

private:
    int m_patientID;
    std::string m_firstName;
    std::string m_lastName;
    Contact m_contact;
};

#endif