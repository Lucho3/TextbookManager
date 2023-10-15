#include "Order.h"
#include "Textbook.h" // Include the header for the Textbook class
#include <iostream>
#include <sstream>
#include "common.h"

Order::Order(std::vector<Distribution*>& list_of_distributions)
    : final_price(0.0) {
    this->setDate();
    this->setDistribution(list_of_distributions);
}

Order::~Order() {
    delete this->distribution;
    for (Textbook* tb : this->textbooks_to_buy) {
        delete tb;
    }

}

const std::string& Order::getDate() const {
    return this->date;
}

void Order::setDate() {
    std::system("cls");
    std::cout << "Please enter the date of the orderin format DD:MM:YYYY: ";
    std::string new_date;
    int counter = 0;
    do {
        if (counter > 0) {
            std::system("cls");
            std::cout << "Please reenter the date wrong format: ";
        }
        std::getline(std::cin, new_date);
        counter++;
    } while (!isValidDate(new_date));
    this->date = new_date;
}

Distribution* Order::getDistribution() {
    return this->distribution;
}

void Order::setDistribution(std::vector<Distribution*>& list_of_distributions) {
    //really raw should be fixed prob
    std::system("cls");
    int len_of_cert = list_of_distributions.size();
    if (len_of_cert) {
        for (int i = 0; i < len_of_cert; ++i) {
            std::cout << "\nIndex: " << i ;
            std::cout <<  list_of_distributions[i]->getName();
        }

        this->distribution = list_of_distributions[setInt("the index of the distribution that you want")];
    }
}

const double Order::getFinalPrice() const {
    return this->final_price;
}


std::vector<Textbook*>& Order::getTextbooksToBuy() {
    return this->textbooks_to_buy;
}

void Order::calculateFinalPrice() {

    for (Textbook* tb : this->textbooks_to_buy) {
        this->final_price += tb->getPrice();
   }
}

void Order::addTextbooksToOrder(std::vector<Textbook*>& list_of_tbs) {
    //really raw should be fixed prob
    std::system("cls");
    int len_of_cert = list_of_tbs.size();
    if (len_of_cert) {

        for (int i = 0; i < len_of_cert; ++i) {
            std::cout << "Index: " << i << std::endl;
            std::cout << *list_of_tbs[i];
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
            this->textbooks_to_buy.push_back(list_of_tbs[index]);
        }
    }
}

std::ostream& Order::print(std::ostream& os) const {
    os << "Order Date: " << date << std::endl;
    os << "Distribution Name: " << this->distribution->getName() << std::endl;
    os << "\nTextbooks: ";
    for (Textbook* textbook : textbooks_to_buy) {
        os << textbook->getTitle();
    }
    return os;
}