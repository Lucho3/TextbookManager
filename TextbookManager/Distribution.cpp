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
    this->address = Common::getStringCommon("the address");
}

const std::string& Distribution::getPhoneNumber() const {
    return this->phone_number;
}

void Distribution::setPhoneNumber() {
    std::system("cls");
    this->phone_number = Common::getStringCommon("the phone number");
    while (!DistributionHelper::isValidNumber(this->phone_number)) {
        this->phone_number = Common::getStringCommon("the phone number");
    }
}

std::shared_ptr<DistributionOwner> Distribution::getOwner() {
    return this->owner;
}

void Distribution::setOwner(std::vector<std::shared_ptr<DistributionOwner>> list_of_owners) {
    std::system("cls");
    int len_of_cert = list_of_owners.size();
    if (len_of_cert) {
        for (int i = 0; i < len_of_cert ; ++i) {
            std::cout << "Index: " << i << std::endl;
            std::cout << *list_of_owners[i] << std::endl;
            std::cout << std::endl;
        }  
        std::cout << std::endl;
        int index = Common::getIntCommon("the index of the owner that you want");
        if (index >= 0 && index < len_of_cert)
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
    Common::fillListBySelection(list_of_tbs, this->available_textbooks);
}

void Distribution::setName() {
    std::system("cls");
    this->name = Common::getStringCommon("the name");
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
    std::cout << *textbook;
        os << std::endl;
    }
    return os;
}