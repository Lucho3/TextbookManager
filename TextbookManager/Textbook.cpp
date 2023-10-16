#include "textbook.h"
#include <regex>
#include <sstream>
#include "tb_helper.h"
#include "certificate.h"
#include "common.h"

Textbook::Textbook(std::vector<Author*>& authors) {
	this->setTitle();
	this->setReleaseDate();
	this->setPrice();
	this->setIssue();
	this->setISBN();
	this->setCirculation();
	this->setAuthors(authors);
}

Textbook::Textbook(std::string& title) :
	title(title) {

}

Textbook::~Textbook() {
	for (Author* a : this->authors) {
		delete a;
	}
	this->authors.clear();
	for (Certificate* c : this->certificates) {
		delete c;
	}
	this->certificates.clear();
}

const std::string& Textbook::getTitle() const {
	return this->title;
}

void Textbook::setTitle() {
	std::system("cls");
	this->title = getStringCommon("the title");
}

const int Textbook::getIssue() const {
	return this->issue;
}

void Textbook::setIssue() {
	std::system("cls");
	this->issue = getIntCommon("the issue");
}


const std::string& Textbook::getISBN() const {
	return this->ISBN;
}

//doesnt work should be fixed
void Textbook::setISBN() 
{
	std::system("cls");
	std::cout << "Please enter the ISBN: ";
	std::string new_ISBN;
	int counter = 0;
	bool (*validateFunction)(const std::string&);
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter the ISBN wrong format: ";
		}
		std::getline(std::cin, new_ISBN);
		if (new_ISBN.length() == 10)
			validateFunction = isValidISBN10;
		else if (new_ISBN.length() == 13)
			validateFunction = isValidISBN13;
		else
			validateFunction = [](const std::string& str) -> bool {
			return false;
		};
		counter++;
	} while (validateFunction(new_ISBN));
	this->ISBN = new_ISBN;
}

const int Textbook::getCirculation() const {
	return this->circulation;
}

void Textbook::setCirculation() {
	std::system("cls");
	this->circulation = getIntCommon("the circulation");
}

const double Textbook::getPrice() const {
	return this->price;
}

void Textbook::setPrice() {
	std::system("cls");
	this->price = getDoubleCommon("the price");
}

const std::string& Textbook::getReleaseDate() const {
	return this->release_date;
}

void Textbook::setReleaseDate() {
	std::system("cls");
	this->release_date = getDateCommon("the release date in format DD:MM:YYYY");
}

std::vector<Author*>& Textbook::getAuthors() {
	return this->authors;
}

void Textbook::setAuthors(std::vector<Author*>& authors) {
	//really raw should be fixed prob
	std::system("cls");
	int len_of_cert = authors.size();
	if (len_of_cert) {
		for (int i = 0; i < len_of_cert; ++i) {
			std::cout << "Index: " << i << std::endl;
			std::cout << *authors[i];
		}
		std::cout << "Enter the indexes of the authors that you want separated by ', ': ";
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
			this->authors.push_back(authors[index]);
		}
	}
}

std::vector<Certificate*>& Textbook::getCertificates() {
	return this->certificates;
}

void Textbook::setCertificate() {
	//On theory we need another class that holds the reference between the certificate and TB or a map in the TB
	this->certificates.push_back(new Certificate());
}

std::ostream& Textbook::print(std::ostream& os) const {
	os << "Title: " << title << std::endl;
	os << "Authors: ";
	for (const Author* author : authors) {
		os << author->getName() << ", ";
	}
	os << std::endl;
	os << "Issue: " << issue << std::endl;
	os << "ISBN: " << ISBN << std::endl;
	os << "Release Date: " << release_date << std::endl;
	os << "Circulation: " << circulation << std::endl;
	os << "Certificates: ";
	for (const Certificate* certificate : certificates) {
		os << certificate->getName() << ", ";
	}
	os << std::endl;
	os << "Price: " << price << std::endl;
	return os;
}