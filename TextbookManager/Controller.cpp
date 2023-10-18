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

Controller::Controller() : certificates_list() {
    
}

void Controller::ClearLists() {
    for (Textbook* tb : this->textbooks_list) {
        delete tb;
    }
    this->textbooks_list.clear();

    for (Certificate* c : this->certificates_list) {
        delete c;
    }
    this->certificates_list.clear();

    for (Distribution* d : this->distributions_list) {
        delete d;
    }
    this->distributions_list.clear();

    for (DistributionOwner* dio : this->distribution_owners_list) {
        delete dio;
    }
    this->distribution_owners_list.clear();

    for (Author* a : this->authors_list) {
        delete a;
    }
    this->authors_list.clear();
}

Controller::~Controller() {
    this->ClearLists();
}

void Controller::createNewElement(const std::string& element) {
    if(element == "Distribution Owner")
        this->distribution_owners_list.push_back(new DistributionOwner(5));
    else if (element == "Author")
        this->authors_list.push_back(new Author(5));
    else if (element == "Textbook")
        this->textbooks_list.push_back(new Textbook(this->authors_list));
    else if (element == "Distribution")
        this->distributions_list.push_back(new Distribution(this->textbooks_list, this->distribution_owners_list));
    else if (element == "Order")
        this->order_list.push_back(new Order(this->distributions_list));
}

void Controller::printAllElements(const std::string& element) {
    std::system("cls");
    if (element == "Distribution Owner")
        for (DistributionOwner* dio : this->distribution_owners_list)
            std::cout << *dio << "\n";
    else if (element == "Author")
        for (Author* a : this->authors_list)
            std::cout << *a << "\n";
    else if (element == "Textbook")
        for (Textbook* t : this->textbooks_list)
            std::cout << *t << "\n";
    else if (element == "Distribution")
        for (Distribution* dis : this->distributions_list)
            std::cout << *dis << "\n";
    else if (element == "Order")
        for (Order* o : this->order_list)
            std::cout << *o << "\n";
}

void Controller::finishOrder() {
    std::system("cls");
    for (int i = 0; i < this->order_list.size(); ++i) {
        std::cout << "Index: " << i << std::endl;
        std::cout << *this->order_list[i];
    }
    std::cout << std::endl;
    int index = getIntCommon("your choice");
    this->order_list[index]->calculateFinalPrice();
    std::cout << "The final price is: ";
    std::cout << this->order_list[index]->getFinalPrice() << std::endl;
    delete this->order_list[index];
    this->order_list.erase(this->order_list.begin() + index);

}

void Controller::addTextBookToOrder() {
    std::system("cls");
    for (int i = 0; i < this->order_list.size(); ++i) {
        std::cout << "Index: " << i << std::endl;
        std::cout << "Date of the order: " << this->order_list[i]->getDate() << std::endl;
        std::cout << "Name of the distribution: " << this->order_list[i]->getDistribution()->getName() << std::endl;;
    }

    int index = getIntCommon("your choice");
    std::cout << std::endl;
    this->order_list[index]->addTextbooksToOrder(this->order_list[index]->getDistribution()->getAvailableTextbooks());
}

void Controller::addCertificteToTextbook() {
    std::system("cls");
    for (int i = 0; i < this->textbooks_list.size(); ++i) {
        std::cout << "Index: " << i << std::endl;
        std::cout << "Textbook title:" << this->textbooks_list[i]->getTitle() << std::endl;
    }

    int index = getIntCommon("your choice");
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
T Controller::deserializeFromBinaryFile(const std::string& fileName) {
    T data;
    std::ifstream inputFile(fileName, std::ios::binary);
    boost::archive::text_iarchive inputArchive(inputFile);
    inputArchive >> data;
    return data;
}

void Controller::loadVectorsFromFile() {
    this->ClearLists();
    this->authors_list = deserializeFromBinaryFile<std::vector<Author*>>("authors.dat");
    this->certificates_list = deserializeFromBinaryFile<std::vector<Certificate*>>("certificates.dat");
    this->distribution_owners_list = deserializeFromBinaryFile<std::vector<DistributionOwner*>>("owners.dat");
    this->distributions_list = deserializeFromBinaryFile<std::vector<Distribution*>>("distributions.dat");
    this->textbooks_list = deserializeFromBinaryFile<std::vector<Textbook*>>("textbooks.dat");
    this->order_list = deserializeFromBinaryFile<std::vector<Order*>>("orders.dat");
}

