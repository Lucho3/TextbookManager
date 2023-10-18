#include "author.h"
#include "common.h"

Author::Author() {
	
}

Author::Author(int number) {
	std::cout << "Creted object number: " << number;
	this->setName();
	this->setGender();
	this->setAge();
	this->setNumberOfTbPublished();
	this->setGuild();
}

Author::~Author() {

}

const std::string& Author::getGuild() const {
    return this->guild;
}

void Author::setGuild() {
	std::system("cls");
	this->guild = getStringCommon("the guild");
}

const int Author::getNumberOfTbPublished() const {
    return this->number_of_tb_published;
}

void Author::setNumberOfTbPublished() {
	std::system("cls");
	this->number_of_tb_published = getIntCommon("the number of published TB");
}

void Author::printFullInformation() const {
	std::cout << "Author Information:" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Gender: " << this->getGender() << std::endl;
	std::cout << "Age: " << this->getAge() << " years" << std::endl;
	std::cout << "Number of Textbooks Published: " << this->getNumberOfTbPublished() << std::endl;
	std::cout << "Guild: " << this->getGuild() << std::endl;
	std::cout << std::endl;
}

std::ostream& Author::print(std::ostream& os) const {
	os << "Name: " << this->getName()  << ", Guild: " << this->guild << std::endl;
	return os;
}