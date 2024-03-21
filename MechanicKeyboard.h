//
// Created by Tony on 06.03.2024.
//

#ifndef DEVICESOOP_MECHANICKEYBOARD_H
#define DEVICESOOP_MECHANICKEYBOARD_H
#include "Keyboard.h"
#include <iostream>

using namespace std;

class MechanicKeyboard: public Keyboard{
private:
    string colorOfKeyboard;
public:
    string set_colorOfKeyboard(string &&colorOfKeyboard);
    string get_colorOfKeyboard();
    void info();

    void doSomething()const;

    void print(std::ostream &os) const override;
    void print_class_name()const override;

    MechanicKeyboard(string name="None",float weight=0, string typeOfMaterial="None",string &&colorOfKeyboard="None");
    MechanicKeyboard(const MechanicKeyboard &other);
    ~MechanicKeyboard() override;

};


#endif //DEVICESOOP_MECHANICKEYBOARD_H