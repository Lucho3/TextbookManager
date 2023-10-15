#include <iostream>
#include "distribution_owner.h"
#include "common.h" 

DistributionOwner::DistributionOwner() {
	this->setName();
	this->setGender();
	this->setAge();
	this->setDaysOwner();
	this->setSalary();
}

DistributionOwner::DistributionOwner(const std::string& name, int age, const std::string& gender, double salary)
    : Person(name, age, gender), salary(salary), days_owner(0) {
}

DistributionOwner::~DistributionOwner() {
}

const double DistributionOwner::getSalary() const {
    return salary;
}

void DistributionOwner::setSalary() {
	std::system("cls");
	std::cout << "Please enter the salary: ";
	std::string input;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter the salary wrong type: ";
		}
		getline(std::cin, input);
		counter++;
	} while (!(tryParseDouble(input, this->salary)));
}

const int DistributionOwner::getDaysOwner() const {
    return days_owner;
}

void DistributionOwner::setDaysOwner() {
	std::system("cls");
	std::cout << "Please enter number days ownership: ";
	std::string input;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter the days owner: ";
		}
		getline(std::cin, input);
		counter++;
	} while (!(tryParseInt(input, this->days_owner)));
}

std::ostream& DistributionOwner::print(std::ostream& os) const {
    os << ", Salary: " << salary << ", Days Owner: " << days_owner;
	return os;
}