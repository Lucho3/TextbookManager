#include <iostream>
#include "distribution_owner.h"
#include "common.h" 

DistributionOwner::DistributionOwner() {

}

DistributionOwner::DistributionOwner(int number) {
	std::cout << "Creted object number: " << number;
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
	this->salary = Common::getDoubleCommon("enter the salary");
}

const int DistributionOwner::getDaysOwner() const {
    return days_owner;
}

void DistributionOwner::setDaysOwner() {
	std::system("cls");
	this->days_owner = Common::getIntCommon("number days ownership");
}

void DistributionOwner::printFullInformation() const {
	std::cout << "Owner Information:" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Gender: " << this->getGender() << std::endl;
	std::cout << "Age: " << this->getAge() << " years" << std::endl;
	std::cout << "Days as Owner: " << this->getDaysOwner() << " days" << std::endl;
	std::cout << "Salary: $" << this->getSalary() << std::endl;
	std::cout << std::endl;
}

std::ostream& DistributionOwner::print(std::ostream& os) const {
	os << "Name: " << this->getName() << ", Days Owner: " << this->days_owner << std::endl;
	return os;
}