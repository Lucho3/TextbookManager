#include "common.h"
#include <sstream>


bool checkDelimiter(std::istream& stream, char expectedDelimiter) {
	char delimiter;
	if (!(stream >> delimiter) || delimiter != expectedDelimiter) {
		return false;
	}
	return true;
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