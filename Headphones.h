//
// Created by Tony on 06.03.2024.
//

#ifndef DEVICESOOP_HEADPHONES_H
#define DEVICESOOP_HEADPHONES_H


#include <iostream>

using namespace std;
class Headphones {
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

    Headphones(string &&NameOfHeadphones="None", float Weight=0, string &&TypeOfMaterial="None", bool MICROPHONE=false);
    Headphones(const Headphones &&other)noexcept;
    ~Headphones();
};



#endif //DEVICESOOP_HEADPHONES_H
