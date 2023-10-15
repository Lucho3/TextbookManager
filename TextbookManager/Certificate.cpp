#include "certificate.h"
#include "common.h"

Certificate::Certificate() {
	this->setName();
	this->setAssigner();
	this->setDate();
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
	std::system("cls");
	std::cout << "Please enter the name of the certificate: ";
	std::string new_name;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "The name should not be empty: ";
		}
		std::getline(std::cin,new_name);
		counter+=1;

	} while (new_name.empty());
	this->name = new_name;
}

const std::string& Certificate::getAssigner() const {
	return this->assigner;
}

void Certificate::setAssigner() {
	std::system("cls");
	std::cout << "Please enter the name of the company assigner: ";
	std::string new_assigner;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "\nThe name should not be empty: ";
		}
		std::getline(std::cin, new_assigner);
		counter++;
	} while (new_assigner.empty());
	this->assigner = new_assigner;
}

const std::string& Certificate::getDate() const {
	return this->date_earned;
}

void Certificate::setDate() {
	std::system("cls");
	std::cout << "Please enter the date in format DD:MM:YYYY: ";
	std::string new_date;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "\nPlease reenter the date wrong format: ";
		}
		std::getline(std::cin, new_date);
		counter++;
	} while (!isValidDate(new_date));
	this->date_earned = new_date;
}

std::ostream& Certificate::print(std::ostream& os) const {
	std::system("cls");
	os << "Certificate Name: " << this->name << ", Date Earned:: " << this->date_earned << std::endl;
	return os;
}