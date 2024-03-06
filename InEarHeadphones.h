//
// Created by Tony on 06.03.2024.
//


#ifndef DEVICESOOP_INEARHEADPHONES_H
#define DEVICESOOP_INEARHEADPHONES_H

#include "Headphones.h"
#include <iostream>

using namespace std;

class InEarHeadphones: public Headphones{
private:
    bool wired;
public:
    bool set_wired(bool wired);
    bool get_wired();
    void info();
    InEarHeadphones(string name="None",float weight=0, string typeOfMaterial="None",bool microphone=false,bool wired= false);
    InEarHeadphones(InEarHeadphones&& other)noexcept;
    ~InEarHeadphones();

};


#endif //DEVICESOOP_INEARHEADPHONES_H