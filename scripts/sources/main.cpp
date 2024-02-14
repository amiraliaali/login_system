#include <iostream>
#include "system.hpp"

int main(void){
    System main_system;
    int user_input{0};

    do{
        std::cout << "Welcome to the system!" << std::endl;
        std::cout << "1- Sign in" << std::endl;
        std::cout << "2- New user" << std::endl;
        std::cout << "3- Exit" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> user_input;

        switch(user_input){
            case 1:
                main_system.sign_in();
                break;
            case 2:
                main_system.new_user();
                break;
            default:
                break;
        }
        std::cout << "-----------------------------------" << std::endl;
    }while(user_input != 3);

    return 0;
}