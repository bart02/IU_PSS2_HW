//
// Created by Artem Batalov on 28.04.2021.
//

#ifndef HOMEWORK_5_ADMINGATEWAY_H
#define HOMEWORK_5_ADMINGATEWAY_H

#include <string>
#include <vector>
#include "../Helpers/exceptions.h"
#include "../DB.h"

class AdminGateway {
public:
    void signup(const string& login, const string& password);
    Admin login(const string& login, const string& password);

    void banDriver(Driver& user);
    void unbanDriver(Driver& user);
    void banPassenger(Passenger& user);
    void unbanPassenger(Passenger& user);

    void validate(Car& car);
};


#endif //HOMEWORK_5_ADMINGATEWAY_H
