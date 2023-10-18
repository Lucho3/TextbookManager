#include "distribution.h"
#include "dis_helper.h"
#include "common.h"
#include <sstream>

Distribution::Distribution() {

}

Distribution::Distribution(std::vector<std::shared_ptr<Textbook>> list_of_tbs, std::vector<std::shared_ptr<DistributionOwner>> list_of_owners) {
    this->setName();
    this->setAddress();
    this->setOwner(list_of_owners);
    this->setPhoneNumber();
    this->setAvailableTextbooks(list_of_tbs);
}

Distribution::Distribution(const std::string& name, std::shared_ptr<DistributionOwner> owner)
    : name(name), owner(owner) {
}

Distribution::~Distribution() {
    for (auto& tb : this->available_textbooks) {
        tb.reset();
    }
    this->available_textbooks.clear();
    this->owner.reset();
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
    this->phone_number = getStringCommon("the phone number");
}

std::shared_ptr<DistributionOwner> Distribution::getOwner() {
    return this->owner;
}

void Distribution::setOwner(std::vector<std::shared_ptr<DistributionOwner>> list_of_owners) {
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

std::vector<std::shared_ptr<Textbook>> Distribution::getAvailableTextbooks() {
    return this->available_textbooks;
}

void Distribution::setAvailableTextbooks(std::vector<std::shared_ptr<Textbook>> list_of_tbs) {
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

void Distribution::printFullInformation() const {
    std::cout << "Distribution Information:" << std::endl;
    std::cout << "Name: " << this->getName() << std::endl;
    std::cout << "Address: " << this->getAddress() << std::endl;
    std::cout << "Phone Number: " << this->getPhoneNumber() << std::endl;

    if (owner != nullptr) {
        std::cout << "Owner Information:" << std::endl;
        std::cout << "  Name: " << owner->getName() << std::endl;
        std::cout << "  Gender: " << owner->getGender() << std::endl;
        std::cout << "  Age: " << owner->getAge() << " years" << std::endl;
        std::cout << "  Days as Owner: " << owner->getDaysOwner() << " days" << std::endl;
        std::cout << "  Salary: $" << owner->getSalary() << std::endl;
    }

    std::cout << "Available Textbooks:" << std::endl;
    for (const auto& textbook : available_textbooks) {
        std::cout << "  Title: " << textbook->getTitle() << std::endl;
    }
    std::cout << std::endl;
}

std::ostream& Distribution::print(std::ostream& os) const {
    os << "Name: " << name << ", Address: " << address << ", Phone Number: " << phone_number << std::endl;
    os << "Distribution Owner: " << this->owner->getName() << std::endl;
    os << "Available Textbooks:\n";

    for (const auto& textbook : available_textbooks) {;
        textbook->print(os);
        os << std::endl;
    }
    return os;
}