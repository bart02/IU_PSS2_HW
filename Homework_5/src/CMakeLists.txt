add_executable(Homework_5 main.cpp Gateways/PassengerGateway.cpp Gateways/PassengerGateway.h Gateways/DriverGateway.cpp Gateways/DriverGateway.h DB.h Helpers/random_string.h Helpers/exceptions.h Helpers/random_string.cpp Backend.cpp Backend.h)
target_link_libraries(Homework_5 PRIVATE sqlite_orm::sqlite_orm)
