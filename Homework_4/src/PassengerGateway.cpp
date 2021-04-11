//
// Created by Artem Batalov on 10.04.2021.
//

#include <iostream>
#include "PassengerGateway.h"
#include "random_string.h"
#include "Backend.h"

void PassengerGateway::signup(const string &name, const string &login, const string &password) {
    int users_with_same_login = DB::storage.count<Passenger>(where(c(&Passenger::login) == login));
    if (users_with_same_login != 0) {
        throw LoginBusy();
    }

    Passenger pax{-1, name, 0, login, password};
    DB::storage.insert(pax);
}

void PassengerGateway::signup(const string& name, const string& login) {
    signup(name, login, random_string(10));
}

Passenger PassengerGateway::login(const string &login, const string &password) {
    auto vec = DB::storage.get_all<Passenger>(where(c(&Passenger::login) == login and c(&Passenger::password) == password));
    if (vec.empty()) {
        throw LoginOrPasswordIncorrect();
    }

    cout << "Welcome " << vec[0].name << ". Your rating is " << vec[0].rating << "." << endl;

    return vec[0];
}

Order PassengerGateway::order_taxi(const Passenger& passenger, const string &from, const string &to, int clas) {
    auto available_drivers = DB::storage.get_all<Driver>(where(c(&Driver::status) == 1));
    if (available_drivers.empty()) {
        throw NoDrivers();
    }

    int sum = Backend::calculate_sum(from, to, clas);

    Order ord{-1, from, to, passenger.id, -1, sum, 0};
    ord.id = DB::storage.insert(ord);

    return ord;
}

vector<Order> PassengerGateway::order_history(const Passenger &passenger) {
    return DB::storage.get_all<Order>(where(c(&Order::passenger) == passenger.id));
}
