add_executable(Homework_4 main.cpp Gateways/PassengerGateway.cpp Gateways/PassengerGateway.h Gateways/DriverGateway.cpp Gateways/DriverGateway.h DB.h Helpers/random_string.h Helpers/exceptions.h Helpers/random_string.cpp Backend.cpp Backend.h)
target_link_libraries(Homework_4 PRIVATE sqlite_orm::sqlite_orm)
