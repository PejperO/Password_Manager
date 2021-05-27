#include <iostream>
#include <algorithm>

void encryption(string password){
    for(int i=0; i<password.size()-1; i+=2)
        std::swap( password[i], password[i+1] );

    for(int i=1; i<password.size(); i+=2)
        std::swap( password[i], password[i+1] );
}

void decryption(string password){
    for(int i=1; i<password.size(); i+=2)
        std::swap( password[i], password[i+1] );

    for(int i=0; i<password.size()-1; i+=2)
        std::swap( password[i], password[i+1] );
}