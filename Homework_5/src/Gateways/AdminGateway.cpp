//
// Created by Artem Batalov on 28.04.2021.
//

#include "AdminGateway.h"

void AdminGateway::signup(const string &login, const string &password) {
    int users_with_same_login = DB::storage.count<Admin>(where(c(&Admin::login) == login));
    if (users_with_same_login != 0) {
        throw LoginBusy();
    }

    Admin a{-1, login, password};
    DB::storage.insert(a);
}

Admin AdminGateway::login(const string& login, const string& password) {
    auto vec = DB::storage.get_all<Admin>(where(c(&Admin::login) == login and c(&Admin::password) == password));
    if (vec.empty()) {
        throw LoginOrPasswordIncorrect();
    }

    return vec[0];
}

template<typename T>
void AdminGateway::ban(T& user) {
    user.ban = true;
    DB::storage.update(user);
}

template<typename T>
void AdminGateway::unban(T &user) {
    user.ban = false;
    DB::storage.update(user);
}

void AdminGateway::validate(Car &car) {
    car.validated = true;
    DB::storage.update(car);
}
