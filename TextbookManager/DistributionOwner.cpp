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
	this->salary = getDoubleCommon("enter the salary");
}

const int DistributionOwner::getDaysOwner() const {
    return days_owner;
}

void DistributionOwner::setDaysOwner() {
	std::system("cls");
	this->days_owner = getIntCommon("number days ownership");
}

std::ostream& DistributionOwner::print(std::ostream& os) const {
	os << "Name: " << this->getName() << ", Days Owner: " << this->days_owner << std::endl;
	return os;
}