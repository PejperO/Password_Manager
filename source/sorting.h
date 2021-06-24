#include <algorithm>

std::vector <std::string> ascending(std::vector <std::string> names){
    //sort(names.begin(),names.end());

    for (int i=0; i<names.size()-1; i++) {
        for (int j = 0; j < names.size() - 1; j++) {
            if (names[j] > names[j + 1]) {
                swap(names[j], names[j + 1]);
            }
        }
    }
}

std::vector <std::string> descending(){

}