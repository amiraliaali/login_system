#include <string>
#include <cstring>

struct HomeAddress{
    std::string street;
    std::string city;
    std::string house_number;
    int postal_code;

    // Default constructor
    HomeAddress() : street(""), city(""), house_number(""), postal_code(0) {}
};

struct PersonalInfo{
    int number;
    std::string family_name;
    std::string first_name;
    std::string birth_date;
    std::string gender;
    std::string password;

    // Default constructor
    PersonalInfo() : number(0), family_name(""), first_name(""), birth_date(""), gender(""), password("") {}
};

struct ContactInfo{
    std::string email;
    std::string phone_number;

    // Default constructor
    ContactInfo() : email(""), phone_number("") {}
};

class UserInfo
{
    friend class System;

private:
    PersonalInfo personal_info_;
    ContactInfo contact_info_;
    HomeAddress home_address_;

public:
    void user_input();
    void email_repetition();
    void family_name_repetition();
    void first_name_repetition();
    void birth_date_repetition();
    void gender_repetition();
    void phone_number_repetition();
    void street_repetition();
    void city_repetition();
    void house_number_repetition();
    void postal_code_repetition();
    void data_shower();
    void password_repetition();
};