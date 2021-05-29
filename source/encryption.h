
std::string encryption(std::string password){

    for(char & i : password) {
        if( (int)i <35 )
            i = (int)i + 89 - 1;
        else
            i = (int)i - 2;
    }
    for(int i =1; i<password.size(); i +=2)
        std::swap( password[i-1], password[i] );

    return password;
}

std::string decryption(std::string password){

    for(char & i : password) {
        if( (int)i > 120 )
            i = (int)i - 89 + 1;
        else
            i = (int)i + 2;
    }
    for(int i =1; i<password.size(); i +=2)
        std::swap( password[i-1], password[i] );

    return password;
}

/*
 ASCII
 my range of characters -> ( 33 - 122 )
 48 - 57 -> numbers
 65 - 90 -> capital letters
 97 - 122 -> letters
*/
