//
// Created by Tony on 29.02.2024.
//

#ifndef DEVICESOOP_GAMINGMOUSE_H
#define DEVICESOOP_GAMINGMOUSE_H
#include "Mouse.h"
#include <iostream>

using namespace std;

class GamingMouse:public Mouse{
private:
    int AdditionalButtons;
    bool rgb;
public:
    int set_AdditionalButtons(int AdditionalButtons);
    int get_AdditionalButtons();
    bool set_rgb(bool rgb);
    bool get_rgb();
    void info();

    GamingMouse &operator=(const GamingMouse &other);

    GamingMouse(string name="None",float weight=0, string typeOfMaterial="None",bool wireless=false,int AAdditionalButtons=0,bool rgb=false);
    ~GamingMouse();

};


#endif //DEVICESOOP_GAMINGMOUSE_H