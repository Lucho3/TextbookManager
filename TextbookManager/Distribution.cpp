#include "distribution.h"
#include "dis_helper.h"
#include "common.h"
#include <sstream>

Distribution::Distribution(std::vector<Textbook*>& list_of_tbs, std::vector<DistributionOwner*>& list_of_owners) {
    this->setName();
    this->setAddress();
    this->setOwner(list_of_owners);
    this->setPhoneNumber();
    this->setAvailableTextbooks(list_of_tbs);
}

Distribution::Distribution(const std::string& name, DistributionOwner* owner)
    : name(name), owner(owner) {
}

Distribution::~Distribution() {
    for (Textbook* tb : this->available_textbooks) {
        delete tb;
    }
    this->available_textbooks.clear();
    delete this->owner;
}

const std::string& Distribution::getAddress() const {
    return this->address;
}

void Distribution::setAddress() {
    std::system("cls");
    std::cout << "Please enter the address: ";
    std::string new_address;
    int counter = 0;
    do {
        if (counter > 0) {
            std::system("cls");
            std::cout << "Please reenter the address wrong type: ";
        }
        std::getline(std::cin, new_address);
        counter++;
    } while (new_address.empty());
    this->address = new_address;
}

const std::string& Distribution::getPhoneNumber() const {
    return this->phone_number;
}

void Distribution::setPhoneNumber() {
    std::system("cls");
    std::cout << "Please enter the phone number: ";
    std::string new_number;
    int counter = 0;
    do {
        if (counter > 0) {
            std::system("cls");
            std::cout << "Please reenter the phone number: ";
        }
        getline(std::cin, new_number);
        counter++;
    } while (!isValidNumber(new_number));
}

DistributionOwner* Distribution::getOwner() {
    return this->owner;
}

void Distribution::setOwner(std::vector<DistributionOwner*>& list_of_owners) {
    //really raw should be fixed prob
    std::system("cls");
    int len_of_cert = list_of_owners.size();
    if (len_of_cert) {
        for (int i = 0; i < len_of_cert ; ++i) {
            std::cout << i << ": " << *list_of_owners[i];
        }
        std::cout << "Enter the index of the owner that you want: ";
        std::string input;
        int index;
        int counter = 0;
        do {
            if (counter > 0) {
                std::system("cls");
                std::cout << "Please reenter the index wrong value: ";
            }
            getline(std::cin, input);
            counter++;
        } while (!(tryParseInt(input, index)));
        this->owner = list_of_owners[index];
    }
}

const std::string& Distribution::getName() const {
    return this->name;
}

std::vector<Textbook*>& Distribution::getAvailableTextbooks() {
    return this->available_textbooks;
}

void Distribution::setAvailableTextbooks(std::vector<Textbook*>& list_of_tbs) {
    //really raw should be fixed prob
    std::system("cls");
    int len_of_cert = list_of_tbs.size();
    if (len_of_cert) {
        for (int i = 0; i < len_of_cert; ++i) {
            std::cout << i << ": " << list_of_tbs[i]->getTitle();
        }
        std::cout << "\nEnter the indexes of the TB that you want separated by ', ': ";
        std::string input;
        std::getline(std::cin, input);
        std::vector<int> indexes;
        std::string token;
        std::stringstream ss(input);
        while (std::getline(ss, token, ',')) {
            int number = std::stoi(token);
            indexes.push_back(number);
        }

        for (int index : indexes) {
            this->available_textbooks.push_back(list_of_tbs[index]);
        }
    }
}

void Distribution::setName() {
    std::system("cls");
    std::cout << "Please enter the name: ";
    std::string new_name;
    int counter = 0;
    do {
        if (counter > 0) {
            std::system("cls");
            std::cout << "Please reenter the name: ";
        }
        getline(std::cin, new_name);
        counter++;
    } while (new_name.empty());
    this->name = new_name;
}

std::ostream& Distribution::print(std::ostream& os) const {
    os << "Name: " << name << ", Address: " << address << ", Phone Number: " << phone_number 
       << ", Distribution Owner: " << this->owner->getName() << std::endl;
    os << "\nAvailable Textbooks: ";

    for (const Textbook* textbook : available_textbooks) {;
        textbook->print(os);
    }
    return os;
}