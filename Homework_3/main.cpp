#include <iostream>

#include "access.h"
#include "Room.h"
#include "User.h"
#include "vector"

using namespace std;

int main() {
    vector<User*> users;
    for (int i=0; i < 16; i++) users.push_back(new Student("Student " + to_string(i), 20000));

    users.push_back(new Professor("Dr. Konyukhov", "abuv"));
    users.push_back(new Professor("Prof. Gelvanovsky", "Che molchim"));
    users.push_back(new Professor("Prof. Tormasov", "Deep dark details"));
    users.push_back(new Professor("Prof. Succi", "Pobolshe vasabi (i pobolshe vasabi)"));

    users.push_back(new LabEmployee("Oleg Bulichev", "Robotics"));
    users.push_back(new LabEmployee("Mike Ivanov", "Robotics"));
    users.push_back(new LabEmployee("Dmitry Devitt", "Robotics"));
    users.push_back(new LabEmployee("Hamna Aslam", "AI in GameDev"));
    users.push_back(new LabEmployee("Hamna Aslam", "AI in GameDev"));
    users.push_back(new LabEmployee("Joseff Braun", "AI in GameDev"));
    users.push_back(new LabEmployee("Mohammad Reza Bahrami", "Cyber-physics"));
    users.push_back(new LabEmployee("Adil Mohomad Khan", "Khan Academy"));

    users.push_back(new Admin("Nikita"));
    users.push_back(new Admin("Admin2"));

    users.push_back(new Director("Kirill Semeinkhin", "Mercedes"));

    vector<Room*> rooms;
    rooms.push_back(new Room("313", CLASS_ROOM));
    rooms.push_back(new Room("108", LECTURE_ROOM));
    rooms.push_back(new Room("Sky", DIRECTOR_CABINET));

    users[0]->printInfo();

    std::cout << checkAccess(rooms[1], users[0]) << std::endl; // prohobited

    (dynamic_cast<Admin*>(users[27])) -> grantAccess(rooms[1], users[0]); // get access


    std::cout << checkAccess(rooms[1], users[0]) << std::endl; // approved
    return 0;
}
