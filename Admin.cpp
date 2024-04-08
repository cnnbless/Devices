//
// Created by Endi on 27.03.2024.
//

#include "Admin.h"
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
#include <memory>


using namespace std;

string Admin::get_URL() const {
    return URL;
}

//Меню Адміна
int Admin::Admin_Menu() const {
    int choice;
    do {
        try {
            cout << "---MENU---" << endl;
            cout << "1. Переглянути доступні товари" << endl;
            cout << "2. Додати новий товар" << endl;
            cout << "3. Видалити товар" << endl;
            cout << "4. Зберегти і вийти" << endl;
            cout << "Ваш вибір: ";
            cin >> choice;

            if (cin.fail()) {
                throw invalid_argument("Invalid input");
            }
            if (choice < 1 or choice > 4) {
                cerr << "Помилка! Даного вибору немає" << endl;
            }
        } catch (const invalid_argument& e) {
            cout << endl << "Ви ввели некоректний тип даних!" << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice < 1 or choice > 4);

    return choice;
}

//Показати наявні товари
void Admin::Display_products(){
    cout<<endl<<"****Доступні товари****"<<endl;
    Functions::Display_info(URL);
}

//Додати новий товар в магазин {
void Admin::Pointer_product(std::string &&pointer) const {
    unique_ptr<ofstream> file(new ofstream(URL, ios::app));
    *file << endl << pointer;
    file->close();
}
void Admin::Add_product() {
    int choice;
    do {
        try {
            cout << "Який товар додати?" << endl;
            cout << "1.Клавіатура" << endl;
            cout << "2.Механічна клавіатура" << endl;
            cout << "3.Мишка" << endl;
            cout << "4.Ігрова мишка" << endl;
            cout << "5.Навушники" << endl;
            cout << "6.Навушники-затички" << endl;
            cout << "0 - Назад" << endl;
            cout << "Ваш вибір: ";
            cin >> choice;

            if (cin.fail()) {
                throw invalid_argument("Invalid input");
            }
            if (choice == 0) {
                throw 0;
            }
            if (choice < 1 or choice > 6) {
                cerr << "Даного вибору немає!" << endl<<endl;
            }
        } catch (const invalid_argument& e) {
            cerr << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } catch (int e) {
            cout << "Повертаємося до попереднього меню." << endl;
            return;
        }

        // Блок коду, який раніше містив goto tryAgain
        if (choice == 1) {
            Pointer_product("Keyboard,");
            cout << "---ТОВАР: Клавіатура---" << endl;
            shared_ptr<Keyboard> a(new Keyboard);
            cin >> *a;
            a->writeProduct();
        }
        if (choice == 2) {
            Pointer_product("MechanicKeyboard,");
            cout << "---ТОВАР: Механічна клавіатура---" << endl;
            shared_ptr<MechanicKeyboard> a(new MechanicKeyboard);
            cin >> *a;
            a->writeProduct();
        }
        if (choice == 3) {
            Pointer_product( "Mouse,");
            cout << "---ТОВАР: Мишка---" << endl;
            shared_ptr<Mouse> a(new Mouse);
            cin >> *a;
            a->writeProduct();
        }
        if (choice == 4) {
            Pointer_product( "GamingMouse,");
            cout << "---ТОВАР: Ігрова мишка---" << endl;
            shared_ptr<GamingMouse> a(new GamingMouse);
            cin >> *a;
            a->writeProduct();
        }
        if (choice == 5) {
            Pointer_product( "Headphones,");
            cout << "---ТОВАР: Навушники---" << endl;
            shared_ptr<Headphones> a(new Headphones);
            cin >> *a;
            a->writeProduct();
        }
        if (choice == 6) {
            Pointer_product( "InEarHeadphones,");
            cout << "---ТОВАР: Навушники-затичик---" << endl;
            shared_ptr<InEarHeadphones> a(new InEarHeadphones);
            cin >> *a;
            a->writeProduct();
        }
    } while (choice < 1 or choice > 6);
}

// }

//Видалити товар з магазина
void Admin::Product_delete() {
    Functions::Delete_product(URL);
}


Admin::Admin(string &URL) {
    this->URL=URL;
}
Admin::~Admin() {

}