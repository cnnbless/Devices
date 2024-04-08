//
// Created by Endi on 27.03.2024.
//

#include "User.h"
#include <iostream>
#include "Functions.h"
#include <fstream>
#include "Mouse.h"
#include "Keyboard.h"
#include "Headphones.h"
#include "MechanicKeyboard.h"
#include "InEarHeadphones.h"
#include "GamingMouse.h"
#include <limits>
#include <string>
#include <memory>
using namespace std;

int check=0;

string User::get_URL_Cart() {
    return URL_Cart;
}

//Меню Звичайного Користувача
int User::User_Menu()const{
    tryAgain:
    try{
        cout << "---MENU---" << endl;
        cout << "1. Переглянути доступні товари" << endl;
        cout << "2. Додати товар в кошик" << endl;
        cout << "3. Видалити товар з кошика" << endl;
        cout << "4. Переглянути кошик" << endl;
        cout << "5. Переглянути історію покупок" << endl;
        cout << "6. Оплатити і вийти" << endl;
        cout << "Ваш вибір: " << endl;
        int choice;
        cin >> choice;
        if (cin.fail()) {
            throw invalid_argument("Invalid input");
        }
        if (choice < 1 or choice > 6) {
            cerr << "Помилка! Даного вибору немає" << endl;
            goto tryAgain;
        } else {
            return choice;
        }
    }
    catch (const invalid_argument& e){
        cout<<endl<<"Ви ввели некоректний тип даних!"<<endl<<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto tryAgain;
    }
}

//Показати наявні товари в магазині
void User::Display_products(){
    cout<<endl<<"****Доступні товари****";
    Functions::Display_info(URL_product);
}

//Додати товар в кошик
void User::Add_product_to_Cart() {
    while (true) {
        try {
            cout << "0 - Назад" << endl;
            cout << "Введіть номер товару, який хочете додати в кошик: ";
            int number;
            cin >> number;

            if (cin.fail()) {
                throw invalid_argument("Invalid input");
            }
            if (number == 0) {
                throw 0;
            }

            ifstream file(URL_product);
            string line;
            char delimiter = ',';
            bool flag_number = false;

            while (getline(file, line)) {
                if (line.empty()) {
                    continue;
                }
                vector<string> values = splitString(line, delimiter);
                if (stoi(values[1]) == number) {
                    flag_number = true;
                    break;
                }
            }
            file.close();
            if (!flag_number) {
                cout << endl << "Даного товару немає!" << endl << endl;
                continue;
            }

            unique_ptr<ifstream> products_file(new ifstream(URL_product));
            while (getline(*products_file, line)) {
                if (line.empty()) {
                    continue;
                }
                vector<string> values = splitString(line, delimiter);
                if (stoi(values[1]) == number) {
                    unique_ptr<ofstream> Cart_file(new ofstream(URL_Cart, ios::app));
                    if (check == 0) {
                        for (auto it = values.begin(); it != values.end(); ++it) {
                            *Cart_file << *it << ",";
                            check++;
                        }
                    } else {
                        *Cart_file << endl;
                        for (auto it = values.begin(); it != values.end(); ++it) {
                            *Cart_file << *it << ",";
                        }
                    }
                    Cart_file->close();
                    break;
                }
            }
            products_file->close();
            break; // вихід з циклу while
        } catch (const invalid_argument &e) {
            cout << endl << "Ви ввели некоректний тип даних!" << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        } catch (int e) {
            return;
        }
    }
}


//Видалити з кошика
void User::Delete_from_Cart() {
    Functions::Delete_product(URL_Cart);
}

//Показати товари в кошику
void User::Display_Cart() {
    cout<<endl<<"****Кошик****";
    Functions::Display_info(URL_Cart);
}

//Показати Історію покупок
void User::Display_history_of_purchases(){
    cout<<endl<<"****Історія покупок****";
    Functions::Display_info(URL);
}

void User::Pay() {

    unique_ptr<ifstream> Cart_file(new ifstream(URL_Cart));
    unique_ptr<ofstream> history_file(new ofstream(URL, ios::app));
    string line;
    while (getline(*Cart_file, line)) {
        *history_file << line << std::endl;
    }
    Cart_file->close();
    history_file->close();
    cout<<"Дякую за користування нашим магазином!;)"<<endl;
}


User::User(string &login,string &URL_product) {
    this->login=login;
    URL = "C:\\Users\\Tony\\CLionProjects\\Devices\\files\\" + login + "_purchase.txt";
    this->URL_product=URL_product;
    URL_Cart = "C:\\Users\\Tony\\CLionProjects\\Devices\\files\\Cart.txt";

    unique_ptr<ofstream> file(new ofstream(URL_Cart));
    file->close();
}

User::~User() {
    remove(URL_Cart.c_str());
}