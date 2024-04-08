//
// Created by Endi on 27.02.2024.
//

#include "Mouse.h"
#include <iostream>
#include <fstream>
int Mouse::set_product_number(int product_number) {
    return this->product_number=product_number;
}
int Mouse::get_product_number() const {
    return product_number;
}
string Mouse::set_name(string name)
{
    return this->name=name;
}
string Mouse::get_name()const
{
    return name;
}
float Mouse::set_weight(float weight)
{
    return this->weight=weight;
}
float Mouse::get_weight()const
{
    return weight;
}
string Mouse::set_TypeOfMaterial(string typeOfMaterial)
{
    return type_of_material=typeOfMaterial;
}
string Mouse::get_TypeOfMaterial()const
{
    return type_of_material;
}
bool Mouse::set_wireless(bool wireless)
{
    return this->wireless=wireless;
}
bool Mouse::get_wireless()const
{
    return wireless;
}
float Mouse::set_price(float price) {
    return this->price=price;
}
float Mouse::get_price() const {
    return price;
}

void Mouse::writeProduct() {
    ofstream file("C:\\Users\\Tony\\CLionProjects\\Devices\\files\\Products.txt", ios::app);
    string data=to_string(product_number)+","+name+","+ to_string(weight)+","+type_of_material+","+to_string(price)+",";
    if(wireless){
        data=data+"1";
    }
    else{
        data+="0";
    }
    file<<data;
    file.close();
}

void Mouse::print(std::ostream &os) const {
    os<<endl<<"---Товар: Мишка---"<<endl
      <<"Номер товару: "<<product_number<<endl
      <<"Назва: "<<name<<endl
      <<"Вага: "<<weight<<endl
      <<"Матеріал: "<<type_of_material<<endl;
    if(wireless){os<<"Провідна: +"<<endl;}
    else{os<<"Провідна: -"<<endl;}
    os<<"Ціна: "<<price<<endl;
}

void Mouse::readData(std::istream &is) {
    cout << "Введіть номер товару: ";
    is >> product_number;
    cout << "Введіть назву мишки: ";
    is >> name;
    cout << "Введіть вагу мишки: ";
    is >> weight;
    cout << "Введіть матеріал кмишки: ";
    is >> type_of_material;
    cout << "Введіть чи мишка провідна (1-так, 0-ні): ";
    is >> wireless;
    cout << "Введіть ціну кмишки: ";
    is >> price;
}

Mouse &Mouse::operator=(const Mouse &other){
    if(this!=&other){
        product_number=other.product_number;
        name=other.name;
        weight=other.weight;
        type_of_material=other.type_of_material;
        wireless=other.wireless;
        price=other.price;
    }
    return  *this;
}


Mouse::Mouse(int product_number, std::string &&name, float weight, std::string &&type_of_material, float price,
             bool wireless):product_number{product_number},name{name},weight{weight},type_of_material{type_of_material}
        ,price{price},wireless{wireless}
{
    //cout<<"called Mouse constructor"<<endl;
}

Mouse::~Mouse() {
    //cout<<"called Mouse destructor"<<endl;
}