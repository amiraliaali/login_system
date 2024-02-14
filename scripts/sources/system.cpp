#include <fstream>
#include "system.hpp"

void System::new_user(){
    UserInfo new_user;
    new_user.user_input();
    for (int i=0; i<number_of_data_; i++){
        if (new_user.contact_info_.email == contact_infos_[i].email){
            std::cout << "This email is already registered!" << std::endl;
            new_user.email_repetition();
            i = 0;
        }
    }

    int user_input{-1};

    do{
        new_user.data_shower();
        std::cout << "If you want to change any data, please give the number of the data you want to change. Otherwise, please give 0: ";
        std::cin >> user_input;

        switch(user_input){
            case 1:
                new_user.family_name_repetition();
                break;
            case 2:
                new_user.first_name_repetition();
                break;
            case 3:
                new_user.birth_date_repetition();
                break;
            case 4:
                new_user.gender_repetition();
                break;
            case 5:
                new_user.email_repetition();
                break;
            case 6:
                new_user.phone_number_repetition();
                break;
            case 7:
                new_user.street_repetition();
                break;
            case 8:
                new_user.house_number_repetition();
                break;
            case 9:
                new_user.postal_code_repetition();
                break;
            case 10:
                new_user.city_repetition();
                break;
            case 11:
                new_user.password_repetition();
                break;
            default:
                break;
        }
    }while (user_input != 0);

    new_user.personal_info_.number = number_of_data_;
    numbers_.push_back(new_user.personal_info_.number);
    personal_infos_.push_back(new_user.personal_info_);
    contact_infos_.push_back(new_user.contact_info_);
    home_addresses_.push_back(new_user.home_address_);
    number_of_data_++;
    file_writer();
}



void System::file_writer()
{
    std::ofstream outfile("/home/amiraliaali/self_projects/login_system/usersInfo.txt");
    outfile << first_line_ << std::endl;
    for (int i = 0; i < number_of_data_; i++)
    {
        outfile << numbers_[i] << "\t" << personal_infos_[i].family_name << "\t" << personal_infos_[i].first_name << "\t";
        outfile << personal_infos_[i].birth_date << "\t" << personal_infos_[i].gender << "\t" << contact_infos_[i].email << "\t";
        outfile << contact_infos_[i].phone_number << "\t" << home_addresses_[i].street << "\t" << home_addresses_[i].house_number << "\t";
        outfile << home_addresses_[i].postal_code << "\t" << home_addresses_[i].city << "\t" << personal_infos_[i].password << std::endl;
    }
}

void System::sign_in(){
    std::string email, password;
    int pos{-1};
    std::cout << "Enter your email: ";
    std::cin >> email;

    for (int i=0; i < number_of_data_; i++){
        if (email == contact_infos_[i].email){
            pos = i;
            break;
        }
    }

    if (pos == -1){
        std::cout << "This email is not registered!" << std::endl;
        return;
    }
    else{
        std::cout << "Enter your password: ";
        std::cin >> password;
        if (password == personal_infos_[pos].password){
            std::cout << "Welcome " << personal_infos_[pos].first_name << " " << personal_infos_[pos].family_name << "!" << std::endl;
        }
        else {
            std::cout << "The password is not correct!" << std::endl;
        }
    
    }
}

void System::print_data(){
    std::cout << "=============All Users Data=============" << std::endl;
    for (int i=0; i<number_of_data_; i++){
        std::cout << "Number: \t\t" << numbers_[i] << std::endl;
        std::cout << "Last Name: \t\t" << personal_infos_[i].family_name << std::endl;
        std::cout << "First Name: \t\t" << personal_infos_[i].first_name << std::endl;
        std::cout << "Birthday: \t\t" << personal_infos_[i].birth_date << std::endl;
        std::cout << "Gender: \t\t" << personal_infos_[i].gender << std::endl;
        std::cout << "E-Mail: \t\t" << contact_infos_[i].email << std::endl;
        std::cout << "Phone Number: \t\t" << contact_infos_[i].phone_number << std::endl;
        std::cout << "Street: \t\t" << home_addresses_[i].street << std::endl;
        std::cout << "House Number: \t\t" << home_addresses_[i].house_number << std::endl;
        std::cout << "City: \t\t\t" << home_addresses_[i].city << std::endl;
        std::cout << "Postal Code: \t\t" << home_addresses_[i].postal_code << std::endl;
        std::cout << "Password: \t\t" << personal_infos_[i].password << std::endl;
        std::cout << "=============" << std::endl;
    }
    std::cout << "========================================" << std::endl;
}

void System::read_data()
{
    std::ifstream file;
    file.open("/home/amiraliaali/self_projects/login_system/usersInfo.txt");
    std::getline(file, first_line_);
    std::string elements;
    int i = 0;
    while (file >> elements)
    {
        if (i == 0)
        {
            numbers_.push_back(std::stoi(elements));
        }
        else if (i == 1)
        {
            personal_infos_.push_back(PersonalInfo());
            personal_infos_[number_of_data_].family_name = elements;
        }
        else if (i == 2)
        {
            personal_infos_[number_of_data_].first_name = elements;
        }
        else if (i == 3)
        {
            personal_infos_[number_of_data_].birth_date = elements;
        }
        else if (i == 4)
        {
            personal_infos_[number_of_data_].gender = elements;
        }
        else if (i == 5)
        {
            contact_infos_.push_back(ContactInfo());
            contact_infos_[number_of_data_].email = elements;
        }
        else if (i == 6)
        {
            contact_infos_[number_of_data_].phone_number = elements;
        }
        else if (i == 7)
        {
            home_addresses_.push_back(HomeAddress());
            home_addresses_[number_of_data_].street = elements;
        }
        else if (i == 8)
        {
            home_addresses_[number_of_data_].house_number = elements;
        }
        else if (i == 9)
        {
            home_addresses_[number_of_data_].postal_code = std::stoi(elements);
        }
        else if (i == 10)
        {
            home_addresses_[number_of_data_].city = elements;
        }
        else if (i == 11)
        {
            personal_infos_[number_of_data_].password = elements;
        }
        i++;
        if (i == 12)
        {
            i = 0;
            number_of_data_++;
        }
    }
}



        
