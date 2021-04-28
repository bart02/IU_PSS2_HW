#include <iostream>
#include <sqlite_orm/sqlite_orm.h>

#include "Gateways/PassengerGateway.h"
#include "Gateways/DriverGateway.h"
#include "DB.h"
#include "Backend.h"
#include "Helpers/random_string.h"

using namespace std;
using namespace sqlite_orm;

Storage DB::storage = init_storage();

int main() {
    // initializations
    print_logo();
    std::srand(std::time(nullptr));
    DB::storage.sync_schema();

    // Gateways init
    PassengerGateway pg;
    DriverGateway dg;

    // Registration
    // All characters appearing in this work are fictitious.
    // Any resemblance to real persons, living or dead, is purely coincidental :).
    pg.signup("Giancarlo Succi", "succi", "wasabbbi");
    pg.signup("Mike Ivanov", "l1va", "l1va4ka"); // it's a joke [or not?)]
    pg.signup("Murat Shaikhutdinov", "notcesar", "10followers");
    pg.signup("Vladimir Makharev", "smirk", "7kilimanjaro");
    pg.signup("Georgy Gelvanovsky", "EgorGelvanovsky", "ch0_m0lch1m");

    dg.signup("Dzhamshut", "dzamshutamana", "nasialnika");
    dg.signup("Shavkatzhon", "ShAvKaTzHoN", "1234567890");
    dg.signup("Ashurmahmed", "mahmed", "shaurma");

    // Actions
    Driver dzam = dg.login("dzamshutamana", "nasialnika");
    Car mers = dg.new_car(dzam, "Mercedes", 3);
    Driver mahmed = dg.login("mahmed", "shaurma");
    Car lada = dg.new_car(mahmed, "Lada Kalina", 0);

    Passenger succi = pg.login("succi", "wasabbbi");
    pg.add_payment_method(succi, "Oplata Online");

    // Pull updates from backend
    Backend::update_geo();

    // Trying to do first order...
    try {
        Order order = pg.order_taxi(succi, "Tsentralnaya st. 179/5", "InnoMax", 3);
    } catch (const NoDrivers& e) {
        cout << e.what() << endl;
    }
    // ... and get No drivers error.

    dg.on_line(mahmed, lada); // Let's switch mahmed to online status

    // Trying to do the order...
    try {
        Order order = pg.order_taxi(succi, "Tsentralnaya st. 179/5", "InnoMax", 3);
    } catch (const NoDrivers& e) {
        cout << e.what() << endl;
    }
    // ... and get |censored| No drivers error.
    // So, stop, we want business-class car, but our driver has only Lada Kalina (not for Succi)

    dg.on_line(dzam, mers); // Let's switch Dzhamshut to online status (he has Mercedes, special for Giancarlo)

    // Trying to do the order...
    try {
        Order order = pg.order_taxi(succi, "Tsentralnaya st. 179/5", "InnoMax", 3);
    } catch (const NoDrivers& e) {
        cout << e.what() << endl;
    }
    // ... and it is working

    auto check_order = pg.current_order(succi);
    cout << pg.current_order(succi).status << endl; // Let's check, status=0

    auto mahmedsorders = dg.available_orders(mahmed); // Mahmed's orders 0
    auto dzahmutsorders = dg.available_orders(dzam); // Dzhamshut's orders 1

    dg.get_order(dzam, dzahmutsorders[0]); // Dzhamshut gets Succi order 1

    // Pull updates from backend
    Backend::update_geo();
    cout << pg.car_info(pg.current_order(succi)).coordinates_lon << endl; // Request coords

    dg.arrived(dzahmutsorders[0]);
    cout << pg.current_order(succi).status << " " << pg.car_info(pg.current_order(succi)).freeBottleOfwater << endl;
    dg.done(dzahmutsorders[0]);
    
    return 0;
}
