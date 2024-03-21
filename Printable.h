//
// Created by Tony on 21.03.2024.
//
#ifndef DEVICESOOP_PRINTABLE_H
#define DEVICESOOP_PRINTABLE_H

#include <iostream>

using namespace std;

class Printable {
    friend ostream &operator<<(ostream &os, const Printable &obj);

public:
    virtual void print(ostream &os) const = 0;
    virtual ~Printable() {};
    virtual void print_class_name()const=0;
};




#endif //DEVICESOOP_PRINTABLE_H