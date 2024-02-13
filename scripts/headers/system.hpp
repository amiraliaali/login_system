#include "user.hpp"
#include <iostream>
#include <vector>
#include <string>

class System{
private:
    std::vector <int> numbers_;
    std::vector <HomeAddress> home_addresses_;
    std::vector <PersonalInfo> personal_infos_;
    std::vector <ContactInfo> contact_infos_;
    int number_of_data_;
    std::string first_line_;

public:
    System() : number_of_data_(0), first_line_("") {read_data();}
    /**
     * @brief Read user data from file
    */
    void read_data();

    /**
     * @brief Add new user to the system
    */
    void new_user();

    /**
     * @brief Print user data table
    */
    void print_data();

    /**
     * @brief Save the current data to the file
    */
    void file_writer();

    /**
     * @brief Attempt to sign in a user
    */
    void sign_in();
};