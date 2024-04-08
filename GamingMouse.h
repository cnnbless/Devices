//
// Created by Endi on 29.02.2024.
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

    void print(std::ostream &os) const override;
    void readData(std::istream& is) override;
    void writeProduct() override;
    GamingMouse &operator=(const GamingMouse &other);

    GamingMouse(int product_number=0,string &&name="None", float weight=0, string &&type_of_material="None"
            ,float price=0, bool wireless=false,int AAdditionalButtons=0,bool rgb=false);
    ~GamingMouse() override;

};


#endif //DEVICESOOP_GAMINGMOUSE_H