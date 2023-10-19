#include "Order.h"
#include "Textbook.h" // Include the header for the Textbook class
#include <iostream>
#include <sstream>
#include "common.h"

Order::Order() {

}

Order::Order(std::vector<std::shared_ptr<Distribution>> list_of_distributions)
    : final_price(0.0) {
    this->setDate();
    this->setDistribution(list_of_distributions);
}

Order::~Order() {
    this->distribution.reset();
    for (auto& tb : this->textbooks_to_buy) {
        tb.reset();
    }

}

const std::string& Order::getDate() const {
    return this->date;
}

void Order::setDate() {
    std::system("cls");
    this->date = Common::getDateCommon("the date of the orderin format DD:MM:YYYY");
}

std::shared_ptr<Distribution> Order::getDistribution() {
    return this->distribution;
}

void Order::setDistribution(std::vector<std::shared_ptr<Distribution>> list_of_distributions) {
    //really raw should be fixed prob
    std::system("cls");
    int len_of_cert = list_of_distributions.size();
    if (len_of_cert) {
        for (int i = 0; i < len_of_cert; ++i) {
            std::cout << "Index: " << i << std::endl;
            std::cout << "Name: " << list_of_distributions[i]->getName();
        }
        std::cout << std::endl;
        this->distribution = list_of_distributions[Common::getIntCommon("the index of the distribution that you want")];
    }
}

const double Order::getFinalPrice() const {
    return this->final_price;
}


std::vector<std::shared_ptr<Textbook>> Order::getTextbooksToBuy() {
    return this->textbooks_to_buy;
}

void Order::calculateFinalPrice() {

    for (const auto& tb : this->textbooks_to_buy) {
        this->final_price += tb->getPrice();
   }
}

void Order::addTextbooksToOrder(std::vector<std::shared_ptr<Textbook>> list_of_tbs) {
    Common::fillListBySelection(list_of_tbs, this->textbooks_to_buy);
}

void Order::printFullInformation() const {
    std::cout << "Order Date: " << date << std::endl;
    std::cout << "Textbooks to Buy:" << std::endl;
    for (const auto& textbook : textbooks_to_buy) {
        std::cout << "  - " << textbook->getTitle() << " (ISBN: " << textbook->getISBN() << ")" << std::endl;
    }
    std::cout << "Distribution: " << distribution->getName() << std::endl;
    std::cout << "Final Price: " << final_price << std::endl;
    std::cout << std::endl;
}

std::ostream& Order::print(std::ostream& os) const {
    os << "Order Date: " << date << std::endl;
    os << "Distribution Name: " << this->distribution->getName() << std::endl;
    os << "Textbooks: ";
    os << std::endl;
    for (const auto& textbook : textbooks_to_buy) {
        os << "Title: " << textbook->getTitle();
        os << std::endl;
    }
    return os;
}