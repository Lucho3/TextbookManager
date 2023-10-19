#include "common.h"
#include <sstream>
#include <iostream>
#include <vector>
#include "author.h"
#include "textbook.h"

bool Common::checkDelimiter(std::istream& stream, char expectedDelimiter) {
	char delimiter;
	if (!(stream >> delimiter) || delimiter != expectedDelimiter) {
		return false;
	}
	return true;
}

bool Common::isValidDate(std::string& dateStr) {
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

bool Common::tryParseInt(const std::string& str, int& result) {
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

bool Common::tryParseDouble(const std::string& str, double& result) {
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

const int Common::getIntCommon(const std::string& prompt) {
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
	} while (!(tryParseInt(option, chosen) && chosen>=0));

	return chosen;
}

const double Common::getDoubleCommon(const std::string & prompt) {
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
	} while (!(tryParseDouble(option, chosen) && chosen >= 0));

	return chosen;
}

const std::string Common::getStringCommon(const std::string& prompt) {
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

const std::string Common::getDateCommon(const std::string& prompt) {
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



template <typename T>
void Common::fillListBySelection(std::vector<std::shared_ptr<T>> selection_list, std::vector<std::shared_ptr<T>>& items_to_fill) {
	std::system("cls");
	int len_of_cert = selection_list.size();
	if (len_of_cert) {
		for (int i = 0; i < len_of_cert; ++i) {
			std::cout << "Index: " << i << std::endl;
			std::cout << *selection_list[i] << std::endl;
		}
		std::cout << "Enter the indexes that you want separated by ', ': ";
		std::string input;
		std::getline(std::cin, input);

		std::vector<int> indexes;
		std::string token;
		std::stringstream ss(input);
		while (std::getline(ss, token, ',')) {
			int number = std::stoi(token);
			indexes.push_back(number);
		}

		for (int index : indexes) {
			if (index >= 0 && index < len_of_cert)
				items_to_fill.push_back(selection_list[index]);
			else
				std::cout << "Wrong index!";
		}
	}
}

template void Common::fillListBySelection<Author>(std::vector<std::shared_ptr<Author>> selection_list, std::vector<std::shared_ptr<Author>>& items_to_fill);
template void Common::fillListBySelection<Textbook>(std::vector<std::shared_ptr<Textbook>> selection_list, std::vector<std::shared_ptr<Textbook>>& items_to_fill);