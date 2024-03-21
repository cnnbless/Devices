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

void MechanicKeyboard::doSomething() const{
    cout<<"MechanicKeyboard"<<endl;
}

void MechanicKeyboard::print(std::ostream &os) const {
    Keyboard::print(os);
    os<<"Колір клавіатури: "<<colorOfKeyboard<<endl;
}

void MechanicKeyboard::print_class_name() const {
    cout<<"Class name: MechanicKeyboard"<<endl;
}

MechanicKeyboard::MechanicKeyboard(string name, float weight, string typeOfMaterial,string &&colorOfKeyboard):
        Keyboard{string{name},float{weight},string{typeOfMaterial}}{
    this->colorOfKeyboard=colorOfKeyboard;
    cout<<"MechanicKeyboard constructor"<<endl;
}
MechanicKeyboard::MechanicKeyboard(const MechanicKeyboard &other):Keyboard(other), colorOfKeyboard(other.colorOfKeyboard){
    cout<<"MechanicKeyboard copy"<<endl;
}
MechanicKeyboard::~MechanicKeyboard() {
    cout<<"called MechanicKeyboard destructor"<<endl;
}