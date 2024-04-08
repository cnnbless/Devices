//
// Created by Endi on 27.03.2024.
//

#ifndef DEVICESOOP_FUNCTIONS_H
#define DEVICESOOP_FUNCTIONS_H
#include <iostream>
#include <vector>

using namespace std;
class Functions {

public:
    virtual void Display_info(string& URL)const final;
    virtual void print_product(vector<string> value)const final;
    virtual vector<string> splitString(const string &str, char delimiter)const final;

    virtual void Delete_product(string& URL)const final;
    virtual void deleteLineFromFile(const string& URL, int lineToDelete)const final;


    Functions(){};
    virtual ~Functions(){};

};


#endif //DEVICESOOP_FUNCTIONS_H