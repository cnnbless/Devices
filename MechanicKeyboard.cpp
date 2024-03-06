//
// Created by Tony on 06.03.2024.
//

#include "MechanicKeyboard.h"

#include "Keyboard.h"

using namespace std;

string MechanicKeyboard::set_colorOfKeyboard(std::string &&colorOfKeyboard) {
    return this->colorOfKeyboard=colorOfKeyboard;
}
string MechanicKeyboard::get_colorOfKeyboard() {
    return colorOfKeyboard;
}
void MechanicKeyboard::info() {
    Keyboard::info();
    cout<<"Колір клавіатури: "<<colorOfKeyboard<<endl;
}

MechanicKeyboard::MechanicKeyboard(string name, float weight, string typeOfMaterial,string &&colorOfKeyboard){
    Keyboard::set_name(name);
    Keyboard::set_weight(weight);
    Keyboard::set_TypeOfMaterial(typeOfMaterial);
    this->colorOfKeyboard=colorOfKeyboard;
    cout<<"MechanicKeyboard constructor"<<endl;
}
MechanicKeyboard::MechanicKeyboard(const MechanicKeyboard &other):Keyboard(other), colorOfKeyboard(other.colorOfKeyboard){
    cout<<"MechanicKeyboard copy"<<endl;
}
MechanicKeyboard::~MechanicKeyboard() {
    cout<<"called MechanicKeyboard destructor"<<endl;
}