//
// Created by Tony on 06.03.2024.
//


#ifndef DEVICESOOP_KEYBOARD_H
#define DEVICESOOP_KEYBOARD_H

#include "Printable.h"
#include <iostream>
using namespace std;
class Keyboard: public Printable {
private:
    string name;
    float weight;
    string type_of_material;
public:
    string set_name(string name);
    string get_name()const ;
    string set_TypeOfMaterial(string typeOfMaterial);
    string get_TypeOfMaterial()const ;
    float set_weight(float weight);
    float get_weight()const ;
    void info()const;

    void doSomething()const;

    virtual void print(std::ostream &os) const override;
    virtual void print_class_name()const override;

    Keyboard();
    Keyboard(string &&name);
    Keyboard(string &&name, float weight);
    Keyboard(string &&name, float weight, string &&type_of_material);
    Keyboard(const Keyboard &other);
    virtual ~Keyboard();
};

#endif //DEVICESOOP_KEYBOARD_H