//
// Created by Artem Batalov on 10.04.2021.
//

#include "DriverGateway.h"
#include <iostream>
#include "random_string.h"

void DriverGateway::signup(const string &name, const string &login, const string &password) {
    int users_with_same_login = DB::storage.count<Driver>(where(c(&Driver::login) == login));
    if (users_with_same_login != 0) {
        throw LoginBusy();
    }

    Driver drv{-1, name, 0, 0, login, password};
    DB::storage.insert(drv);
}

void DriverGateway::signup(const string& name, const string& login) {
    signup(name, login, random_string(10));
}

Driver DriverGateway::login(const string &login, const string &password) {
    auto vec = DB::storage.get_all<Driver>(where(c(&Driver::login) == login and c(&Driver::password) == password));
    if (vec.empty()) {
        throw LoginOrPasswordIncorrect();
    }

    cout << "Welcome " << vec[0].name << ". Your rating is " << vec[0].rating << "." << endl;

    return vec[0];
}

void DriverGateway::on_line(Driver &driver) {
    driver.status = 1;
    DB::storage.update(driver);
}

vector<Order> DriverGateway::order_history(const Driver &driver) {
    return DB::storage.get_all<Order>(where(c(&Order::driver) == driver.id));
}
