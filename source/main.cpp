#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include "login.h"
#include "password_generator.h"
#include "encryption.h"

std::string name;
std::string password;
std::string category;

std::vector <std::string> names;
std::vector <std::string> passwords;
std::vector <std::string> categories;

void read(int type){
    std::ifstream reading;

    if(type == 1)
        reading.open("data/pass1.txt");
    else
        reading.open("data/pass2.txt");

    while (true)
    {
        reading >> category >> name >> password;
        if (!reading.fail()) {
            categories.push_back( encryption( category ) );
            names.push_back( encryption( name ) );
            passwords.push_back( encryption( password ) );
        }
        else
            break;
    }
    reading.close();
}

void write(int type){
    std::ofstream writing;

    if(type == 1)
        writing.open("data/pass1.txt");
    else
        writing.open("data/pass2.txt");

    for(int i =0; i < categories.size() ; ++i) {
        writing
                << decryption( categories[i] ) << " "
                << decryption( names[i] ) << " "
                << decryption( passwords[i] ) << " "
                << std::endl;
    }

    writing.close();
}

void show(){
    std::cout << "which category you are interested in?" << std::endl;
    std::cin >> category;

    for(int i =0; i < categories.size() ; ++i){
        if(category == categories[i]){
            std::cout
                    << "name: " << names[i] << " "
                    << "password: "<< passwords[i] << " "
                    << std::endl;
        }
    }
}

int main() {
    bool logged = login();

    if(logged){

        int type = 0;
        while(type < 1 || type > 4){
            system("cls");
            std::cout << "What do you need?" << std::endl;
            std::cout << "type 1 if you want to read first file" << std::endl;
            std::cout << "type 2 if you want to read second file" << std::endl;
            std::cout << "type 3 if you want to edit password" << std::endl;
            std::cout << "type 4 if you want to create new password" << std::endl;
            std::cin >> type;
        }
        system("cls");

        switch (type) {
            case 1:
                read(type);
                show();
                write(type);
                break;
            case 2:
                read(type);
                show();
                write(type);
                break;
            case 3:
                std::cout << "not available yet" << std::endl;
                break;
            case 4:
                PasswordGenerator();
        }
    }
    std::cout << std::endl << "press any key and enter to continue: " << std::endl;
    int get;
    std::cin >> get;
}