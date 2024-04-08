//
// Created by Endi on 27.02.2024.
//

#include "Headphones.h"
#include <iostream>
#include <fstream>
using namespace std;
int Headphones::set_product_number(int product_number) {
    return this->product_number=product_number;
}
int Headphones::get_product_number() const {
    return product_number;
}
string Headphones::set_name(string name)
{
    return this->name = name;
}
string Headphones::get_name()const
{
    return name;
}
float Headphones::set_weight(float weight)
{
    return this->weight=weight;
}
float Headphones::get_weight()const
{
    return weight;
}
string Headphones::set_TypeOfMaterial(string type_of_material)
{
    return this->type_of_material=type_of_material;
}
string Headphones::get_TypeOfMaterial()const
{
    return type_of_material;
}
bool Headphones::set_microphone(bool microphone)
{
    return this->microphone=microphone;
}
bool Headphones::get_microphone()const
{
    return microphone;
}
float Headphones::set_price(float price) {
    return this->price=price;
}
float Headphones::get_price() const {
    return price;
}

void Headphones::writeProduct() {
    ofstream file("C:\\Users\\Tony\\CLionProjects\\Devices\\files\\Products.txt", ios::app);
    string data=to_string(product_number)+","+name+","+ to_string(weight)+","+type_of_material+","+to_string(price)+",";
    if(microphone){
        data=data+"1";
    }
    else{
        data+="0";
    }
    file<<data;
    file.close();
}

void Headphones::print(std::ostream &os) const {
    os<<endl<<"---Товар: Наушники---"<<endl
      <<"Номер товару: "<<product_number<<endl
      <<"Назва: "<<name<<endl
      <<"Вага: "<<weight<<endl
      <<"Матеріал: "<<type_of_material<<endl;
    if(microphone){os<<"Наявність мікрофона: +"<<endl;}
    else{os<<"Наявність мікрофона: -"<<endl;}
    os<<"Ціна: "<<price<<endl;
}

void Headphones::readData(std::istream &is) {
    cout<<"Введіть номер товару: ";
    is >> product_number;
    cout<<"Введіть назву наушників: ";
    is >> name;
    cout<<"Введіть вагу наушників: ";
    is >> weight;
    cout<<"Введіть матеріал наушників: ";
    is >> type_of_material;
    cout << "Введіть чи є мікрофон (1-так, 0-ні): ";
    is >> microphone;
    cout<<"Введіть ціну наушників: ";
    is >> price;
}

Headphones::Headphones(const Headphones &&other) noexcept{
    product_number=other.product_number;
    name=move(other.name);
    weight=other.weight;
    type_of_material=move(other.type_of_material);
    microphone=other.microphone;
    price=other.price;
    cout<<"Headphones move constructor"<<endl;
}

Headphones::Headphones(int product_number, std::string &&name, float weight, std::string &&type_of_material,
                       float price, bool microphone):
        product_number{product_number},name{name}, weight{weight}, type_of_material{type_of_material}
        ,microphone{microphone},price{price}
{
    //cout<<"called Headphones constructor"<<endl;
}

Headphones::~Headphones(){
    //cout<<"called Headphones destructor"<<endl;
}