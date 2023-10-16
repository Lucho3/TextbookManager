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
    this->address = getStringCommon("the address");
}

const std::string& Distribution::getPhoneNumber() const {
    return this->phone_number;
}

void Distribution::setPhoneNumber() {
    std::system("cls");
    this->phone_number = getIntCommon("the phone number");
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
            std::cout << "Index: " << i << std::endl;
            std::cout << *list_of_owners[i];
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
            std::cout << "Index: " << i << std::endl;
            std::cout << "Title: " << list_of_tbs[i]->getTitle() << std::endl;
        }
        std::cout << "Enter the indexes of the TB that you want separated by ', ': ";
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
    this->name = getStringCommon("the name");
}

std::ostream& Distribution::print(std::ostream& os) const {
    os << "Name: " << name << ", Address: " << address << ", Phone Number: " << phone_number << std::endl;
    os << "Distribution Owner: " << this->owner->getName() << std::endl;
    os << "Available Textbooks:\n";

    for (const Textbook* textbook : available_textbooks) {;
        textbook->print(os);
        os << std::endl;
    }
    return os;
}