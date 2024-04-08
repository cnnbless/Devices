#include <iostream>
#include <fstream>
#include <string>
#include "vector"
#include "User.h"
#include "Printable.h"
#include "Admin.h"
#include <memory>

using namespace std;
ostream &operator<<(ostream &os, const Printable &obj) {
    obj.print(os);
    return os;
}
istream &operator>>(std::istream &is, Printable &obj) {
    obj.readData(is);
    return is;
}

int main() {
    string URL_login = "C:\\Users\\Tony\\CLionProjects\\Devices\\files\\Login.txt";
    string URL_product = "C:\\Users\\Tony\\CLionProjects\\Devices\\files\\Products.txt";

    unique_ptr<ifstream> file(new ifstream(URL_login));
    vector<string> logins;
    string line;
    while (getline(*file, line)) {
        if (!line.empty()) {
            logins.push_back(line);
        }
    }
    file->close();

    string login;
    bool user_flag = false;
    bool admin_flag = false;

    do {
        cout << "Введіть ваш логін: ";
        cin >> login;

        if (login == "admin") {
            cout << "Введіть пароль: ";
            string password;
            cin >> password;
            if (password == "admin") {
                admin_flag = true;
                break;
            } else {
                cout << "Ви ввели невірний пароль!" << endl << endl;
            }
        } else {
            bool old_user = false;
            for (const string& existing_login : logins) {
                if (login == existing_login) {
                    user_flag = true;
                    old_user = true;
                    cout << "OLD USER" << endl;
                    break;
                }
            }
            if (!old_user) {
                user_flag = true;
                logins.push_back(login);

                unique_ptr<ofstream> file(new ofstream(URL_login, ios::app));
                *file << endl << login;
                file->close();

                cout << "NEW USER" << endl;

                string purchase_name_file = "C:\\Users\\Tony\\CLionProjects\\Devices\\files\\" + login + "_purchase.txt";
                unique_ptr<ofstream> purchase_history(new ofstream(purchase_name_file));
                purchase_history->close();
            }
        }
    } while (!user_flag && !admin_flag);

    std::unique_ptr<Admin> admin;
    std::unique_ptr<User> user;
    if (admin_flag) {
        admin=make_unique<Admin>(URL_product);
        while (true) {
            int choice = admin->Admin_Menu();
            if (choice == 1) {
                admin->Display_products();
            }
            if (choice == 2) {
                try{
                    admin->Add_product();
                }
                catch (int a){
                    continue;
                }
            }
            if(choice==3){
                try{
                    admin->Product_delete();
                    remove(admin->get_URL().c_str());
                    rename("C:\\Users\\Tony\\CLionProjects\\Devices\\files\\temp.txt"
                            , admin->get_URL().c_str());
                }
                catch (int a){
                    continue;
                }
            }
            if (choice == 4) {
                break;
            }
        }
    }

    if(user_flag){
        user = make_unique<User>(login, URL_product);
        while(true){
            int choice = user->User_Menu();
            if(choice==1){
                user->Display_products();
            }
            if(choice==2){
                try{
                    user->Add_product_to_Cart();
                }
                catch (int a){
                    continue;}
            }
            if(choice==3){
                try{
                    user->Delete_from_Cart();
                    remove(user->get_URL_Cart().c_str());
                    rename("C:\\Users\\Tony\\CLionProjects\\Devices\\files\\temp.txt"
                            , user->get_URL_Cart().c_str());
                }
                catch(int a){
                    continue;
                }
            }
            if(choice==4){
                user->Display_Cart();
            }
            if(choice==5){
                user->Display_history_of_purchases();
            }
            if(choice==6){
                user->Pay();
                break;
            }
        }
    }

    return 0;
}