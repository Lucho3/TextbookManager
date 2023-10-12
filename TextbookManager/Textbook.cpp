#include "textbook.h"
#include <regex>
#include "tb_helper.h"

Textbook::Textbook() {

}

Textbook::Textbook(std::string& title) :
	title(title) {

}

Textbook::~Textbook() {
	this->authors.clear();
	this->certificates.clear();
}

const std::string& Textbook::get_title() const {
	return this->title;
}

void Textbook::set_title() {
	std::cout << "Please enter the title: ";
	std::string new_title;
	int counter = 0;
	do
	{
		if (counter > 0)
			std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Please reenter the title wrong type: ";
		std::cin >> new_title;
		counter++;
	} while (new_title.empty());
	this->title = new_title;
}

//TODO: authors to do 

const int Textbook::get_issue() const {
	return this->issue;
}

void Textbook::set_issue() {
	std::cout << "Please enter the issue: ";
	while (!(std::cin >> this->issue));
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Please reenter the issue wrong type: ";
	}
}


const std::string& Textbook::get_ISBN() const {
	return this->ISBN;
}

void Textbook::set_ISBN() {
	std::cout << "Please enter the ISBN: ";
	std::string new_ISBN;
	int counter = 0;
	bool (*validate_function)(const std::string&);
	do
	{
		if (counter > 0)
			std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Please reenter the ISBN wrong format: ";
		std::cin >> new_ISBN;
		if (new_ISBN.length() == 10)
			validate_function = isValidISBN10;
		else if (new_ISBN.length() == 13)
			validate_function = isValidISBN13;
		else
			validate_function = [](const std::string& str) -> bool {
			return false;
		};
		counter++;
	} while (validate_function(new_ISBN));
	this->ISBN = new_ISBN;
}

const int Textbook::get_circulation() const {
	return this->circulation;
}

void Textbook::set_circulation() {
	std::cout << "Please enter the circulation: ";
	while (!(std::cin >> this->circulation));
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Please reenter the circulation wrong type: ";
	}
}

const double Textbook::get_price() const {
	return this->price;
}

void Textbook::set_price() {
	std::cout << "Please enter the price: ";
	while (!(std::cin >> this->price) || this->price <= 0);
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Please reenter the price wrong type: ";
	}
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
		os << certificate.get_name() << ", ";
	}
	os << std::endl;
	os << "Price: " << price << std::endl;
	return os;
}