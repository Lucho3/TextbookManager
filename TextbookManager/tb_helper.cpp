#include <regex>
#include "tb_helper.h"

bool TextbookHelper::isValidISBN10(const std::string& isbn) {
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

bool TextbookHelper::isValidISBN13(const std::string& isbn) {
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

