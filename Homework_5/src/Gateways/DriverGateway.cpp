//
// Created by Artem Batalov on 10.04.2021.
//

#include "DriverGateway.h"
#include <iostream>
#include "../Helpers/random_string.h"

void DriverGateway::signup(const string &name, const string &login, const string &password) {
    int users_with_same_login = DB::storage.count<Driver>(where(c(&Driver::login) == login));
    if (users_with_same_login != 0) {
        throw LoginBusy();
    }

    Driver drv{-1, name, 0, 0, login, password};
    DB::storage.insert(drv);
}

Driver DriverGateway::login(const string &login, const string &password) {
    auto vec = DB::storage.get_all<Driver>(where(c(&Driver::login) == login and c(&Driver::password) == password));
    if (vec.empty()) {
        throw LoginOrPasswordIncorrect();
    }

    cout << "Welcome " << vec[0].name << ". Your rating is " << vec[0].rating << "." << endl;

    return vec[0];
}

void DriverGateway::on_line(Driver &driver, Car &car) {
    if (car.driver != driver.id) {
        throw CarError();
    }

    driver.status = 1;
    DB::storage.update(driver);

    car.in_use = true;
    DB::storage.update(car);
}

void DriverGateway::get_order(Driver& driver, Order& order) {
    if (driver.ban) {
        throw Banned();
    }

    if (driver.status != 1) {
        throw DriverIsOfflineOrBusy();
    }
    if (order.status != 0) {
        throw OrderAlreadyInProgress();
    }

    driver.status = 2;
    DB::storage.update(driver);

    order.status = 1;
    order.driver = driver.id;
    DB::storage.update(order);
}

vector<Order> DriverGateway::available_orders(const Driver &driver) {
    Car car = DB::storage.get_all<Car>(where(c(&Car::driver) == driver.id))[0];
    return DB::storage.get_all<Order>(where(c(&Order::status) == 0 and c(&Order::carType) <= car.carType));
}

vector<Order> DriverGateway::order_history(const Driver &driver) {
    return DB::storage.get_all<Order>(where(c(&Order::driver) == driver.id));
}

Order DriverGateway::current_order(const Driver &driver) {
    vector<Order> vec = DB::storage.get_all<Order>(where(c(&Order::driver) == driver.id));
    if (vec.empty()) throw NoOrders();
    return vec[0];
}

void DriverGateway::arrived(Order& order) {
    order.status = 2;
    DB::storage.update(order);
}

void DriverGateway::done(Order& order) {
    order.status = 3;
    DB::storage.update(order);
}

Car DriverGateway::new_car(const Driver &driver, const string &car_name, const int &car_type) {
    int bootles = 0;
    if (car_type > 0) bootles = std::rand() % 10;

    Car car{-1, car_name, driver.id, car_type, bootles, 0, 0, false};
    car.id = DB::storage.insert(car);

    return car;
}

