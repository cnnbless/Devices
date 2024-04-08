//
// Created by Endi on 27.02.2024.
//

#ifndef DEVICESOOP_HEADPHONES_H
#define DEVICESOOP_HEADPHONES_H


#include <iostream>
#include "Printable.h"

using namespace std;
class Headphones: public Printable{
private:
    int product_number;
    string name;
    float weight;
    string type_of_material;
    bool microphone;
    float price;

public:
    int set_product_number(int product_number);
    int get_product_number()const;
    string set_name(string name);
    string get_name()const;
    float set_weight(float weight);
    float get_weight()const;
    string set_TypeOfMaterial(string type_of_material);
    string get_TypeOfMaterial()const;
    bool set_microphone(bool microphone);
    bool get_microphone()const;
    float set_price(float price);
    float get_price()const;

    virtual void print(std::ostream &os) const override;
    virtual void readData(std::istream& is) override;
    virtual void writeProduct() override;
    Headphones(const Headphones &&other)noexcept;

    Headphones(int product_number=0,string &&name="None", float weight=0, string &&type_of_material="None"
            ,float price=0, bool microphone= false);
    virtual ~Headphones();
};



#endif //DEVICESOOP_HEADPHONES_H