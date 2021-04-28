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
    void signup(const string& login, const string& password);
    Admin login(const string& login, const string& password);

    template <typename T> void ban(T& user);
    template <typename T> void unban(T& user);

    void validate(Car& car);
};


#endif //HOMEWORK_5_ADMINGATEWAY_H
