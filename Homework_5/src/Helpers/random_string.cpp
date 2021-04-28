//
// Created by Artem Batalov on 11.04.2021.
//

#include "random_string.h"

std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

void print_logo() {
    std::cout << R"(
    $$\      $$\ $$$$$$$$\                 $$\                         $$$$$$$$\                     $$\
    $$ | $\  $$ |$$  _____|                $$ |                        \__$$  __|                    \__|
    $$ |$$$\ $$ |$$ |      $$$$$$$\   $$$$$$$ | $$$$$$\  $$\   $$\        $$ |    $$$$$$\  $$\   $$\ $$\
    $$ $$ $$\$$ |$$$$$\    $$  __$$\ $$  __$$ |$$  __$$\ \$$\ $$  |       $$ |    \____$$\ \$$\ $$  |$$ |
    $$$$  _$$$$ |$$  __|   $$ |  $$ |$$ /  $$ |$$$$$$$$ | \$$$$  /        $$ |    $$$$$$$ | \$$$$  / $$ |
    $$$  / \$$$ |$$ |      $$ |  $$ |$$ |  $$ |$$   ____| $$  $$<         $$ |   $$  __$$ | $$  $$<  $$ |
    $$  /   \$$ |$$$$$$$$\ $$ |  $$ |\$$$$$$$ |\$$$$$$$\ $$  /\$$\ $$\    $$ |   \$$$$$$$ |$$  /\$$\ $$ |
    \__/     \__|\________|\__|  \__| \_______| \_______|\__/  \__|\__|   \__|    \_______|\__/  \__|\__|

)" << std::endl;
}
