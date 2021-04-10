#include <iostream>
#include <sqlite_orm/sqlite_orm.h>

using namespace std;
using namespace sqlite_orm;

struct Passenger{
    int id;
    std::string name;
    int rating;
};

struct Driver{
    int id;
    std::string name;
    int rating;
    int status;
};

auto create_db() {
    return make_storage("db.sqlite",
                        make_table("passengers",
                                   make_column("id", &Passenger::id, autoincrement(), primary_key()),
                                   make_column("name", &Passenger::name),
                                   make_column("rating", &Passenger::rating)),
                        make_table("drivers",
                                   make_column("id", &Driver::id, autoincrement(), primary_key()),
                                   make_column("name", &Driver::name),
                                   make_column("rating", &Driver::rating),
                                   make_column("status", &Driver::status)));
}



int main() {

    auto storage = create_db();
    storage.sync_schema();

    Passenger pax{-1, "Ivan", 0};
    int insertedId = storage.insert(pax);
    cout << "insertedId = " << insertedId << endl;
    pax.id = insertedId;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
