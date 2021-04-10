//
// Created by Artem Batalov on 21.02.2021.
//

#ifndef HW3_ACCESS_H
#define HW3_ACCESS_H

class User;
class Room;
class Alarm;

enum access {
    BLUE, GREEN, YELLOW, RED, NO_LEVEL
};

bool checkAccess(Alarm& alarm, Room* room, User* user);

#endif //HW3_ACCESS_H
