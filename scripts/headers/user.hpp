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
    /**
     * @brief Get the personal info of the user
    */
    void user_input();

    /**
     * @brief Ask the user to repeat their input for email
    */
    void email_repetition();

    /**
     * @brief Ask the user to repeat their input for family name
    */
    void family_name_repetition();

    /**
     * @brief Ask the user to repeat their input for first name
    */
    void first_name_repetition();

    /**
     * @brief Ask the user to repeat their input for birth date
    */
    void birth_date_repetition();

    /**
     * @brief Ask the user to repeat their input for
    */
    void gender_repetition();

    /**
     * @brief Ask the user to repeat their input for phone number
    */
    void phone_number_repetition();

    /**
     * @brief Ask the user to repeat their input for street
    */
    void street_repetition();

    /**
     * @brief Ask the user to repeat their input for city
    */
    void city_repetition();

    /**
     * @brief Ask the user to repeat their input for house number
    */
    void house_number_repetition();

    /**
     * @brief Ask the user to repeat their input for postal code
    */
    void postal_code_repetition();

    /**
     * @brief Show all the input data to the user
    */
    void data_shower();

    /**
     * @brief Ask the user to repeat their input for password
    */
    void password_repetition();
};