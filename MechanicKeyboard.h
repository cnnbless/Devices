//
// Created by Endi on 29.02.2024.
//

#ifndef DEVICESOOP_MECHANICKEYBOARD_H
#define DEVICESOOP_MECHANICKEYBOARD_H

#include "Keyboard.h"
#include <iostream>
using namespace std;

class MechanicKeyboard: public Keyboard{
private:
    string colorOfKeyboard;
public:
    string set_colorOfKeyboard(string &&colorOfKeyboard);
    string get_colorOfKeyboard()const;

    void print(std::ostream &os) const override;
    void readData(std::istream& is) override;
    void writeProduct() override;
    MechanicKeyboard(const MechanicKeyboard &other);

    MechanicKeyboard(int product_number=0,string &&name="None", float weight=0, string &&type_of_material="None"
            ,float price=0,string &&colorOfKeyboard="None");
    ~MechanicKeyboard() override;

};
#endif //DEVICESOOP_MECHANICKEYBOARD_H