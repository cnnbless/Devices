//
// Created by Endi on 27.02.2024.
//

#include "Mouse.h"
#include <iostream>
int Mouse::AmountOfMice=0;

string Mouse::set_name(string name)
{

    return this->name=name;
}
string Mouse::get_name()
{
    return name;
}
float Mouse::set_weight(float weight)
{
    return this->weight=weight;
}
float Mouse::get_weight()
{
    return weight;
}
string Mouse::set_TypeOfMaterial(string typeOfMaterial)
{
    return type_of_material=typeOfMaterial;
}
string Mouse::get_TypeOfMaterial()
{
    return type_of_material;
}
bool Mouse::set_wireless(bool wireless)
{
    return this->wireless=wireless;
}
bool Mouse::get_wireless()
{
    return wireless;
}
void Mouse::info()
{
    cout<<"INFO: "<<endl
        <<"Назва мишки: "<<name
        <<"\nВага мишки: "<<weight<<" кг"
        <<"\nТип матеріалу мишки: "<<type_of_material
        <<"\nМишка провідна: "<<wireless<<endl;
}

int Mouse::get_amountOfMice() {
    return AmountOfMice;
}

std::ostream &operator<<(std::ostream &os, const Mouse &mouse) {
    os << "Назва мишки: " <<mouse.name  << endl;
    os << "Вага мишки: " <<mouse.weight  << endl;
    os << "Тип матеріалу мишки: "<< mouse.type_of_material<<endl;
    os << "Провідна: "<<mouse.wireless<<endl;
    return os;
}
std::istream &operator>>(std::istream &is, Mouse &mouse) {
    cout<<"Введіть назву мишки: ";
    is >> mouse.name;
    cout<<"Введіть вагу мишки: ";
    is >> mouse.weight;
    cout<<"Введіть тип матеріалу мишки: ";
    is >> mouse.type_of_material;
    cout<<"Провідна true/false: ";
    is >> mouse.wireless;
    return is;
}
Mouse &Mouse::operator=(const Mouse &other){
    if(this!=&other){
        name=other.name;
        weight=other.weight;
        type_of_material=other.type_of_material;
        wireless=other.wireless;
    }
    return  *this;
}
Mouse Mouse::operator+(float num) {
    weight+=num;
    return *this;
}
Mouse Mouse::operator-(float num) {
    if(weight<0.1){
        weight=0;
        return *this;
    }
    weight-=num;
    return *this;
}
Mouse Mouse::operator+=(float num) {
    weight+=num;
    return *this;
}
Mouse Mouse::operator-=(float num) {
    if(weight<0.1){
        weight=0;
        return *this;
    }
    weight-=num;
    return *this;
}
Mouse Mouse::operator--(){
    if(weight<0.1){
        weight=0;
        return *this;
    }
    weight-=0.100;
    return *this;
}
Mouse Mouse::operator++() {
    weight+=0.100;
    return *this;
}
Mouse::Mouse()
{
    AmountOfMice++;
    name="None";
    weight=0;
    type_of_material="None";
    wireless= false;
    cout<<"called Mouse constructor"<<endl;
}
Mouse::Mouse(std::string NameOfMouse): Mouse()
{
    name=NameOfMouse;

}
Mouse::Mouse(std::string NameOfMouse, float Weight):Mouse(NameOfMouse)
{
    weight=Weight;
}
Mouse::Mouse(std::string NameOfMouse, float Weight, std::string NameTypeOfMaterial):Mouse(NameOfMouse,  Weight) {
    type_of_material=NameTypeOfMaterial;
}
Mouse::Mouse(std::string NameOfMouse, float Weight, std::string NameTypeOfMaterial, bool Wireless):Mouse(NameOfMouse,  Weight,  NameTypeOfMaterial) {
    wireless=Wireless;
}
Mouse::~Mouse() {
    AmountOfMice--;
    cout<<"called Mouse destructor"<<endl;
}