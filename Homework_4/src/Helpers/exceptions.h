//
// Created by Artem Batalov on 11.04.2021.
//

#ifndef HOMEWORK_4_EXCEPTIONS_H
#define HOMEWORK_4_EXCEPTIONS_H

#include <string>
#include <exception>

using namespace std;

class LoginBusy: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "This login is busy";
    }
};

class LoginOrPasswordIncorrect: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Login or password is incorrect";
    }
};

class NoDrivers: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "There are not any available drivers";
    }
};

class DriverIsOfflineOrBusy: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Driver is offline or busy";
    }
};

class OrderAlreadyInProgress: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Order already ..."; // TODO
    }
};

class NoOrders: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "No orders";
    }
};

#endif //HOMEWORK_4_EXCEPTIONS_H
