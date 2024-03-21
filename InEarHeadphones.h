//
// Created by Endi on 29.02.2024.
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

    void print_name_class() const override;
    void print(std::ostream &os) const override;
    void print_class_name()const override;

    InEarHeadphones(string name="None",float weight=0, string typeOfMaterial="None",bool microphone=false,bool wired= false);
    InEarHeadphones(InEarHeadphones&& other)noexcept;
    ~InEarHeadphones() override;

};


#endif //DEVICESOOP_INEARHEADPHONES_H