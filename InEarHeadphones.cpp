//
// Created by Endi on 29.02.2024.
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

void InEarHeadphones::print_name_class() const {
    cout<<"InEarHeadphones"<<endl;
}

void InEarHeadphones::print(std::ostream &os) const {
    Headphones::print(os);
    os<<"Провідні наушники: "<<wired<<endl;

}
void InEarHeadphones::print_class_name() const {
    cout<<"Class name: InEarHeadphones"<<endl;
}

InEarHeadphones::InEarHeadphones(std::string name, float weight, std::string typeOfMaterial,bool microphone, bool wired):
        Headphones{string{name},float{weight},string{typeOfMaterial}
                ,bool{microphone} }{
    this->wired=wired;
    cout<<"InEarHeadphones constructor"<<endl;
}
InEarHeadphones::InEarHeadphones(InEarHeadphones &&other)noexcept: Headphones(std::move(other)), wired(other.wired) {
    cout<<"InEarHeadphones move constuctor"<<endl;
}

InEarHeadphones::~InEarHeadphones() {
    cout<<"InEarHeadphones destructor"<<endl;
}