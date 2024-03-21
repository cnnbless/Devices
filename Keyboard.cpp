#include "Keyboard.h"
#include "Printable.h"
#include <iostream>

string Keyboard::set_name(string name)
{
    return this->name=name;
}
string Keyboard::get_name() const
{
    return name;
}
string Keyboard::set_TypeOfMaterial(string typeOfMaterial)
{

    return type_of_material=typeOfMaterial;
}
string Keyboard::get_TypeOfMaterial() const
{
    return type_of_material;
}
float Keyboard::set_weight(float weight)
{
    return this->weight=weight;
}
float Keyboard::get_weight() const
{
    return weight;
}
void Keyboard::info() const
{
    cout<<"INFO: "<<endl
        <<"Назва клавіатури: "<<name
        <<"\nВага клавіатури: "<<weight<<" кг"
        <<"\nТип матеріалу клавіатури: "<<type_of_material<<endl;
}

void Keyboard::doSomething() const
{
    cout<<"Keyboard"<<endl;
}

void Keyboard::print(std::ostream &os) const {
    os<<"INFO: "<<endl
      <<"Назва клавіатури: "<<name
      <<"\nВага клавіатури: "<<weight<<" кг"
      <<"\nТип матеріалу клавіатури: "<<type_of_material<<endl;
}

void Keyboard::print_class_name() const {
    cout<<"Class name: Keyboard"<<endl;
}

Keyboard::Keyboard()
{
    name="None";
    weight=0;
    type_of_material="None";
    cout<<"called Keyboard constructor"<<endl;
}
Keyboard::Keyboard(std::string &&name)
{
    this->name=name;
    weight=0;
    type_of_material="None";
    cout<<"called Keyboard constructor"<<endl;
}
Keyboard::Keyboard(std::string &&name, float weight)
{
    this->name=name;
    this->weight=weight;
    type_of_material="None";
    cout<<"called Keyboard constructor"<<endl;
}
Keyboard::Keyboard(std::string &&name, float weight, std::string &&type_of_material)
{
    this->name=name;
    this->weight=weight;
    this->type_of_material=type_of_material;
    cout<<"called Keyboard constructor"<<endl;
}
Keyboard::Keyboard(const Keyboard &other) {
    name = other.name;
    weight = other.weight;
    type_of_material = other.type_of_material;
    cout<<"called copy constructor"<<endl;
}
Keyboard::~Keyboard()
{
    cout<<"called Keyboard destructor"<<endl;
}