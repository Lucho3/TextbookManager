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
	std::cout << "Please enter the title: ";
	std::string new_title;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter the title wrong type: ";
		}
		std::getline(std::cin, new_title);
		counter++;
	} while (new_title.empty());
	this->title = new_title;
}

//TODO: authors to do 

const int Textbook::getIssue() const {
	return this->issue;
}

void Textbook::setIssue() {
	std::system("cls");
	std::string input;
	std::cout << "Please enter the issue: ";
	int counter=0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter the issue wrong type: ";
		}
		getline(std::cin, input);
		counter++;
	} while (!(tryParseInt(input, this->issue)));
}


const std::string& Textbook::getISBN() const {
	return this->ISBN;
}

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
	std::cout << "Please enter the circulation: ";
	std::string input;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter the circulation wrong type: ";
		}
		getline(std::cin, input);
		counter++;
	} while (!(tryParseInt(input, this->circulation)));
}

const double Textbook::getPrice() const {
	return this->price;
}

void Textbook::setPrice() {
	std::system("cls");
	std::cout << "Please enter the price: ";
	std::string input;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter the price wrong type: ";
		}
		getline(std::cin, input);
		counter++;
	} while (!(tryParseDouble(input, this->price)));
}

const std::string& Textbook::getReleaseDate() const {
	return this->release_date;
}

void Textbook::setReleaseDate() {
	std::system("cls");
	std::cout << "Please enter the release date in format DD:MM:YYYY: ";
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
	this->release_date = new_date;
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
			std::cout << i << ": " << authors[i]->getName() << " Guild: " << authors[i]->getGuild() << std::endl;
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