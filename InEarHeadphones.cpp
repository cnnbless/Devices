//
// Created by Tony on 06.03.2024.
//

#include "InEarHeadphones.h"
#include "Headphones.h"
#include <iostream>

bool InEarHeadphones::set_wired(bool wired) {
    return this->wired=wired;
}
bool InEarHeadphones::get_wired() {
    return wired;
}
void InEarHeadphones::info() {
    Headphones::info();
    cout<<"Провідні наушники: "<<wired<<endl;
}
InEarHeadphones::InEarHeadphones(std::string name, float weight, std::string typeOfMaterial,bool microphone, bool wired) {
    Headphones::set_name(name);
    Headphones::set_weight(weight);
    Headphones::set_TypeOfMaterial(typeOfMaterial);
    Headphones::set_microphone(microphone);
    this->wired=wired;
    cout<<"InEarHeadphones constructor"<<endl;
}
InEarHeadphones::InEarHeadphones(InEarHeadphones &&other)noexcept: Headphones(std::move(other)), wired(other.wired) {
    cout<<"InEarHeadphones move constuctor"<<endl;
}

InEarHeadphones::~InEarHeadphones() {
    cout<<"InEarHeadphones destructor"<<endl;
}