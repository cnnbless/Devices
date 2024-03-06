//
// Created by Tony on 06.03.2024.
//

#include "GamingMouse.h"
#include "Mouse.h"
#include <iostream>

int GamingMouse::set_AdditionalButtons(int AdditionalButtons) {
    return this->AdditionalButtons=AdditionalButtons;
}
int GamingMouse::get_AdditionalButtons() {
    return AdditionalButtons;
}
bool GamingMouse::set_rgb(bool rgb) {
    return this->rgb=rgb;
}
bool GamingMouse::get_rgb() {
    return rgb;
}
void GamingMouse::info() {
    Mouse::info();
    cout<<"Кількість додаткових кнопок: "<<AdditionalButtons<<endl;
    cout<<"RGB підсвітка: "<<rgb<<endl;
}

GamingMouse &GamingMouse::operator=(const GamingMouse &other) {
    if(this!=&other){
        Mouse::operator=(other);
        AdditionalButtons=other.AdditionalButtons;
        rgb=other.rgb;
    }
    return *this;
}

GamingMouse::GamingMouse(std::string name, float weight, std::string typeOfMaterial, bool wireless,int AAdditionalButtons, bool rgb)
{
    Mouse::set_name(name);
    Mouse::set_weight(weight);
    Mouse::set_TypeOfMaterial(typeOfMaterial);
    Mouse::set_wireless(wireless);
    this->AdditionalButtons=AAdditionalButtons;
    this->rgb=rgb;
    cout<<"GamingMouse constructor"<<endl;
}
GamingMouse::~GamingMouse() {
    cout<<"GamingMouse destructor"<<endl;
}