#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string path_to_data = "/Users/amiraliaali/Documents/Coding/c++Projects/loginSystem/usersInfo.txt";

class UserInfo{
    friend class System;
private:
    string familyName, firstName, birthDate;
    string sex, email, phoneNumber;
    string street, city, houseNumber;
    string password;
    int postalCode, number{};
public:
    void userInput();
    void emailRepetition();
    void familyNameRepetition();
    void firstNameRepetition();
    void birthDateRepetition();
    void sexRepetition();
    void phoneNumberRepetition();
    void streetRepetition();
    void cityRepetition();
    void houseNumberRepetition();
    void postalCodeRepetition();
    void dataShower();
    void passwordRepetition();
};

void UserInfo::dataShower(){
    cout << "Überlegen Sie bitte Ihre Eingaben noch einmal:" << endl;
    cout << "1- Name: " << familyName << endl;
    cout << "2- Vorname: " << firstName << endl;
    cout << "3- Geburtsdatum: " << birthDate << endl;
    cout << "4- Geschlecht: " << sex << endl;
    cout << "5- Email: " << email << endl;
    cout << "6- Telefon-Nummer: " << phoneNumber << endl;
    cout << "7- Straße: " << street << endl;
    cout << "8- Hausnummer: " << houseNumber << endl;
    cout << "9- Stadt: " << city << endl;
    cout << "10- PLZ: " << postalCode << endl;
    cout << "11- Passwort: " << password << endl;
}

void UserInfo::passwordRepetition(){
    cout << "Geben Sie bitte das neue Passwort ein: ";
    cin >> password;
}

void UserInfo::postalCodeRepetition(){
    cout << "Geben Sie bitte die neue PLZ ein: ";
    cin >> postalCode;
}

void UserInfo::houseNumberRepetition(){
    cout << "Geben Sie bitte die neue Hausnummer ein: ";
    cin >> houseNumber;
}

void UserInfo::cityRepetition(){
    cout << "Geben Sie bitte die neue Stadt ein: ";
    cin >> city;
}

void UserInfo::streetRepetition(){
    cout << "Geben Sie bitte die neue Straße ein: ";
    cin >> street;
}

void UserInfo::phoneNumberRepetition(){
    cout << "Geben Sie bitte die neue Telefonnummer ein: ";
    cin >> phoneNumber;
}

void UserInfo::sexRepetition(){
    cout << "Geben Sie bitte das neue Geschlecht ein: ";
    cin >> sex;
}

void UserInfo::birthDateRepetition(){
    cout << "Geben Sie bitte das neue Geburtsdatum ein: ";
    cin >> birthDate;
}

void UserInfo::firstNameRepetition(){
    cout << "Geben Sie bitte den neuen Vorname ein: ";
    cin >> firstName;
}

void UserInfo::familyNameRepetition(){
    cout << "Geben Sie bitte den neuen Name ein: ";
    cin >> familyName;
}

void UserInfo::emailRepetition(){
    cout << "Geben Sie bitte die neue Email-Adresse ein: ";
    cin >> email;
}

void UserInfo :: userInput(){
    cout << "Name: ";
    cin >> familyName;
    cout << "Vorname: ";
    cin >> firstName;
    cout << "Geburtsdatum(dd.mm.yyyy): ";
    cin >> birthDate;
    cout << "Geschlecht(m/w/x): ";
    cin >> sex;
    cout << "Email-Adresse: ";
    cin >> email;
    cout << "Telefon-Nummer(015xxxxxxxxx): ";
    cin >> phoneNumber;
    cout << "Straße: ";
    cin >> street;
    cout << "Hausnummer: ";
    cin >> houseNumber;
    cout << "PLZ: ";
    cin >> postalCode;
    cout << "Stadt: ";
    cin >> city;
    cout << "Passwort: ";
    cin >> password;
}


class System{
private:
    vector <int> numbers;
    vector <string> familyNames;
    vector <string> firstNames;
    vector <string> birthDates;
    vector <string> sex;
    vector <string> emails;
    vector <string> phoneNumbers;
    vector <string> streets;
    vector <string> houseNumbers;
    vector <string> cities;
    vector <string> passwords;
    vector <int> postalCodes;
    int numberOfData{};
    string firstLine;
public:
    System();
    void newUser();
    void printData();
    void fileWriter();
    void signIn();
};

System::System(){
    ifstream infile(path_to_data);
    getline(infile, firstLine);
    string elements;
    int i =0;
    while (infile >> elements){
        if (i == 0){
            numbers.push_back(stoi(elements));
        }
        else if (i == 1){
            familyNames.push_back(elements);
        }
        else if (i == 2){
            firstNames.push_back(elements);
        }
        else if (i == 3){
            birthDates.push_back(elements);
        }
        else if (i == 4){
            sex.push_back(elements);
        }
        else if (i == 5){
            emails.push_back(elements);
        }
        else if (i == 6){
            phoneNumbers.push_back(elements);
        }
        else if (i == 7){
            streets.push_back(elements);
        }
        else if (i == 8){
            houseNumbers.push_back(elements);
        }
        else if (i == 9){
            postalCodes.push_back(stoi(elements));
        }
        else if (i == 10){
            cities.push_back(elements);
        }
        else {
            passwords.push_back(elements);
        }
        i++;
        if (i==12){i = 0; numberOfData+=1;}
    }
}

void System::signIn(){
    string givenEmail;
    string givenPass;
    int pos{-1};
    cout << "Email-Adresse: ";
    cin >> givenEmail;
    for (int i=0; i < numberOfData; i++){
        if (emails[i] == givenEmail){
            pos = i;
        }
    }
    if (pos == -1){

        cout << "Die eingegebene Email-Adresse existiert nicht in unserem System. Bitte nochmal versuchen." << endl;
        signIn();
    }
    else{

        cout << "Passwort: ";
        cin >> givenPass;
        if (passwords[pos] == givenPass){
            cout << "Willkommen!!" << endl;
        }
        else {
            cout << "Das eingegebene Passwort passt nicht zu der Email-Adresse. Bitte nochmal versuchen." << endl;
            signIn();
        }
    }

}


void System::fileWriter(){
    ofstream outfile(path_to_data);
    outfile << firstLine << endl;
    for (int i=0; i<numberOfData; i++){
        outfile << numbers[i] << "\t" << familyNames[i] << "\t" << firstNames[i] << "\t";
        outfile << birthDates[i] << "\t" << sex[i] << "\t" << emails[i] << "\t";
        outfile << phoneNumbers[i] << "\t" << streets[i] << "\t" << houseNumbers[i] << "\t";
        outfile << postalCodes[i] << "\t" << cities[i] << "\t" << passwords[i] <<endl;
    }
}


void System::printData(){
    cout << "=============All Users Data=============" << endl;
    cout << firstLine << endl;
    for (int i=0; i<numberOfData; i++){
        cout << numbers[i] << "\t" << familyNames[i] << "\t" << firstNames[i] << "\t";
        cout << birthDates[i] << "\t" << sex[i] << "\t" << emails[i] << "\t";
        cout << phoneNumbers[i] << "\t" << streets[i] << "\t" << houseNumbers[i] << "\t";
        cout << postalCodes[i] << "\t" << cities[i] << "\t" << passwords[i] <<endl;
    }
    cout << "========================================" << endl;

}

void System::newUser(){
    UserInfo newuser;
    newuser.userInput();
    for (int i=0; i < emails.size(); i++){
        while (emails[i] == newuser.email){
            cout << "Sorry, diese Email-Adresse ist schon angemeldet. Bitte geben Sie eine andere Email-Adresse ein." << endl;
            newuser.emailRepetition();
            i = 0;
        }
    }
    int userIn{100};
    do{
        newuser.dataShower();
        cout << "Wenn Sie etwas ändern wollen, bitte geben Sie Ihre gewünschte Nummer ein. Ansonten bitte geben Sie die Nummer 0 ein: ";
        cin >> userIn;
        switch (userIn) {
            case 1:
                newuser.familyNameRepetition();
                break;
            case 2:
                newuser.firstNameRepetition();
                break;
            case 3:
                newuser.birthDateRepetition();
                break;
            case 4:
                newuser.sexRepetition();
                break;
            case 5:
                newuser.emailRepetition();
                break;
            case 6:
                newuser.phoneNumberRepetition();
                break;
            case 7:
                newuser.streetRepetition();
                break;
            case 8:
                newuser.houseNumberRepetition();
                break;
            case 9:
                newuser.postalCodeRepetition();
                break;
            case 10:
                newuser.cityRepetition();
                break;
            case 11:
                newuser.passwordRepetition();
                break;
            default:
                break;
        }
    } while (userIn != 0);
    
    newuser.number = numberOfData;
    numbers.push_back(newuser.number);
    familyNames.push_back(newuser.familyName);
    firstNames.push_back(newuser.firstName);
    birthDates.push_back(newuser.birthDate);
    sex.push_back(newuser.sex);
    emails.push_back(newuser.email);
    phoneNumbers.push_back(newuser.phoneNumber);
    streets.push_back(newuser.street);
    houseNumbers.push_back(newuser.houseNumber);
    cities.push_back(newuser.city);
    postalCodes.push_back(newuser.postalCode);
    passwords.push_back(newuser.password);
    numberOfData +=1;
}


int main(void){
    System mainSystem;
    int userChoice{};
    do{
        cout << "============================================" << endl;
        cout << "Willkommen zu meinem System. Was wollen Sie?" << endl;
        cout << "1- Anmelden\n2- Registirien\n3- Exit" << endl;
        cout << "Ihre Wahl: ";
        cin >> userChoice;
        if (userChoice == 1){
            mainSystem.signIn();
        }
        else if (userChoice == 2)
            mainSystem.newUser();
        else
            mainSystem.printData();
    }while(userChoice != 3);
    mainSystem.fileWriter();
    return 0;
}


