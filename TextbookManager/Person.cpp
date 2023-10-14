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
	std::cout << "Please enter the name of the person: ";
	std::string new_name;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "The name should not be empty: ";
		}
		std::getline(std::cin, new_name);
		counter += 1;

	} while (new_name.empty());
	this->name = new_name;
}


const int Person::getAge() const {
	return this->age;
}


void Person::setAge() {
	std::system("cls");
	std::cout << "Please enter the age: ";
	std::string input;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter the age wrong value: ";
		}
		getline(std::cin, input);
		counter++;
	} while (!(tryParseInt(input, this->age)));
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