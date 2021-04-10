//
// Created by Artem Batalov on 07.03.2021.
//

#include "access.h"
#include "User.h"
#include "Room.h"
#include "Alarm.h"

bool checkAccess(Alarm& alarm, Room* room, User* user) {
    if (alarm.isEmergency()) return true;
    if (room->customAccess.find(user) != room->customAccess.end()) return room->customAccess[user];
    if (user->getAccessLevel() >= room->getAccessLevel()) return true;
    return false;
}
