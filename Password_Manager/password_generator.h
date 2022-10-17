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

        int kind = 0;
        while (kind < 1 || kind > 3) {
            std::cout << "type 1 if you want to save the password" << std::endl;
            std::cout << "type 2 if you want to change random the password" << std::endl;
            std::cout << "type 3 if you want to go back to desktop" << std::endl;
            std::cout << "type 4 if you want to exit" << std::endl;
            std::cin >> kind;
        }
        system("cls");

        switch (kind) {
            case 1:
                std::cout << "not available yet" << std::endl;
                break;
            case 2:
                PasswordGenerator();
                break;
            case 3:
                //return 10;
            default:
                break;
        }
    //return 0;
}