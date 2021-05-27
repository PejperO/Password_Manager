#include <iostream>
#include <vector>

void PasswordGenerator(){
    std::cout << "How long the password should be: " << std::endl;
    int size;
    std::cin >> size;

    std::vector<char> password;

    for(int i =0; i < size; ++i){
        password.push_back(48 + rand() % 75);  //ASCII
        std::cout << password[i];
    }
}