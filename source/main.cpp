#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "login.h"
#include "password_generator.h"
#include "encryption.h"

int main() {
    bool logged = login();

    if(logged){
        std::ifstream file1;
        file1.open("data/pass.txt");

        std::string name;
        std::string password;
        std::string category;

        std::vector <std::string> names;
        std::vector <std::string> passwords;
        std::vector <std::string> categories;

        while (true)
        {
            file1 >> category >> name >> password;
            if (!file1.fail()) {
                categories.push_back(category);
                names.push_back(name);
                passwords.push_back(password);
            }
            else
                break;
        }
        std::cout << "which category you are interested in?" << std::endl;
        std::cin >> category;

        for(int i =0; i < category.size() ; ++i){
            if(category == categories[i]){
                std::cout
                << "name: " <<names[i] << " "
                << "password: "<<passwords[i] << " "
                << std::endl;
            }
        }
    }

    int get;
    std::cin >> get;
}