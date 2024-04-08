//
// Created by Endi on 29.02.2024.
//

#include "InEarHeadphones.h"
#include "Headphones.h"
#include <iostream>
#include <fstream>

bool InEarHeadphones::set_wired(bool wired) {
    return this->wired=wired;
}
bool InEarHeadphones::get_wired()const{
    return wired;
}

void InEarHeadphones::writeProduct() {
    Headphones::writeProduct();
    ofstream file("C:\\Users\\Tony\\CLionProjects\\Devices\\files\\Products.txt", ios::app);
    string data=",";
    if(wired){
        data+="1";
    }
    else{
        data+="0";
    }
    file<<data;
    file.close();
}

void InEarHeadphones::print(std::ostream &os) const {
    os<<endl<<"---Товар: Наушники-затички---"<<endl
      <<"Номер товару: "<<Headphones::get_product_number()<<endl
      <<"Назва: "<<Headphones::get_name()<<endl
      <<"Вага: "<<Headphones::get_weight()<<endl
      <<"Матеріал: "<<Headphones::get_TypeOfMaterial()<<endl;
    if(Headphones::get_microphone()){os<<"Наявність мікрофона: +"<<endl;}
    else{os<<"Наявність мікрофона: -"<<endl;}
    if(wired){os<<"Провідні: +"<<endl;}
    else{os<<"Провідні: -"<<endl;}
    os<<"Ціна: "<<Headphones::get_price()<<endl;
}

void InEarHeadphones::readData(std::istream &is) {
    Headphones::readData(is);
    cout<<"Введіть чи наушники провідні (1-так, 0-ні): ";
    is >> wired;
}

InEarHeadphones::InEarHeadphones(InEarHeadphones &&other)noexcept: Headphones(std::move(other)), wired(other.wired) {
    cout<<"InEarHeadphones move constuctor"<<endl;
}

InEarHeadphones::InEarHeadphones(int product_number, std::string &&name, float weight, std::string &&type_of_material,
                                 float price, bool microphone, bool wired): Headphones{int{product_number}
        ,string{name},float{weight}
        ,string{type_of_material},float{price}, bool{microphone}}
{
    this->wired=wired;
    //cout<<"InEarHeadphones constructor"<<endl;
}

InEarHeadphones::~InEarHeadphones() {
    //cout<<"InEarHeadphones destructor"<<endl;
}