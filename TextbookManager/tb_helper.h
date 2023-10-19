#ifndef TBHELPER_H
#define TBHELPER_H

#include <string>

class TextbookHelper {
public:
	static bool isValidISBN10(const std::string&);
	static bool isValidISBN13(const std::string&);
};

#endif