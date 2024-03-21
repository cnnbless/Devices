//
// Created by Endi on 27.02.2024.
//

#ifndef DEVICESOOP_MOUSE_H
#define DEVICESOOP_MOUSE_H

#include "Printable.h"
#include <iostream>

using namespace std;
class Mouse: public Printable{

private:
    string name;
    float weight;
    string type_of_material;
    bool wireless;
    static int AmountOfMice;

public:
    string set_name(string name);
    string get_name();
    float set_weight(float weight);
    float get_weight();
    string set_TypeOfMaterial(string typeOfMaterial);
    string get_TypeOfMaterial();
    bool set_wireless(bool wireless);
    bool get_wireless();
    virtual void info();
    int get_amountOfMice();

    virtual void doSomething()const;
    virtual void Click()const final;

    virtual void print(std::ostream &os) const override;
    virtual void print_class_name()const override;

//    friend std::ostream  &operator<<(std::ostream &os, const Mouse &mouse);
    friend std::istream &operator>>(std::istream &is, Mouse &mouse);

    Mouse &operator=(const Mouse &other);
    Mouse operator+(float num);
    Mouse operator-(float num);
    Mouse operator+=(float num);
    Mouse operator-=(float num);

    Mouse operator--();
    Mouse operator++();

    Mouse();
    Mouse(string NameOfMouse);
    Mouse(string NameOfMouse, float Weight);
    Mouse(string NameOfMouse, float Weight, string TypeOfMaterial);
    Mouse(string NameOfMouse, float Weight, string TypeOfMaterial, bool Wireless);
    virtual ~Mouse();
};


#endif //DEVICESOOP_MOUSE_H