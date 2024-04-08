#include "GamingMouse.h"
#include "Mouse.h"
#include <iostream>
#include <fstream>

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

void GamingMouse::writeProduct() {
    Mouse::writeProduct();
    ofstream file("C:\\Users\\Tony\\CLionProjects\\Devices\\files\\Products.txt", ios::app);
    string data=","+ to_string(AdditionalButtons)+",";
    if(rgb){
        data+="1";
    }
    else{
        data+="0";
    }
    file<<data;
    file.close();
}

void GamingMouse::print(std::ostream &os) const {
    os<<endl<<"---Товар: Геймерська мишка---"<<endl
      <<"Номер товару: "<<Mouse::get_product_number()<<endl
      <<"Назва: "<<Mouse::get_name()<<endl
      <<"Вага: "<<Mouse::get_weight()<<endl
      <<"Матеріал: "<<Mouse::get_TypeOfMaterial()<<endl;
    if(Mouse::get_wireless()){os<<"Провідна: +"<<endl;}
    else{os<<"Провідна: -"<<endl;}
    os<<"Кількість додаткових кнопок: "<<AdditionalButtons<<endl;
    os<<"Підсвітка: ";
    if (rgb){os<<"+";}
    else {os<<"-";}
    os<<endl<<"Ціна: "<<Mouse::get_price()<<endl;
}

void GamingMouse::readData(std::istream &is) {
    Mouse::readData(is);
    cout<<"Введіть кількість додаткових кнопок: ";
    is >> AdditionalButtons;
    cout<<"Введіть чи є підсвітка (1-так, 0-ні): ";
    is >> rgb;
}

GamingMouse &GamingMouse::operator=(const GamingMouse &other) {
    if(this!=&other){
        Mouse::operator=(other);
        AdditionalButtons=other.AdditionalButtons;
        rgb=other.rgb;
    }
    return *this;
}

GamingMouse::GamingMouse(int product_number, std::string &&name, float weight, std::string &&type_of_material,
                         float price, bool wireless, int AAdditionalButtons, bool rgb):
        Mouse{int{product_number},string{name},float{weight}
                ,string{type_of_material},float{price}, bool{wireless}}
{
    this->AdditionalButtons=AAdditionalButtons;
    this->rgb=rgb;
    //cout<<"GamingMouse constructor"<<endl;
}

GamingMouse::~GamingMouse() {
    //cout<<"GamingMouse destructor"<<endl;
}