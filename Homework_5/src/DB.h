//
// Created by Artem Batalov on 10.04.2021.
//

#ifndef HOMEWORK_5_DB_H
#define HOMEWORK_5_DB_H

#include <iostream>
#include <sqlite_orm/sqlite_orm.h>

using namespace std;
using namespace sqlite_orm;

struct Passenger{
    int id;
    string name;
    int rating;
    string login;
    string password;
};

struct Driver{
    int id;
    string name;
    int rating;
    int status; // 0 - offline, 1 - on line (free), 2 - on order;
    string login;
    string password;
};

struct Order{
    int id;
    string from;
    string to;
    int passenger;
    int driver;
    int carType; // 0 - Economy, 1 - Comfort, 2 - ComfortPlus, 3 - Business
    int sum;
    int status; // 0 - car not assigned; 1 - car is en route; 2 - waiting; 3 - done; -1 - car not found
};

struct Car{
    int id;
    string name;
    int driver;
    int carType; // 0 - Economy, 1 - Comfort, 2 - ComfortPlus, 3 - Business
    int freeBottleOfwater;
    int coordinates_lat;
    int coordinates_lon;

    void parkRightInFrontOfTheEntrance() {
        if (carType == 3) {
            cout << "Of course!" << endl;
        } else {
            cout << "Ti cho, ni budu ia nikuda porkovatsa!" << endl;
        }
    }
};

struct PaymentMethod{
    int id;
    int passenger;
    string method;
};

inline auto init_storage() {
    return make_storage("db.sqlite",
                        make_table("passengers",
                                   make_column("id", &Passenger::id, autoincrement(), primary_key()),
                                   make_column("name", &Passenger::name),
                                   make_column("rating", &Passenger::rating),
                                   make_column("login", &Passenger::login),
                                   make_column("password", &Passenger::password)),
                        make_table("drivers",
                                   make_column("id", &Driver::id, autoincrement(), primary_key()),
                                   make_column("name", &Driver::name),
                                   make_column("rating", &Driver::rating),
                                   make_column("status", &Driver::status),
                                   make_column("login", &Driver::login),
                                   make_column("password", &Driver::password)),
                        make_table("orders",
                                   make_column("id", &Order::id, autoincrement(), primary_key()),
                                   make_column("from", &Order::from),
                                   make_column("to", &Order::to),
                                   make_column("passenger", &Order::passenger),
                                   make_column("driver", &Order::driver),
                                   make_column("carType", &Order::carType),
                                   make_column("sum", &Order::sum),
                                   make_column("status", &Order::status)),
                        make_table("cars",
                                   make_column("id", &Car::id, autoincrement(), primary_key()),
                                   make_column("name", &Car::name),
                                   make_column("driver", &Car::driver),
                                   make_column("carType", &Car::carType),
                                   make_column("lat", &Car::coordinates_lat),
                                   make_column("lon", &Car::coordinates_lon)),
                        make_table("payment",
                                   make_column("id", &PaymentMethod::id, autoincrement(), primary_key()),
                                   make_column("passenger", &PaymentMethod::passenger),
                                   make_column("method", &PaymentMethod::method)));
}
using Storage = decltype(init_storage());

class DB {
public:
    static Storage storage;
};


#endif //HOMEWORK_5_DB_H
