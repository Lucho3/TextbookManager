#include "controller.h"
#include "certificate.h"
#include "author.h"
#include "distribution_owner.h"
#include "distribution.h"
#include "textbook.h"
#include "common.h"
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

Controller::Controller() {
}

template <typename Container>
void Controller::ClearList(Container& container) {
    for (auto& item : container) {
        item.reset();
    }
    container.clear();
}

void Controller::ClearLists() {
    this->ClearList(this->textbooks_list);
    this->ClearList(this->certificates_list);
    this->ClearList(this->distributions_list);
    this->ClearList(this->distribution_owners_list);
    this->ClearList(this->authors_list);
}

Controller::~Controller() {
    this->ClearLists();
}

void Controller::createNewElement(const std::string& element) {
    if (element == "Distribution Owner") {
        this->distribution_owners_list.push_back(std::make_shared<DistributionOwner>(1));
    }
    else if (element == "Author") {
        this->authors_list.push_back(std::make_shared<Author>(1));
    }
    else if (element == "Textbook") {
        this->textbooks_list.push_back(std::make_shared<Textbook>(this->authors_list));
    }
    else if (element == "Distribution") {
        this->distributions_list.push_back(std::make_shared<Distribution>(this->textbooks_list, this->distribution_owners_list));
    }
    else if (element == "Order") {
        this->order_list.push_back(std::make_shared<Order>(this->distributions_list));
    }
}

void Controller::printAllElements(const std::string& element) {
    std::system("cls");
    if (element == "Distribution Owner")
        for (const auto& dio : this->distribution_owners_list)
            dio->printFullInformation();
    else if (element == "Author")
        for (const auto& a : this->authors_list)
            a->printFullInformation();
    else if (element == "Textbook")
        for (const auto& t : this->textbooks_list)
            t->printFullInformation();
    else if (element == "Distribution")
        for (const auto& dis : this->distributions_list)
            dis->printFullInformation();
    else if (element == "Order")
        for (const auto& o : this->order_list)
            o->printFullInformation();
}

void Controller::finishOrder() {
    std::system("cls");
    for (int i = 0; i < this->order_list.size(); ++i) {
        std::cout << "Index: " << i << std::endl;
        std::cout << *this->order_list[i];
        std::cout << std::endl;
    }
    std::cout << std::endl;
    int index = Common::getIntCommon("your choice");
    this->order_list[index]->calculateFinalPrice();
    std::cout << "The final price is: ";
    std::cout << this->order_list[index]->getFinalPrice() << std::endl;
    this->order_list[index].reset();
    this->order_list.erase(this->order_list.begin() + index);

}

void Controller::addTextBookToOrder() {
    std::system("cls");
    for (int i = 0; i < this->order_list.size(); ++i) {
        std::cout << "Index: " << i << std::endl;
        std::cout << "Date of the order: " << this->order_list[i]->getDate() << std::endl;
        std::cout << "Name of the distribution: " << this->order_list[i]->getDistribution()->getName() << std::endl;;
    }

    int index = Common::getIntCommon("your choice");
    std::cout << std::endl;
    this->order_list[index]->addTextbooksToOrder(this->order_list[index]->getDistribution()->getAvailableTextbooks());
}

void Controller::addCertificteToTextbook() {
    std::system("cls");
    for (int i = 0; i < this->textbooks_list.size(); ++i) {
        std::cout << "Index: " << i << std::endl;
        std::cout << "Textbook title:" << this->textbooks_list[i]->getTitle() << std::endl;
        std::cout << std::endl;
    }

    int index = Common::getIntCommon("your choice");
    this->textbooks_list[index]->setCertificate();
}

template <typename T>
void Controller::serializeToBinaryFile(const std::string& fileName, const T& data) {
    std::ofstream outputFile(fileName, std::ios::binary);
    boost::archive::text_oarchive outputArchive(outputFile);
    outputArchive << data;
}

void Controller::saveVectorsToFile() {
    this->serializeToBinaryFile("authors.dat", this->authors_list);
    this->serializeToBinaryFile("certificates.dat", this->certificates_list);
    this->serializeToBinaryFile("owners.dat", this->distribution_owners_list);
    this->serializeToBinaryFile("distributions.dat", this->distributions_list);
    this->serializeToBinaryFile("textbooks.dat", this->textbooks_list);
    this->serializeToBinaryFile("orders.dat", this->order_list);
}

template <typename T>
std::vector<std::shared_ptr<T>> Controller::deserializeFromBinaryFile(const std::string& fileName) {
    std::vector<std::shared_ptr<T>> data;
    std::ifstream inputFile(fileName, std::ios::binary);
    boost::archive::text_iarchive inputArchive(inputFile);
    inputArchive >> data;
    return data;
}

void Controller::loadVectorsFromFile() {
    this->ClearLists();
    this->authors_list = deserializeFromBinaryFile<Author>("authors.dat");
    this->certificates_list = deserializeFromBinaryFile<Certificate>("certificates.dat");
    this->distribution_owners_list = deserializeFromBinaryFile<DistributionOwner>("owners.dat");
    this->distributions_list = deserializeFromBinaryFile<Distribution>("distributions.dat");
    this->textbooks_list = deserializeFromBinaryFile<Textbook>("textbooks.dat");
    this->order_list = deserializeFromBinaryFile<Order>("orders.dat");
}

