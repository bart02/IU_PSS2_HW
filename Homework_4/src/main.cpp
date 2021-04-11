#include <iostream>
#include <sqlite_orm/sqlite_orm.h>

#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "DB.h"

using namespace std;
using namespace sqlite_orm;

Storage DB::storage = init_storage();

int main() {
    // DB init
    DB::storage.sync_schema();

    // Gateways init
    PassengerGateway pg;
    DriverGateway dg;

    // Registration
//    pg.signup("Artem Batalov", "bart02", "pass");
//    dg.signup("Dzhamshut", "dz", "pass");

    // Actions
    Passenger p = pg.login("bart02", "pass");
    Driver d = dg.login("dz", "pass");

//    Order order = pg.order_taxi(p, "", "", 0);
    dg.on_line(d);
    Order order = pg.order_taxi(p, "", "", 0);

    auto hist = pg.order_history(p);

    std::cout << order.id << std::endl;
    return 0;
}
