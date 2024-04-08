//
// Created by Endi on 27.03.2024.
//

#ifndef DEVICESOOP_ADMIN_H
#define DEVICESOOP_ADMIN_H
#include <iostream>
#include "Functions.h"
using namespace std;

class Admin: public Functions{
private:
    string URL;
public:
    string get_URL()const;

    int Admin_Menu()const;

    void Display_products();

    void Add_product();
    void Pointer_product(string &&pointer)const;

    void Product_delete();

    Admin(string &URL);
    virtual ~Admin();

};


#endif //DEVICESOOP_ADMIN_H