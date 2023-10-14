#include "distribution.h"

Distribution::Distribution() : name(""), owner(DistributionOwner()) {
}

Distribution::Distribution(const std::string& name, const DistributionOwner& owner)
    : name(name), owner(owner) {
}

Distribution::~Distribution() {
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
    return phone_number;
}

DistributionOwner& Distribution::getOwner() {
    return owner;
}

void Distribution::setName(const std::string& new_name) {
    name = new_name;
}



void Distribution::setPhoneNumber(const std::string& new_phone_number) {
    phone_number = new_phone_number;
}

void Distribution::setOwner(const DistributionOwner& new_owner) {
    owner = new_owner;
}

std::ostream& Distribution::print(std::ostream& os) const {
    os << "Name: " << name << ", Address: " << address << ", Phone Number: " << phone_number << std::endl;
    os << "Distribution Owner: ";
    owner.print(os);
    os << "\nAvailable Textbooks: ";
    for (const Textbook& textbook : available_textbooks) {
        os << "\n- ";
        textbook.print(os);
    }
    return os;
}