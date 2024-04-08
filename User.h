//
// Created by Endi on 27.03.2024.
//

#ifndef DEVICESOOP_USER_H
#define DEVICESOOP_USER_H
#include <iostream>
#include "Functions.h"
using namespace std;

class User: public Functions{
private:
    string login;
    string URL;
    string URL_product;
    string URL_Cart;
public:
    string get_URL_Cart();

    int User_Menu()const;

    void Display_products();

    void Add_product_to_Cart();

    void Delete_from_Cart();

    void Display_Cart();

    void Display_history_of_purchases();

    void Pay();

    User(string &login,string &URL_product);
    virtual ~User();
};


#endif //DEVICESOOP_USER_H