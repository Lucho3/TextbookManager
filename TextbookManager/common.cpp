#include "common.h"
#include <sstream>
#include <iostream>
#include <vector>
#include "controller.h"
#include "certificate.h"
#include "author.h"
#include "distribution_owner.h"
#include "distribution.h"
#include "textbook.h"
#include "common.h"


bool checkDelimiter(std::istream& stream, char expectedDelimiter) {
	char delimiter;
	if (!(stream >> delimiter) || delimiter != expectedDelimiter) {
		return false;
	}
	return true;
}

bool isValidDate(std::string& dateStr) {
	int day, month, year;
	char delimiter;
	std::istringstream date_stream(dateStr);

	if (!(date_stream >> day) || !checkDelimiter(date_stream, ':') ||
		!(date_stream >> month) || !checkDelimiter(date_stream, ':') ||
		!(date_stream >> year)) {
		return false;
	}

	if (day < 1 || day > 31 || month < 1 || month > 12 ||
		year < 1900 || year > 2100) {
		return false;
	}

	dateStr = (day < 10 ? "0" : "") + std::to_string(day) + ":" +
		(month < 10 ? "0" : "") + std::to_string(month) + ":" +
		std::to_string(year);

	return true;
}

bool tryParseInt(const std::string& str, int& result) {
	try {
		result = std::stoi(str);
		return true;
	}
	catch (const std::invalid_argument& e) {
		return false;
	}
	catch (const std::out_of_range& e) {
		return false;
	}
}

bool tryParseDouble(const std::string& str, double& result) {
	try {
		result = std::stod(str);
		return true;
	}
	catch (const std::invalid_argument& e) {
		return false;
	}
	catch (const std::out_of_range& e) {
		return false;
	}
}

const int getIntCommon(const std::string& prompt) {
	std::cout << "Please enter " << prompt <<": ";
	std::string option;
	int counter = 0;
	int chosen;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter" << prompt << ": ";
		}
		getline(std::cin, option);
		counter++;
	} while (!(tryParseInt(option, chosen)));

	return chosen;
}

const double getDoubleCommon(const std::string& prompt) {
	std::cout << "Please enter " << prompt << ": ";
	std::string option;
	int counter = 0;
	double chosen;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter" << prompt << ": ";
		}
		getline(std::cin, option);
		counter++;
	} while (!(tryParseDouble(option, chosen)));

	return chosen;
}

const std::string getStringCommon(const std::string& prompt) {
	std::cout << "Please enter " << prompt << ": ";
	std::string new_value;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout << "Please reenter" << prompt << ": ";
		}
		std::getline(std::cin, new_value);
		counter++;
	} while (new_value.empty());

	return new_value;
}

const std::string getDateCommon(const std::string& prompt) {
	std::cout << "Please enter " << prompt << ": ";
	std::string new_date;
	int counter = 0;
	do {
		if (counter > 0) {
			std::system("cls");
			std::cout  << "Please reenter" << prompt << ": ";;
		}
		std::getline(std::cin, new_date);
		counter++;
	} while (!isValidDate(new_date));
	
	return new_date;
}

