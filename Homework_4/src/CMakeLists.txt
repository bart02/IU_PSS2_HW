add_executable(Homework_4 main.cpp PassengerGateway.cpp PassengerGateway.h DriverGateway.cpp DriverGateway.h DB.h random_string.h exceptions.h random_string.cpp Backend.cpp Backend.h)
target_link_libraries(Homework_4 PRIVATE sqlite_orm::sqlite_orm)
