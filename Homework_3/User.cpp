//
// Created by Artem Batalov on 21.02.2021.
//

#include "User.h"
#include "Room.h"
#include <iostream>

User::User(const std::string &name, access accessLevel) : name(name), access_level(accessLevel) {}

std::string User::getName() const {
    return name;
}

access User::getAccessLevel() const {
    return access_level;
}


Guest::Guest(const std::string &name, const std::string &event, access accessLevel) : User(name, accessLevel), event(event) {}

void Guest::printInfo() {
    std::cout << "I'm a Guest of `" << this->event << "` event. My name is " << this->getName() << "." << std::endl;
}


Student::Student(const std::string &name, int stipa, access accessLevel) : User(name, accessLevel), stipa(stipa) {}

void Student::printInfo() {
    std::cout << "I'm a Student. My name is " << this->getName() << ". I have " << this->stipa << " rub. of Dobraya volya Universiteta." << std::endl;
}


Professor::Professor(const std::string &name, const std::string &joke, access accessLevel) : User(name, accessLevel),
                                                                                             joke(joke) {}

void Professor::printInfo() {
    std::cout << "I'm a Professor. My name is " << this->getName() << ". " << this->joke << "." << std::endl;
}


LabEmployee::LabEmployee(const std::string &name, const std::string &lab, access accessLevel) : User(name, accessLevel),
                                                                                                lab(lab) {}

void LabEmployee::printInfo() {
    std::cout << "I'm a" << this->lab << " lab employee. My name is " << this->getName() << "." << std::endl;
}


Director::Director(const std::string &name, const std::string &car, access accessLevel) : User(name, accessLevel),
                                                                                          car(car) {}

void Director::printInfo() {
    std::cout << "I'm the one and only Director " << this->getName() << "." << std::endl;
}


Admin::Admin(const std::string &name, access accessLevel) : User(name, accessLevel) {}

void Admin::grantAccess(Room *room, User *user) {
    room->customAccess[user] = true;
}

void Admin::printInfo() {
    std::cout << "Odmem. Do not touch." << std::endl;
}
