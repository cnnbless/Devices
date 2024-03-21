//
// Created by Tony on 06.03.2024.
//
//
// Created by Endi on 27.02.2024.
//

#include "Headphones.h"
#include <iostream>
using namespace std;
string Headphones::set_name(string name)
{
    return this->name = name;
}
string Headphones::get_name()
{
    return name;
}
float Headphones::set_weight(float weight)
{
    return this->weight=weight;
}
float Headphones::get_weight()
{
    return weight;
}
string Headphones::set_TypeOfMaterial(string type_of_material)
{
    return this->type_of_material=type_of_material;
}
string Headphones::get_TypeOfMaterial()
{
    return type_of_material;
}
bool Headphones::set_microphone(bool microphone)
{
    return this->microphone=microphone;
}
bool Headphones::get_microphone()
{
    return microphone;
}
void Headphones::info()
{
    cout<<"INFO: "<<endl
        <<"Назва наушників: "<<name
        <<"\nВага наушників: "<<weight<<" кг"
        <<"\nТип наушників наушників: "<<type_of_material
        <<"\nНаушники з мікрофоном: "<<microphone<<endl;
}


void Headphones::print_name_class() const {
    cout<<"Headphones"<<endl;
}

void Headphones::print(std::ostream &os) const {
    os<<"INFO: "<<endl
      <<"Назва наушників: "<<name
      <<"\nВага наушників: "<<weight<<" кг"
      <<"\nТип наушників наушників: "<<type_of_material
      <<"\nНаушники з мікрофоном: "<<microphone<<endl;
}

void Headphones::print_class_name() const {
    cout<<"Class name: Headphones"<<endl;
}

Headphones::Headphones(std::string &&NameOfKeyboard, float Weight, std::string &&TypeOfMaterial, bool MICROPHONE):
        name{NameOfKeyboard}, weight(Weight), type_of_material(TypeOfMaterial), microphone(MICROPHONE)
{
    cout<<"called Headphones constructor"<<endl;
}
Headphones::Headphones(const Headphones &&other) noexcept{
    name=move(other.name);
    weight=other.weight;
    type_of_material=move(other.type_of_material);
    microphone=other.microphone;
    cout<<"Headphones move constructor"<<endl;
}
Headphones::~Headphones(){
    cout<<"called Headphones destructor"<<endl;
}