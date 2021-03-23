cmake_minimum_required(VERSION 3.17)
project(HW3)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW3 main.cpp Room.cpp Room.h access.h User.cpp User.h access.cpp Alarm.cpp Alarm.h)