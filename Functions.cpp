//
// Created by Endi on 27.03.2024.
//

#include "Functions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Mouse.h"
#include "Keyboard.h"
#include "Headphones.h"
#include "MechanicKeyboard.h"
#include "InEarHeadphones.h"
#include "GamingMouse.h"
#include <limits>
#include <memory>

vector<string> Functions::splitString(const std::string &str, char delimiter) const {
    shared_ptr<vector<string>> tokens(new vector<string>);
    size_t startPos = 0;
    size_t endPos = str.find(delimiter);

    while (endPos != string::npos) {
        tokens->push_back(str.substr(startPos, endPos - startPos));
        startPos = endPos + 1;
        endPos = str.find(delimiter, startPos);
    }
    tokens->push_back(str.substr(startPos, endPos));
    return *tokens;
}

void Functions::print_product(vector<std::string> value) const {
    if (value[0] == "Keyboard") {
        unique_ptr<Keyboard> a(new Keyboard(stoi(value[1]), string(value[2])
                , stof(value[3]), string(value[4]), stof(value[5])));
        cout << *a;
    }
    if (value[0] == "MechanicKeyboard") {
        unique_ptr<MechanicKeyboard> a(new MechanicKeyboard(stoi(value[1]), string(value[2])
                , stof(value[3]), string(value[4])
                , stof(value[5]),string(value[6])));
        cout << *a;
    }
    if (value[0] == "Mouse") {
        unique_ptr<Mouse> a(new Mouse(stoi(value[1]), string(value[2])
                , stof(value[3]), string(value[4])
                , stof(value[5]), stoi(value[6])));
        cout << *a;
    }
    if (value[0] == "GamingMouse") {
        unique_ptr<GamingMouse> a(new GamingMouse(stoi(value[1]), string(value[2])
                , stof(value[3]), string(value[4])
                , stof(value[5]),stoi(value[6])
                , stoi(value[7]), stoi(value[8])));
        cout << *a;
    }
    if (value[0] == "Headphones") {
        unique_ptr<Headphones> a(new Headphones(stoi(value[1]), string(value[2])
                , stof(value[3]), string(value[4])
                , stof(value[5])));
        cout << *a;
    }
    if (value[0] == "InEarHeadphones") {
        unique_ptr<InEarHeadphones> a(new InEarHeadphones((stoi(value[1])), string(value[2])
                , stof(value[3]), string(value[4]), stof(value[5])
                ,stoi(value[6]),stoi(value[7])));
        cout << *a;
    }

}

void Functions::Display_info(std::string &URL) const {
    unique_ptr<ifstream> file (new ifstream(URL));
    string line;
    char delimiter = ',';

    while (getline(*file, line)) {
        if (line.empty()) {
            continue;
        }
        vector<string> values = splitString(line, delimiter);
        print_product(values);
    }
    cout << endl;
    file->close();
}

void Functions::deleteLineFromFile(const std::string &URL, int lineToDelete) const {
    unique_ptr<ifstream> inFile (new ifstream(URL));
    unique_ptr<ofstream> tempFile (new ofstream("C:\\Users\\Tony\\CLionProjects\\Devices\\files\\temp.txt"));

    string line;
    int lineNum = 1;
    while (getline(*inFile, line)) {
        if(line.empty()){
            continue;
        }
        if (lineNum != lineToDelete) {
            if (lineNum > 1)
                *tempFile << endl;
            *tempFile << line;
        }
        lineNum++;
    }
    inFile->close();
    tempFile->close();
}

void Functions::Delete_product(std::string &URL) const {
    tryAgain:
    try{
        cout<<"0 - Назад"<<endl;
        cout<<"Введіть номер товара: ";
        int number;
        cin>>number;

        if (cin.fail()) {
            throw std::invalid_argument("Invalid input");
        }
        if(number==0){
            throw 0;
        }

        unique_ptr<ifstream> file(new ifstream(URL));
        string line;
        char delimiter = ',';
        bool flag_number=false;

        while (getline(*file, line)) {
            if (line.empty()) {
                continue;
            }
            vector<string> values = splitString(line, delimiter);
            if(stoi(values[1])==number){
                flag_number= true;
                break;
            }
        }
        file->close();
        if(!flag_number){
            cout<<endl<<"Даного товара немає!"<<endl<<endl;
            goto tryAgain;
        }
        unique_ptr<ifstream> products_file(new ifstream(URL));
        int line_delete=1;

        while (getline(*products_file, line)) {
            if (line.empty()) {
                continue;
            }
            vector<string> values = splitString(line, delimiter);
            if(stoi(values[1])==number){
                deleteLineFromFile(URL,line_delete);
                break;
            }
            line_delete++;
        }

        products_file->close();

    }
    catch(const invalid_argument& e){
        cout<<endl<<"Ви ввели некоректний тип даних!"<<endl<<endl;
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        goto tryAgain;
    }
}