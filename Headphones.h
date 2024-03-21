#ifndef DEVICESOOP_HEADPHONES_H
#define DEVICESOOP_HEADPHONES_H


#include <iostream>
#include "Printable.h"

using namespace std;
class Headphones: public Printable{
private:
    string name;
    float weight;
    string type_of_material;
    bool microphone;

public:
    string set_name(string name);
    string get_name();
    float set_weight(float weight);
    float get_weight();
    string set_TypeOfMaterial(string type_of_material);
    string get_TypeOfMaterial();
    bool set_microphone(bool microphone);
    bool get_microphone();
    void info();

    virtual void print_name_class()const;
    virtual void print(std::ostream &os) const override;
    virtual void print_class_name()const override;

    Headphones(string &&NameOfHeadphones="None", float Weight=0, string &&TypeOfMaterial="None", bool MICROPHONE=false);
    Headphones(const Headphones &&other)noexcept;
    virtual ~Headphones();
};



#endif //DEVICESOOP_HEADPHONES_H
