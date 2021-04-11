//
// Created by Artem Batalov on 10.04.2021.
//

#ifndef HOMEWORK_4_DRIVERGATEWAY_H
#define HOMEWORK_4_DRIVERGATEWAY_H

#include <string>
#include "exceptions.h"
#include "DB.h"

class DriverGateway {
public:
    void signup(const string& name, const string& login, const string& password);
    void signup(const string& name, const string& login);

    Driver login(const string& login, const string& password);

    void on_line(Driver& driver);
    vector<Order> order_history(const Driver& driver);

};


#endif //HOMEWORK_4_DRIVERGATEWAY_H
