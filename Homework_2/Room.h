//
// Created by Artem Batalov on 21.02.2021.
//

#ifndef HW2_ROOM_H
#define HW2_ROOM_H


#include "access.h"
#include <map>
#include <string>

enum room_type {
    CLASS_ROOM, LECTURE_ROOM, CONFERENCE_ROOM, CABINET, DIRECTOR_CABINET
};

class Room {
private:
    std::string name;
    room_type type;
    access access_level;

public:
    std::map<User*, bool> customAccess;
    access getAccessLevel() const;

    Room(const std::string &name, room_type type, access accessLevel);
    Room(const std::string &name, room_type type);
};


#endif //HW2_ROOM_H
