#include "textbook.h"
#include <regex>
#include "tb_helper.h"
#include "certificate.h"
#include "common.h"

Textbook::Textbook() {

}

Textbook::Textbook(std::string& title) :
	title(title) {

}

Textbook::~Textbook() {
	//TODO fix
	this->authors.clear();
	this->certificates.clear();
}

const std::string& Textbook::getTitle() const {
	return this->title;
}

void Textbook::setTitle() {
	std::cin.clear();
	std::cin.ignore(100, '\n');
	std::cout << "Please enter the title: ";
	std::string new_title;
	int counter = 0;
	do
	{
		if (counter > 0)
		std::cout << "\nPlease reenter the title wrong type: ";
		std::cin >> new_title;
		counter++;
	} while (new_title.empty());
	this->title = new_title;
}

//TODO: authors to do 

const int Textbook::getIssue() const {
	return this->issue;
}

void Textbook::setIssue() {
	std::cin.clear();
	std::cin.ignore(100, '\n');
	std::cout << "Please enter the issue: ";
	while (!(std::cin >> this->issue));
	{
		std::cout << "\nPlease reenter the issue wrong type: ";
	}
}


const std::string& Textbook::getISBN() const {
	return this->ISBN;
}

void Textbook::setISBN() 
{
    std::cin.clear();
    std::cin.ignore(100, '\n');
	std::cout << "Please enter the ISBN: ";
	std::string new_ISBN;
	int counter = 0;
	bool (*validateFunction)(const std::string&);
	do
	{
		if (counter > 0)
		std::cout << "\nPlease reenter the ISBN wrong format: ";
		std::cin >> new_ISBN;
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
	std::cin.clear();
	std::cin.ignore(100, '\n');
	std::cout << "Please enter the circulation: ";
	while (!(std::cin >> this->circulation));
	{
		std::cout << "\nPlease reenter the circulation wrong type: ";
	}
}

const double Textbook::getPrice() const {
	return this->price;
}

void Textbook::setPrice() {
	std::cin.clear();
	std::cin.ignore(100, '\n');
	std::cout << "Please enter the price: ";
	while (!(std::cin >> this->price) || this->price <= 0);
	{
		std::cout << "\nPlease reenter the price wrong type: ";
	}
}

const std::string& Textbook::getReleaseDate() const {
	return this->release_date;
}

void Textbook::setReleaseDate() {
	std::cin.clear();
	std::cin.ignore(100, '\n');
	std::cout << "Please enter the release date in format DD:MM:YYYY: ";
	std::string new_date;
	int counter = 0;
	do
	{
		if (counter > 0)
			std::cout << "\nPlease reenter the date wrong format: ";
		std::cin >> new_date;
		counter++;
	} while (!isValidDate(new_date));
	this->release_date = new_date;
}

std::ostream& Textbook::print(std::ostream& os) const {
	os << "Title: " << title << std::endl;
	os << "Authors: ";
	for (const Author& author : authors) {
		os << author.get_name() << ", ";
	}
	os << std::endl;
	os << "Issue: " << issue << std::endl;
	os << "ISBN: " << ISBN << std::endl;
	os << "Release Date: " << release_date << std::endl;
	os << "Circulation: " << circulation << std::endl;
	os << "Certificates: ";
	for (const Certificate& certificate : certificates) {
		os << certificate.getName() << ", ";
	}
	os << std::endl;
	os << "Price: " << price << std::endl;
	return os;
}