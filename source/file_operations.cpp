#include <fstream>
#include <vector>
#include "encryption.h"

class File{  // idk why, just bc ^^
public:
    void read(int type);
    void write(int type);
    void show();
private:
    std::string name;
    std::string password;
    std::string category;
    std::vector <std::string> names;
    std::vector <std::string> passwords;
    std::vector <std::string> categories;
};

void File::read(int type){
    std::ifstream reading;

    if(type == 1)
        reading.open("data/pass1.txt");
    else
        reading.open("data/pass2.txt");

    while (true)
    {
        reading >> category >> name >> password;
        if (!reading.fail()) {
            categories.push_back( encryption( category ) );
            names.push_back( encryption( name ) );
            passwords.push_back( encryption( password ) );
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

    for(int i =0; i < categories.size() ; ++i) {
        writing
                << decryption( categories[i] ) << " "
                << decryption( names[i] ) << " "
                << decryption( passwords[i] ) << " "
                << std::endl;
    }

    writing.close();
}

void File::show(){
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
