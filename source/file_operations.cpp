#include <fstream>
#include <vector>
#include <ctime>
#include "encryption.h"

class File{  // idk why, just bc ^^
public:
    void read(int type);
    void write(int type);
    void show();
private:
    time_t now;
    struct tm nowLocal;
    int day, month, year;
    std::string name, password, category;
    std::vector <std::string> names, passwords, categories;
};

void File::read(int type){
    std::ifstream reading;

    if(type == 1)
        reading.open("data/pass1.txt");
    else
        reading.open("data/pass2.txt");

    reading >> day >> month >> year;
    day = IntDecryption( day );
    month = IntDecryption( month );
    year = IntDecryption( year );

    while (true)
    {
        reading >> category >> name >> password;
        if (!reading.fail()) {
            categories.push_back(decryption(category) );
            names.push_back(decryption(name) );
            passwords.push_back(decryption(password) );
        }
        else
            break;
    }
    reading.close();
}

void File::write(int type){
    std::ofstream writing;

    if(type == 1)
        writing.open("data/pass1.txt");
    else
        writing.open("data/pass2.txt");

    now = time(NULL);
    nowLocal = *localtime(&now);
    writing << IntEncryption( nowLocal.tm_mday ) << " "
    << IntEncryption( nowLocal.tm_mon + 1 ) << " "
    << IntEncryption( nowLocal.tm_year + 1900 ) << std::endl;

    for(int i =0; i < categories.size() ; ++i) {
        writing
                << encryption(categories[i]) << " "
                << encryption(names[i]) << " "
                << encryption(passwords[i]) << " "
                << std::endl;
    }

    writing.close();
}

void File::show(){

    std::cout << "The last time you opened this file was: "
    << day << "." << month << "." << year << std::endl << std::endl;

    std::cout << "which category you are interested in?" << std::endl;
    for(int i =0; i < categories.size(); ++i){
        if(categories[i] != categories[i+1])
            std::cout << "< " << categories[i] << " > ";
    }
    std::cout << std::endl;
    std::cin >> category;

    for(int i =0; i < categories.size() ; ++i){
        if( category == categories[i] ){
            std::cout
                    << "name: " << names[i] << " "
                    << "password: "<< passwords[i] << " "
                    << std::endl;
        }
    }
}