//
// Created by Artem Batalov on 11.04.2021.
//

#include "Backend.h"
#include "DB.h"
#include <cstdlib>

int Backend::calculate_sum(const string &from, const string &to, int clas) {
    return 5;
}

void Backend::update_geo() {
    auto cars = DB::storage.get_all<Car>();
    for (Car &c : cars) {
        c.coordinates_lat = std::rand();
        c.coordinates_lon = std::rand();
        DB::storage.update(c);
    }
}
