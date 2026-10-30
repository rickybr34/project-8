#ifndef APPOINTMENT_MANAGER_H
#define APPOINTMENT_MANAGER_H

#include <string>
#include <unordered_map>
#include "Patient.h"

class AppointmentManager {
public:
    // Registers a new patient and assigns them a unique numerical id
    // returns -1 if a name is empty or phone is not valid, otherwise returns new id
    int addPatient(const std::string& firstName, const std::string& lastName, const Contact& contact);

private:
    std::unordered_map<int, Patient> m_patients;
    int m_nextPatientId = 1;
};

#endif