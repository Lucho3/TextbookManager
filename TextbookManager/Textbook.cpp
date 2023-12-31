#include "textbook.h"
#include <regex>
#include <sstream>
#include "tb_helper.h"
#include "certificate.h"
#include "common.h"

Textbook::Textbook() {

}

Textbook::Textbook(std::vector<std::shared_ptr<Author>> authors) {
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
	for (auto& a : this->authors) {
		a.reset();
	}
	this->authors.clear();
	for (auto& c : this->certificates) {
	    c.reset();
	}
	this->certificates.clear();
}

const std::string& Textbook::getTitle() const {
	return this->title;
}

void Textbook::setTitle() {
	std::system("cls");
	this->title = Common::getStringCommon("the title");
}

const int Textbook::getIssue() const {
	return this->issue;
}

void Textbook::setIssue() {
	std::system("cls");
	this->issue = Common::getIntCommon("the issue");
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
			validateFunction = TextbookHelper::isValidISBN10;
		else if (new_ISBN.length() == 13)
			validateFunction = TextbookHelper::isValidISBN13;
		else {
			validateFunction = [](const std::string& str) -> bool {
				return false;
			};
		}
		counter++;
	} while (!validateFunction(new_ISBN));
	this->ISBN = new_ISBN;
}

const int Textbook::getCirculation() const {
	return this->circulation;
}

void Textbook::setCirculation() {
	std::system("cls");
	this->circulation = Common::getIntCommon("the circulation");
}

const double Textbook::getPrice() const {
	return this->price;
}

void Textbook::setPrice() {
	std::system("cls");
	this->price = Common::getDoubleCommon("the price");
}

const std::string& Textbook::getReleaseDate() const {
	return this->release_date;
}

void Textbook::setReleaseDate() {
	std::system("cls");
	this->release_date = Common::getDateCommon("the release date in format DD:MM:YYYY");
}

std::vector<std::shared_ptr<Author>> Textbook::getAuthors() {
	return this->authors;
}

void Textbook::setAuthors(std::vector<std::shared_ptr<Author>> authors) {
	Common::fillListBySelection(authors, this->authors);
}

void Textbook::printFullInformation() const {
	std::cout << "Textbook Information:" << std::endl;
	std::cout << "Title: " << this->getTitle() << std::endl;
	std::cout << "Issue: " << this->getIssue() << std::endl;
	std::cout << "ISBN: " << this->getISBN() << std::endl;
	std::cout << "Release Date: " << this->getReleaseDate() << std::endl;
	std::cout << "Circulation: " << this->getCirculation() << " copies" << std::endl;
	std::cout << "Price: $" << this->getPrice() << std::endl;

	std::cout << "Authors:" << std::endl;
	for (const auto& author : authors) {
		std::cout << "  Author Name: " << author->getName() << std::endl;
	}

	std::cout << "Certificates:" << std::endl;
	for (const auto& certificate : certificates) {
		std::cout << "  Certificate Name: " << certificate->getName() << std::endl;
		std::cout << "  Assigner: " << certificate->getAssigner() << std::endl;
		std::cout << "  Date: " << certificate->getDate() << std::endl;
	}
	std::cout << std::endl;
}

std::vector<std::shared_ptr<Certificate>> Textbook::getCertificates() {
	return this->certificates;
}

void Textbook::setCertificate() {
	//On theory we need another class that holds the reference between the certificate and TB or a map in the TB
	this->certificates.push_back(std::make_shared<Certificate>(1));
}

std::ostream& Textbook::print(std::ostream& os) const {
	os << "Title: " << title << std::endl;
	os << "Authors: ";
	for (const auto& author : authors) {
		os << author->getName() << ", ";
	}
	os << std::endl;
	os << "Issue: " << issue << std::endl;
	os << "ISBN: " << ISBN << std::endl;
	os << "Release Date: " << release_date << std::endl;
	os << "Circulation: " << circulation << std::endl;
	os << "Certificates: ";
	for (const auto& certificate : certificates) {
		os << certificate->getName() << ", ";
	}
	os << std::endl;
	os << "Price: " << price << std::endl;
	return os;
}