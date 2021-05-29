#include <ctime>

void PasswordGenerator(){
    srand(time(nullptr));

    std::cout << "How long the password should be: " << std::endl;
    int size;
    std::cin >> size;

    std::vector<char> password;
    for(int i =0; i < size; ++i){
        password.push_back( 33 + rand()%(122 - 33) );
        std::cout << password[i];
    }
    std::cout << std::endl;
}