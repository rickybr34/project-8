#include <iostream>
#include <string>
#include "AppointmentManager.h"


// prints a prompt (ex. "First name: "), reads one line of user input and returns it
std::string readLine(const std::string& prompt) {
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int main() {
    std::cout << "\nClinic Appointment System\n" << std::endl;
    
    AppointmentManager manager;

    // Demo menu to add patients or exit
    while (true){
        std::cout << "1) Add Patient\n0) Exit\n" << std::endl;
        std::string choice = readLine("Choose 1 or 0: ");

        if (choice == "1") {
            std::string firstName = readLine("First name: ");
            while (firstName.empty()) {
                std::cout << "First name is required. Try again.\n";
                firstName = readLine("First name: ");
            }
            std::string lastName = readLine("Last name: ");
            while (lastName.empty()) {
                std::cout << "Last name is required. Try again.\n";
                lastName = readLine("Last name: ");
            }
            std::string phone = readLine("Phone: ");
            while (!Contact::isPhoneValid(phone)) {
                std::cout << "Phone must have 10 digits. Try again.\n";
                phone = readLine("Phone: ");
            }
            std::string email = readLine("Email: ");
            std::string address = readLine("Address: ");

            int id = manager.addPatient(firstName, lastName, Contact(phone, address, email));
            if (id == -1) {
                std::cout << "Error: Patient failed to be registered. Make sure all fields are input correctly.\n";
            } else {
                std::cout << "\nNew patient " << firstName << " " << lastName << " registered with ID: " << id << "\n\n";
            }
        } else if (choice == "0") {
            break;
        }
    }
    return 0;
}
