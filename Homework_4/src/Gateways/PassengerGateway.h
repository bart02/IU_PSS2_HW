//
// Created by Artem Batalov on 10.04.2021.
//

#ifndef HOMEWORK_4_PASSENGERGATEWAY_H
#define HOMEWORK_4_PASSENGERGATEWAY_H

#include <string>
#include <vector>
#include "../Helpers/exceptions.h"
#include "../DB.h"

using namespace std;


class PassengerGateway {
public:
    void signup(const string& name, const string& login, const string& password);
    void signup(const string& name, const string& login);

    Passenger login(const string& login, const string& password);

    void add_payment_method(const Passenger& passenger, const string& method);

    Order order_taxi(const Passenger& passenger, const string& from, const string& to, int carType);

    Order current_order(const Passenger& passenger);
    Car car_info(const Order& order);

    vector<Order> order_history(const Passenger& passenger);
};


#endif //HOMEWORK_4_PASSENGERGATEWAY_H
