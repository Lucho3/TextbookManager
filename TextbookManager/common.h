#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <vector>
#include <iostream>

class Common {
private:
	static bool checkDelimiter(std::istream&, char);
public:
	static bool isValidDate(std::string&);
	static bool tryParseInt(const std::string&, int&);
	static bool tryParseDouble(const std::string&, double&);
	static const int getIntCommon(const std::string&);
	static const std::string getStringCommon(const std::string&);
	static const std::string getDateCommon(const std::string&);
	static const double getDoubleCommon(const std::string&);
	template <typename T>
	static void fillListBySelection(std::vector<std::shared_ptr<T>>, std::vector<std::shared_ptr<T>>&);
};
#endif

