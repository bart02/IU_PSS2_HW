//
// Created by Artem Batalov on 24.03.2021.
//

#ifndef HW3_ALARM_H
#define HW3_ALARM_H


class Alarm {
    bool status;

public:
    Alarm();
    void on();
    void off();
    bool isEmergency() const;
};


#endif //HW3_ALARM_H
