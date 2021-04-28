//
// Created by Artem Batalov on 10.04.2021.
//

#ifndef HOMEWORK_5_DRIVERGATEWAY_H
#define HOMEWORK_5_DRIVERGATEWAY_H

#include <string>
#include "../Helpers/exceptions.h"
#include "../DB.h"

class DriverGateway {
public:
    void signup(const string& name, const string& login, const string& password, const string& car_name, const int& car_type);

    Driver login(const string& login, const string& password);

    void on_line(Driver& driver);

    void get_order(Driver& driver, Order& order);
    void arrived(Order& order);
    void done(Order& order);

    Order current_order(const Driver& driver);
    vector<Order> available_orders(const Driver &driver);
    vector<Order> order_history(const Driver& driver);
};


#endif //HOMEWORK_5_DRIVERGATEWAY_H
