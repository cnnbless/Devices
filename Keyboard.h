//
// Created by Endi on 27.02.2024.
//

#ifndef DEVICESOOP_KEYBOARD_H
#define DEVICESOOP_KEYBOARD_H

#include "Printable.h"
#include <iostream>
using namespace std;
class Keyboard: public Printable {
private:
    int product_number;
    string name;
    float weight;
    string type_of_material;
    float price;
public:
    int set_product_number(int product_number);
    int get_product_number()const;
    string set_name(string name);
    string get_name()const;
    float set_weight(float weight);
    float get_weight()const;
    string set_typeOfMaterial(string type_of_material);
    string get_typeOfMaterial()const;
    float set_price(float price);
    float get_price()const;

    virtual void print(std::ostream &os) const override;
    virtual void readData(std::istream& is) override;
    virtual void writeProduct() override;
    Keyboard(const Keyboard &other);


    Keyboard(int product_number=0,string &&name="None", float weight=0, string &&type_of_material="None",float price=0);
    virtual ~Keyboard();
};
#endif //DEVICESOOP_KEYBOARD_H