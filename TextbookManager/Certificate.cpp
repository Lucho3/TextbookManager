#include "certificate.h"
#include "common.h"

Certificate::Certificate() {

}

Certificate::Certificate(int number) {
	std::cout << "Creted object number: " << number;
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
	this->name = getStringCommon("the name of the certificate");
}

const std::string& Certificate::getAssigner() const {
	return this->assigner;
}

void Certificate::setAssigner() {
	std::system("cls");
	this->assigner = getStringCommon("the name the name of the company assigner");
}

const std::string& Certificate::getDate() const {
	return this->date_earned;
}

void Certificate::setDate() {
	std::system("cls");
	this->date_earned = getDateCommon("the date in format DD:MM:YYYY");
}

void Certificate::printFullInformation() const {
	std::cout << "Certificate Information:" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Assigner: " << this->getAssigner() << std::endl;
	std::cout << "Date: " << this->getDate() << std::endl;
	std::cout << std::endl;
}

std::ostream& Certificate::print(std::ostream& os) const {
	std::system("cls");
	os << "Certificate Name: " << this->name << ", Date Earned:: " << this->date_earned << std::endl;
	return os;
}