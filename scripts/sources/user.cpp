#include "user.hpp"
#include <iostream>


void UserInfo::data_shower(){
    std::cout << "1- Family Name: " << personal_info_.family_name << std::endl;
    std::cout << "2- First Name: " << personal_info_.first_name << std::endl;
    std::cout << "3- Birth Date: " << personal_info_.birth_date << std::endl;
    std::cout << "4- Gender: " << personal_info_.gender << std::endl;
    std::cout << "5- Email: " << contact_info_.email << std::endl;
    std::cout << "6- Phone Number: " << contact_info_.phone_number << std::endl;
    std::cout << "7- Street: " << home_address_.street << std::endl;
    std::cout << "8- House Number: " << home_address_.house_number << std::endl;
    std::cout << "9- City: " << home_address_.city << std::endl;
    std::cout << "10- Postal Code: " << home_address_.postal_code << std::endl;
    std::cout << "11- Password: " << personal_info_.password << std::endl;
}

void UserInfo::password_repetition(){
    std::cout << "Please enter the new password: ";
    std::cin >> personal_info_.password;
}

void UserInfo::postal_code_repetition(){
    std::cout << "Please enter the new postal code: ";
    std::cin >> home_address_.postal_code;
}

void UserInfo::house_number_repetition(){
    std::cout << "Please enter the new house number: ";
    std::cin >> home_address_.house_number;
}

void UserInfo::city_repetition(){
    std::cout << "Please enter the new city: ";
    std::cin >> home_address_.city;
}

void UserInfo::street_repetition(){
    std::cout << "Please enter the new street: ";
    std::cin >> home_address_.street;
}

void UserInfo::phone_number_repetition(){
    std::cout << "Please enter the new phone number: ";
    std::cin >> contact_info_.phone_number;
}

void UserInfo::gender_repetition(){
    std::cout << "Please enter your gender again: ";
    std::cin >> personal_info_.gender;
}

void UserInfo::birth_date_repetition(){
    std::cout << "Please enter your birth date again: ";
    std::cin >> personal_info_.birth_date;
}

void UserInfo::first_name_repetition(){
    std::cout << "Please enter your first name again: ";
    std::cin >> personal_info_.first_name;
}

void UserInfo::family_name_repetition(){
    std::cout << "Please enter your family name again: ";
    std::cin >> personal_info_.family_name;
}

void UserInfo::email_repetition(){
    std::cout << "Please enter your email again: ";
    std::cin >> contact_info_.email;
}

void UserInfo::user_input(){
    std::cout << "Family name: ";
    std::cin >> personal_info_.family_name;
    std::cout << "First name: ";
    std::cin >> personal_info_.first_name;
    std::cout << "Birthday (dd.mm.yyyy): ";
    std::cin >> personal_info_.birth_date;
    std::cout << "Gender (m/f/x): ";
    std::cin >> personal_info_.gender;
    std::cout << "E-Mail: ";
    std::cin >> contact_info_.email;
    std::cout << "Phone number: ";
    std::cin >> contact_info_.phone_number;
    std::cout << "Street: ";
    std::cin >> home_address_.street;
    std::cout << "House number: ";
    std::cin >> home_address_.house_number;
    std::cout << "City: ";
    std::cin >> home_address_.city;
    std::cout << "Postal code: ";
    std::cin >> home_address_.postal_code;
    std::cout << "Password: ";
    std::cin >> personal_info_.password;
}