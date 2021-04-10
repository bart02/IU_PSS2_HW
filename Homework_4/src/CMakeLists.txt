add_executable(Homework_4 main.cpp PassengerGateway.cpp PassengerGateway.h DriverGateway.cpp DriverGateway.h db.h)
target_link_libraries(Homework_4 PRIVATE sqlite_orm::sqlite_orm)
