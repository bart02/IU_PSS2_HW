//
// Created by Artem Batalov on 21.02.2021.
//

#include "Room.h"

Room::Room(const std::string &name, room_type type, access accessLevel) : name(name), type(type),
                                                                          access_level(accessLevel) {}

Room::Room(const std::string &name, room_type type) : name(name), type(type) {
    switch (type) {
        case CLASS_ROOM:
            access_level = GREEN;
            break;
        case LECTURE_ROOM:
            access_level = YELLOW;
            break;
        case CONFERENCE_ROOM:
            access_level = YELLOW;
            break;
        case CABINET:
            access_level = RED;
            break;
        case DIRECTOR_CABINET:
            access_level = NO_LEVEL;
            break;
    }
}

access Room::getAccessLevel() const {
    return access_level;
}
