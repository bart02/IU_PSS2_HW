# Programming Software Systems 2
## Homework3
### Requirements
C++14
gcc
cmake

### Compile and run
UNIX:
```bash
mkdir build
cd build
cmake ..
make
./HW3
```

### What this program do?
#### Create room of several types
```cpp
rooms.push_back(new Room("313", CLASS_ROOM));
```

#### Create user of several types
Each type has his own feature (joke, car, etc.), see more below.
```cpp
vector_users.push_back(new Student("Artem Batalov", 20000));
```

#### Admins can grant access to any room
```cpp
(dynamic_cast<Admin*>(users[15])) -> grantAccess(rooms[1], users[0]);
```

### Fire alarm
This program has Alarm that could open each room in case of emergency.

### Types of rooms
`CLASS_ROOM`, `LECTURE_ROOM`, `CONFERENCE_ROOM`, `CABINET`, `DIRECTOR_CABINET`

### Types of users
#### Guest
He/she can participate in some event.

#### Student
You can set amount of his/her stipa.

#### Professor
You can set his/her joke.

#### Lab Employee
You can set his/her lab.

#### Director
You can buy a car for him.

#### Admin
Just love him/her.
