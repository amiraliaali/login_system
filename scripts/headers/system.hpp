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
    void read_data();
    void new_user();
    void print_data();
    void file_writer();
    void sign_in();
};