#include "encryption.h"
#include "sorting.h"

class File{
public:
    void read(int type);
    void write(int type);
    void show_categories();
    int show(int type);
    int edit(int type);
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

    now = time(nullptr);
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

int File::show(int type){
    system("cls");
    read(type);

    std::cout << "The last time you opened this file was: "
    << hour << ":";
    if(minute < 10)
        std::cout << "0";
    std::cout << minute << " " <<day << "." << month << "." << year
    << std::endl << std::endl;

    std::cout << "which category you are interested in?" << std::endl;
    std::cout << std::endl;
    std::cout << "write < all > to see all the passwords" <<std::endl;
    std::cout << "categories in file " << type << " ";
    show_categories();
    std::cin >> category;

    int kind = 0;
    while(kind < 1 || kind > 3) {

        if(category == "all"){
            for(int i =0; i < categories.size() ; ++i){
                std::cout
                        << "name: " << names[i] << " "
                        << "    password: "<< passwords[i] << " "
                        << std::endl;
            }
            std::cout << std::endl;
        }
        else {
            for (int i = 0; i < categories.size(); ++i) {
                if (category == categories[i]) {
                    std::cout
                            << "name: " << names[i] << " "
                            << "password: " << passwords[i] << " "
                            << std::endl;
                }
            }
            std::cout << std::endl;
        }

        std::cout << "type 1 if you want to edit passwords" << std::endl;
        std::cout << "type 2 if you want to go back to desktop" << std::endl;
        std::cout << "type 3 if you want to exit" << std::endl;
        std::cin >> kind;
    }

    switch (kind) {
        case 1:
            type = edit(type);
            break;
        case 2:
            write(type);
            return 10;
        default:
            write(type);
    }
    if(type == 10)
        return 10;
    return 0;
}

int File::edit(int type){
    system("cls");

    int kind = 0;
    while(kind < 1 || kind > 6) {
        std::cout << "type 1 if you want to add new category" << std::endl;
        std::cout << "type 2 if you want to add new password to existing category" << std::endl;
        std::cout << "type 3 if you want to delete password" << std::endl;
        std::cout << "type 4 if you want to delete all category" << std::endl;
        std::cout << "type 5 if you want to go back to desktop" << std::endl;
        std::cout << "type 6 if you want to exit" << std::endl;
        std::cin >> kind;
    }

    bool category_name = false;
    int k =0;
    switch (kind) {
        case 1:
            std::cout << "what will be the name of your new category?" << std::endl;
            std::cin >> category;
            std::cout << "at least one password must exist in the new category" << std::endl;
            std::cout << "what is the name of your new password?" << std::endl;
            std::cin >> name;

            for(int i =0; i < names.size(); ++i){
                if(name == names[i])
                    category_name = true;
            }
            if(category_name){
                std::cout << "there is a password with that name" << std::endl;
                Sleep(1000);
                edit(type);
            }

            std::cout << "what is the password of your new password?" << std::endl;
            std::cin >> password;
            categories.push_back( category );
            names.push_back( name );
            passwords.push_back( password );

            std::cout << "your new password is now in the library!" << std::endl;
            Sleep(1000);
            write(type);
            edit(type);
            break;

        case 2:
            std::cout << "to which category you want to add new password?" << std::endl;
            show_categories();
            std::cin >> category;

            for(int i =0; i < categories.size(); ++i) {
                if (category == categories[i]) {
                    category_name = true;
                    break;
                }
                else
                    category_name = false;
            }
            if(!category_name) {
                std::cout << "the category does not exist" << std::endl;
                Sleep(1000);
                edit(type);
            }

            std::cout << "what is the name of your new password?" << std::endl;
            std::cin >> name;
            category_name = false;
            for(int i =0; i < names.size(); ++i){
                if(name == names[i])
                    category_name = true;
            }
            if(category_name){
                std::cout << "there is a password with that name" << std::endl;
                Sleep(1000);
                edit(type);
            }

            std::cout << "what is the password of your new password?" << std::endl;
            std::cin >> password;
            categories.push_back( category );
            names.push_back( name );
            passwords.push_back( password );

            std::cout << "your new password is now in the library!" << std::endl;
            Sleep(1000);
            write(type);
            edit(type);
            break;

        case 3:
            std::cout << "what is the name of the password?" << std::endl;
            std::cin >> name;
            for(int i =0; i < names.size(); ++i) {
                if(names[i] == name) {
                    names.erase(names.begin() + i);
                    categories.erase(categories.begin() + i);
                    passwords.erase(passwords.begin() + i);
                }
            }

            std::cout << "all of passwords with name " << name << " deleted" << std::endl;
            Sleep(1000);
            write(type);
            edit(type);
            break;

        case 4:
            std::cout << "what is the name of the category?" << std::endl;
            std::cin >> category;
            for(int i =0; i < categories.size(); ++i) {
                if(categories[i] == category) {
                    names.erase(names.begin() + i);
                    categories.erase(categories.begin() + i);
                    passwords.erase(passwords.begin() + i);
                }
            }

            std::cout << "all of passwords with category " << category << " deleted" << std::endl;
            Sleep(1000);
            write(type);
            edit(type);
            break;

        case 5:
            return 10;
        default:
            break;
    }
    return 0;
}

void File::show_categories(){
    int k =0;

    for(int i =0; i < categories.size(); ++i){
        for(int j = categories.size() -1; j > i; --j)
            if (categories[i] == categories[j])
                ++k;
        if(k != 0)
            k = 0;
        else
            std::cout << "< " << categories[i] << " > ";
    }
    std::cout << std::endl;
}