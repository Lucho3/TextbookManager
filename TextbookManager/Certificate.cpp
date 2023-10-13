#include "certificate.h"
#include "common.h"

Certificate::Certificate() {

}

Certificate::Certificate(std::string& name) :
	name(name) {

}

Certificate::~Certificate() {
}

const std::string& Certificate::getName() const {
	return this->name;
}

void Certificate::setName() {
	std::cin.clear();
	std::cin.ignore(100, '\n');
	std::cout << "Please enter the name of the certificate: ";
	std::string new_name;
	int counter = 0;
	do
	{
		if (counter > 0)
			std::cout << "\nThe name should not be empty: ";
		std::cin >> new_name;
		counter++;
	} while (new_name.empty());
	this->name = new_name;
}

const std::string& Certificate::getAssigner() const {
	return this->assigner;
}

void Certificate::setAssigner() {
	std::cin.clear();
	std::cin.ignore(100, '\n');
	std::cout << "Please enter the name of the company assigner: ";
	std::string new_name;
	int counter = 0;
	do
	{
		if (counter > 0)
			std::cout << "\nThe name should not be empty: ";
		std::cin >> new_name;
		counter++;
	} while (new_name.empty());
	this->assigner = new_name;
}

const std::string& Certificate::getDate() const {
	return this->date_earned;
}

void Certificate::setDate() {
	std::cin.clear();
	std::cin.ignore(100, '\n');
	std::cout << "Please enter the date in format DD:MM:YYYY: ";
	std::string new_date;
	int counter = 0;
	do
	{
		if (counter > 0)
			std::cout << "\nPlease reenter the date wrong format: ";
		std::cin >> new_date;
		counter++;
	} while (!isValidDate(new_date));
	this->date_earned = new_date;
}

std::ostream& Certificate::print(std::ostream& os) const {
	os << "Certificate Name: " << name << "\n";
	os << "Assigner: " << assigner << "\n";
	os << "Date Earned: " << date_earned << "\n";
	return os;
}