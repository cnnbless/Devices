//
// Created by Endi on 14.03.2024.
//

#ifndef DEVICESOOP_PRINTABLE_H
#define DEVICESOOP_PRINTABLE_H

#include <iostream>

using namespace std;

class Printable {
    friend ostream &operator<<(ostream &os, const Printable &obj);
    friend std::istream &operator>>(istream &is, Printable &obj);

public:
    virtual void print(ostream &os) const = 0;
    virtual void readData(std::istream &is) = 0;
    virtual void writeProduct()=0;
    virtual ~Printable() {};
};

#endif //DEVICESOOP_PRINTABLE_H