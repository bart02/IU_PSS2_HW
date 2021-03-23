//
// Created by Artem Batalov on 21.02.2021.
//

#ifndef HW2_USER_H
#define HW2_USER_H

#include "access.h"
#include <string>


class User {
private:
    std::string name;
    access access_level;

public:
    User(const std::string &name, access accessLevel);

    std::string getName() const;
    access getAccessLevel() const;

    virtual void printInfo() = 0;
};


class Guest : public User {
public:
    std::string event;

    Guest(const std::string &name, const std::string &event, access accessLevel = BLUE);
    void printInfo() override;
};

class Student : public User {
public:
    int stipa;

    Student(const std::string &name, int stipa, access accessLevel = GREEN);
    void printInfo() override;
};

class Professor : public User {
public:
    std::string joke;

    Professor(const std::string &name, const std::string &joke, access accessLevel = YELLOW);
    void printInfo() override;
};

class LabEmployee : public User {
public:
    std::string lab;

    LabEmployee(const std::string &name, const std::string &lab, access accessLevel = RED);
    void printInfo() override;
};

class Director : public User {
public:
    std::string car;

    Director(const std::string &name, const std::string &car, access accessLevel = RED);
    void printInfo() override;
};

class Admin : public User {
public:
    Admin(const std::string &name, access accessLevel = RED);

    static void grantAccess(Room* room, User* user);

    void printInfo() override;
};


#endif //HW2_USER_H
