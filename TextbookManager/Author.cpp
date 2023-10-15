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
	std::cout << "Please enter the guild: ";
	std::string new_guild;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter the guild wrong type: ";
		}
		std::getline(std::cin, new_guild);
		counter++;
	} while (new_guild.empty());
	this->guild = new_guild;
}

const int Author::getNumberOfTbPublished() const {
    return this->number_of_tb_published;
}



void Author::setNumberOfTbPublished() {
	std::system("cls");
	std::cout << "Please enter the number of published TB: ";
	std::string input;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter the number wrong type: ";
		}
		getline(std::cin, input);
		counter++;
	} while (!(tryParseInt(input, this->number_of_tb_published)));
}

std::ostream& Author::print(std::ostream& os) const {
	std::system("cls");
	os << "Name: " << this->getName()  << ", Guild: " << this->guild << std::endl;
	return os;
}