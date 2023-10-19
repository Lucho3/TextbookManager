#include "person.h"
#include "common.h"

Person::Person() {

}

Person::Person(const std::string& name, int age, const std::string& gender)
    : name(name), age(age), gender(gender) {
    
}

Person::~Person() {

}

const std::string& Person::getName() const {
    return name;
}

void Person::setName() {
	std::system("cls");
	this->name = Common::getStringCommon("the name of the person");
}


const int Person::getAge() const {
	return this->age;
}


void Person::setAge() {
	std::system("cls");
	this->age = Common::getIntCommon("the age of the person");
}

const std::string& Person::getGender() const {
    return this->gender;
}

void Person::setGender() {
	std::system("cls");
	std::cout << "Please enter the gender - male/female: ";
	std::string new_gender;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "The gender should be male or female: ";
		}
		std::getline(std::cin, new_gender);
		counter += 1;

	} while (!(new_gender == "male" || new_gender == "female"));
	this->gender = new_gender;
}