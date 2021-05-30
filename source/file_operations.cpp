#include "encryption.h"

class File{
public:
    void read(int type);
    void write(int type);
    void show(int type);
private:
    time_t now;
    struct tm nowLocal;
    int hour, minute, day, month, year;
    std::string name, password, category;
    std::vector <std::string> names, passwords, categories;
};

void File::read(int type){
    std::ifstream reading;

    if(type == 1)
        reading.open("data/pass1.txt");
    else
        reading.open("data/pass2.txt");

    reading >> hour >> minute >> day >> month >> year;
    hour = IntDecryption( hour );
    minute = IntDecryption( minute );
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
    writing
    << IntEncryption( nowLocal.tm_hour ) << " "
    << IntEncryption( nowLocal.tm_min ) << " "
    << IntEncryption( nowLocal.tm_mday ) << " "
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

void File::show(int type){

    read(type);

    std::cout << "The last time you opened this file was: "
    << hour << ":";
    if(minute < 10)
        std::cout << "0";
    std::cout << minute << " " <<day << "." << month << "." << year
    << std::endl << std::endl;

    std::cout << "which category you are interested in?" << std::endl;
    for(int i =0; i < categories.size(); ++i){
        if(categories[i] != categories[i+1])
            std::cout << "< " << categories[i] << " > ";
    }
    std::cout << std::endl;
    std::cin >> category;

    int kind = 0;
    while(kind < 1 || kind > 3) {

        for(int i =0; i < categories.size() ; ++i){
            if( category == categories[i] ){
                std::cout
                << "name: " << names[i] << " "
                << "password: "<< passwords[i] << " "
                << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << "type 1 if you want to edit passwords" << std::endl;
        std::cout << "type 2 if you want to go back to desktop" << std::endl;
        std::cout << "type 3 if you want to exit" << std::endl;
        std::cin >> kind;
    }

    switch (kind) {
        case 1:
            std::cout << "not available yet" << std::endl;
            break;
        case 2:
            std::cout << "not available yet 2" << std::endl;
            break;
        default:
            write(type);
    }
}