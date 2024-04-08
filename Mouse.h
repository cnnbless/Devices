//
// Created by Endi on 27.02.2024.
//

#ifndef DEVICESOOP_MOUSE_H
#define DEVICESOOP_MOUSE_H

#include "Printable.h"
#include <iostream>
using namespace std;
class Mouse: public Printable{

private:
    int product_number;
    string name;
    float weight;
    string type_of_material;
    bool wireless;
    float price;

public:
    int set_product_number(int product_number);
    int get_product_number()const;
    string set_name(string name);
    string get_name()const;
    float set_weight(float weight);
    float get_weight()const;
    string set_TypeOfMaterial(string typeOfMaterial);
    string get_TypeOfMaterial()const;
    bool set_wireless(bool wireless);
    bool get_wireless()const;
    float set_price(float price);
    float get_price()const;

    virtual void print(std::ostream &os) const override;
    virtual void readData(std::istream& is) override;
    virtual void writeProduct() override;
    Mouse &operator=(const Mouse &other);

    Mouse(int product_number=0,string &&name="None", float weight=0, string &&type_of_material="None",float price=0
            , bool wireless=false);
    virtual ~Mouse();
};


#endif //DEVICESOOP_MOUSE_H