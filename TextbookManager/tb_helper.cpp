#include <regex>
#include <sstream>
#include "tb_helper.h"

bool isValidISBN10(const std::string& isbn) {
	if (isbn.size() != 10) {
		return false;
	}

	int checksum = 0;
	for (int i = 0; i < 10; i++) {
		if (isbn[i] == 'X' && i == 9) {
			checksum += 10;
		}
		else if (isdigit(isbn[i])) {
			checksum += (isbn[i] - '0') * (10 - i);
		}
		else {
			return false;
		}
	}

	return (checksum % 11 == 0);
}

bool isValidISBN13(const std::string& isbn) {
	if (isbn.size() != 13 || !std::regex_match(isbn, std::regex(R"(\d{13})"))) {
		return false;
	}

	int checksum = 0;
	for (int i = 0; i < 12; i++) {
		checksum += (i % 2 == 0) ? (isbn[i] - '0') : 3 * (isbn[i] - '0');
	}

	int remainder = checksum % 10;
	int checkDigit = (10 - remainder) % 10;

	return (checkDigit == (isbn[12] - '0'));
}

bool isValidDate(const std::string& dateStr) {
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

	std::string formattedDateStr = (day < 10 ? "0" : "") + std::to_string(day) + ":" +
		(month < 10 ? "0" : "") + std::to_string(month) + ":" +
		std::to_string(year);

	return formattedDateStr == dateStr;
}

bool checkDelimiter(std::istream& stream, char expectedDelimiter) {
	char delimiter;
	if (!(stream >> delimiter) || delimiter != expectedDelimiter) {
		return false;
	}
	return true;
}