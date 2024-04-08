//
// Created by Endi on 29.02.2024.
//

#ifndef DEVICESOOP_INEARHEADPHONES_H
#define DEVICESOOP_INEARHEADPHONES_H

#include "Headphones.h"
#include <iostream>

using namespace std;

class InEarHeadphones: public Headphones{
private:
    bool wired;
public:
    bool set_wired(bool wired);
    bool get_wired()const;

    void print(std::ostream &os) const override;
    void readData(std::istream& is) override;
    void writeProduct() override;
    InEarHeadphones(InEarHeadphones&& other)noexcept;

    InEarHeadphones(int product_number=0,string &&name="None", float weight=0, string &&type_of_material="None"
            ,float price=0, bool microphone= false, bool wired = false);
    ~InEarHeadphones() override;

};


#endif //DEVICESOOP_INEARHEADPHONES_H