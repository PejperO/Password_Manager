
void desktop(){
    File file;

    int type = 0;
    while(type < 1 || type > 5){
        system("cls");
        std::cout << "What do you need?" << std::endl;
        std::cout << "type 1 if you want to read first file" << std::endl;
        std::cout << "type 2 if you want to read second file" << std::endl;
        std::cout << "type 3 if you want to edit password" << std::endl;
        std::cout << "type 4 if you want to create random password" << std::endl;
        std::cout << "type 5 if you want to exit" << std::endl;
        std::cin >> type;
    }
    system("cls");

    switch (type) {
        case 1: case 2:
            file.read(type);
            file.show();
            file.write(type);
            break;
        case 3:
            std::cout << "not available yet" << std::endl;
            break;
        case 4:
            PasswordGenerator();
            break;
        default:
            break;
    }
}
