#include <windows.h>

bool login(){
    std::string AppPassword = "yes";

    std::cout << "Welcome to Password manager!" << std::endl;
    std::string password_login;

    for(size_t i = 0; i < 3; ++i) {
        std::cout << "To make sure you are the owner please write the password:" <<std::endl;
        std::cin >> password_login;

        if(password_login == AppPassword){
            std::cout << "You have been successfully logged in!" << std::endl;
            Sleep(1000);
            system("cls");  //not working on CLion ?
            return true;
        }
        else {
            if(i < 2)
                std::cout << "Your password is incorrect. " << 2 - i
                << " more tries" << std::endl;
            else {
                std::cout << "You entered the wrong password 3 times" << std::endl
                << "blocking" << std::endl;
                return false;
            }
        }
    }
    return false;
}
