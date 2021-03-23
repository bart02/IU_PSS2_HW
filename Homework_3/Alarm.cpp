//
// Created by Artem Batalov on 24.03.2021.
//

#include <iostream>
#include "Alarm.h"

Alarm::Alarm() {
    status = false;
}

void Alarm::on() {
    std::cout << "ATTENTION, EMERGENCY SITUATION, PLEASE LEAVE THE BUILDING IMMEDIATELY USING EMERGENCY EXITS!" << std::endl;
    status = true;
}

void Alarm::off() {
    status = false;
}

bool Alarm::isEmergency() const {
    return status;
}
