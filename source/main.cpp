#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <ctime>
#include "login.h"
#include "file_operations.cpp"

void desktop(){
    File file;

    int type = 0;
    while(type < 1 || type > 4){
        system("cls");
        std::cout << "What do you need?" << std::endl;
        std::cout << "type 1 if you want to read first file" << std::endl;
        std::cout << "type 2 if you want to read second file" << std::endl;
        std::cout << "type 3 if you want to exit" << std::endl;
        std::cin >> type;
    }
    system("cls");

    switch (type) {
        case 1: case 2:
            type = file.show(type);
            break;
        case 3:
            //type = PasswordGenerator(0);
            std::cout << "not available yet" << std::endl;
            break;
        default:
            break;
    }
    if(type == 10)
        desktop();
}

int main() {

    /*
     TO DO:
     - sorting parameters ( 2 different parameters )
    */

    bool logged = login();

    if(logged)
        desktop();

    system("cls");
    system("pause");
}