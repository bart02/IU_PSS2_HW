//
// Created by Artem Batalov on 11.04.2021.
//

#ifndef HOMEWORK_5_BACKEND_H
#define HOMEWORK_5_BACKEND_H

#include <string>
using namespace std;

class Backend {
public:
    static int calculate_sum(const string &from, const string &to, int clas);
    static void update_geo();
};


#endif //HOMEWORK_5_BACKEND_H
