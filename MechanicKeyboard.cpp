//
// Created by Endi on 29.02.2024.
//

#include "MechanicKeyboard.h"
#include "Keyboard.h"
#include <fstream>
using namespace std;

string MechanicKeyboard::set_colorOfKeyboard(string &&colorOfKeyboard) {
    return this->colorOfKeyboard=colorOfKeyboard;
}
string MechanicKeyboard::get_colorOfKeyboard()const {
    return colorOfKeyboard;
}

void MechanicKeyboard::writeProduct() {
    Keyboard::writeProduct();
    ofstream file("C:\\Users\\Tony\\CLionProjects\\Devices\\files\\Products.txt", ios::app);
    string data=","+colorOfKeyboard;
    file<<data;
    file.close();
}

void MechanicKeyboard::print(std::ostream &os) const {
    os<<endl<<"---Товар: Механічна клавіатура---"<<endl
      <<"Номер товару: "<<Keyboard::get_product_number()<<endl
      <<"Назва: "<<Keyboard::get_name()<<endl
      <<"Вага: "<<Keyboard::get_weight()<<endl
      <<"Матеріал: "<<Keyboard::get_typeOfMaterial()<<endl
      <<"Колір: "<<colorOfKeyboard<<endl
      <<"Ціна: "<<Keyboard::get_price()<<endl;
}

void MechanicKeyboard::readData(std::istream &is) {
    Keyboard::readData(is);
    cout<<"Введіть колір клавіатури: ";
    is >> colorOfKeyboard;
}

MechanicKeyboard::MechanicKeyboard(const MechanicKeyboard &other):Keyboard(other)
        , colorOfKeyboard(other.colorOfKeyboard)
{
    cout<<"MechanicKeyboard copy"<<endl;
}

MechanicKeyboard::MechanicKeyboard(int product_number, string &&name, float weight, string &&type_of_material,
                                   float price, string &&colorOfKeyboard):
        Keyboard{int{product_number},string{name},float{weight}
                ,string{type_of_material},float{price}}
{
    this->colorOfKeyboard=colorOfKeyboard;
    //cout<<"called MechanicKeyboard constructor"<<endl;
}
MechanicKeyboard::~MechanicKeyboard() {
    //cout<<"called MechanicKeyboard destructor"<<endl;
}