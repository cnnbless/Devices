#include <iostream>
#include "Mouse.h"
#include "Keyboard.h"
#include "Headphones.h"
#include "MechanicKeyboard.h"
#include "InEarHeadphones.h"
#include "GamingMouse.h"
#include "Printable.h"
using namespace std;


ostream &operator<<(ostream &os, const Printable &obj) {
    obj.print(os);
    return os;
}

int main() {
//проблему Static Method Binding
//    Keyboard a;
//    MechanicKeyboard b;
//    Keyboard *p=&b;
//    p->doSomething();

// (Run-time) поліморфізму
//    Mouse a;
//    GamingMouse b;
//    Mouse *p=&b;
//    p->info();

// virtual destructor
//    Keyboard *a = new MechanicKeyboard;
//    delete a;

//final
//    GamingMouse a;
//    a.Click();

// Base class reference
//    InEarHeadphones a;
//    Headphones b;
//    InEarHeadphones &pos = a;
//    pos.print_name_class();
// Pure virtual function + інтерфейс
//    MechanicKeyboard a("rty",2.4,"metal","green");
//    cout << a;
//    GamingMouse b("wirma",1.3,"plastic",true,3,true);
//    cout<<b;
//    InEarHeadphones c("warmila",4,"plastic",true,false);
//    cout<<c;

// 7
//    MechanicKeyboard a;
//    a.print_class_name();
    return 0;
}