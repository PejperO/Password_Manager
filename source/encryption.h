#include <iostream>
#include <algorithm>

std::string encryption(std::string password){

    for(char & i : password) {
        if( (int)i < 50)
            i = (int)i + 9 - 1;
        if( (int)i < 67 && (int)i >= 65)
            i = (int)i + 25 - 1;
        if( (int)i < 99 && (int)i >= 97)
            i = (int)i + 25 - 1;
        else
            i = (int)i - 2;
    }

    for(int i =1; i<password.size(); i +=2)
        std::swap( password[i-1], password[i] );

    return password;
}

std::string decryption(std::string password){

    for(char & i : password) {
        if( (int)i > 55 && (int)i <= 57)
            i = (int)i - 9 + 1;
        if( (int)i > 88 && (int)i <= 90)
            i = (int)i - 25 + 1;
        if( (int)i > 120 && (int)i <= 122)
            i = (int)i - 25 + 1;
        else
            i = (int)i + 2;
    }

    for(int i =1; i<password.size(); i +=2)
        std::swap( password[i-1], password[i] );

    return password;
}

void mabey(std::string password){  // are elements 0, 7, 8, 10, 13 problem?

    for(char & i : password){  //encryption
        if( (int)i > 250)
            i = (int) i - 255 + 4;
        else
            i = (int)i + 5;
    }

    for(char & i : password){  //decryption
        if( (int)i < 5)
            i = (int) i + 255 - 4;
        else
            i = (int)i - 5;
    }
}

// 48 - 57 -> numbers
// 65 - 90 -> capital letters
// 97 - 122 -> letters
