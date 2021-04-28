//
// Created by Artem Batalov on 10.04.2021.
//

#include <iostream>
#include "PassengerGateway.h"
#include "../Helpers/random_string.h"
#include "../Backend.h"

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

Order PassengerGateway::order_taxi(const Passenger& passenger, const string &from, const string &to, int carType) {
//    auto available_drivers = DB::storage.get_all<Driver>(where(c(&Driver::status) == 1));
    if (passenger.ban) {
        throw Banned();
    }

    auto rows = DB::storage.select(columns(&Driver::id, &Car::carType), join<Car>(on(c(&Driver::id) == &Car::driver)), where(c(&Driver::status) == 1 and c(&Car::carType) >= carType));

    if (rows.empty()) {
        throw NoDrivers();
    }

    int sum = Backend::calculate_sum(from, to, carType);

    Order ord{-1, from, to, passenger.id, -1, carType, sum, 0};
    ord.id = DB::storage.insert(ord);

    return ord;
}

vector<Order> PassengerGateway::order_history(const Passenger &passenger) {
    return DB::storage.get_all<Order>(where(c(&Order::passenger) == passenger.id));
}

Order PassengerGateway::current_order(const Passenger& passenger) {
    vector<Order> vec = DB::storage.get_all<Order>(where(c(&Order::passenger) == passenger.id));
    if (vec.empty()) throw NoOrders();
    return vec[0];
}

void PassengerGateway::add_payment_method(const Passenger& passenger, const string& method) {
    PaymentMethod pay{-1, passenger.id, method};
    DB::storage.insert(pay);
}

Car PassengerGateway::car_info(const Order &order) {
    Driver driver = DB::storage.get<Driver>(order.driver);
//    Car car = DB::storage.get<Car>(where(c(&Car::driver) == driver.id));
    return DB::storage.get_all<Car>(where(c(&Car::driver) == driver.id))[0];
}
