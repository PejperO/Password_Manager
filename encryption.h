#include <iostream>

void encryption(string password){
    char help;

    for(int i=0; i<password.size()-1; i+=2){
        help= password[i];
        password[i] = password[i+1];
        password[i+1] = help;
    }

    for(int i=1; i<password.size(); i+=2){
        help= password[i];
        password[i] = password[i+1];
        password[i+1] = help;
    }
}