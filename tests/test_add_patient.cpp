#include <gtest/gtest.h>
#include "AppointmentManager.h"


TEST(AddPatientTest, NewPatientAdded) {
    AppointmentManager manager;
    Contact contact("123-456-7891", "100 Main st", "jsmith@umb.com");
    EXPECT_EQ(manager.addPatient("John", "Smith", contact), 1);
}

TEST(AddPatientTest, EmptyNameIsRejected) {
    AppointmentManager manager;
    Contact contact("123-456-7891", "100 Main st", "jsmith@umb.com");
    EXPECT_EQ(manager.addPatient("", "Smith", contact), -1);
}

TEST(AddPatientTest, InvalidPhoneIsRejected) {
    AppointmentManager manager;
    Contact contact("1234", "100 Main st", "jsmith@umb.com");
    EXPECT_EQ(manager.addPatient("John", "Smith", contact), -1);
}

TEST(AddPatientTest, UniqueIds) {
    AppointmentManager manager;
    Contact contact1("123-456-7891", "100 Main st", "jsmith@umb.com");
    Contact contact2("987-654-3210", "20 morrissey blvd", "jdoe@umb.com");
    int patient1 = manager.addPatient("John", "Smith", contact1);
    int patient2 = manager.addPatient("Jane", "Doe", contact2);
    EXPECT_EQ(patient2, 2);
}