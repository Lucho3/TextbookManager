#include "author.h"
#include "common.h"

Author::Author()  {
	this->setName();
	this->setGender();
	this->setAge();
	this->setNumberOfTbPublished();
	this->setGuild();
}

Author::Author(const std::string & name, int age, const std::string& gender, const std::string & guild)
    : Person(name, age, gender), number_of_tb_published(0), guild(guild) {
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

std::ostream& Author::print(std::ostream& os) const {
	os << "Name: " << this->getName()  << ", Guild: " << this->guild << std::endl;
	return os;
}