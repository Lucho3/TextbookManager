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

std::ostream& Textbook::print(std::ostream& os) const {
	os << "Title: " << title << std::endl;
	os << "Authors: ";
	for (const Author& author : authors) {
		//os << author.get_name() << ", ";
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