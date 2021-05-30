#include <iostream>
#include "file_operations.cpp"
#include "login.h"
#include "password_generator.h"
#include "desktop.h"

int main() {

    /*
     TO DO:
     - adding deleting passwords or categories
     - sorting parameters ( 2 different parameters )
    */

    bool logged = login();

    if(logged)
        desktop();

    system("pause");
}