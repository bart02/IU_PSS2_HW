//
// Created by Artem Batalov on 21.02.2021.
//

#ifndef HW2_ACCESS_H
#define HW2_ACCESS_H

class User;
class Room;

enum access {
    GREEN, YELLOW, RED, NO_LEVEL
};

bool checkAccess(Room* room, User* user);

#endif //HW2_ACCESS_H
