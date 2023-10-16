#ifndef COMMON_H
#define COMMON_H

#include <string>

bool isValidDate(std::string& dateStr);
bool tryParseInt(const std::string& str, int& result);
bool tryParseDouble(const std::string& str, double& result);
const int getIntCommon(const std::string&);
const std::string getStringCommon(const std::string&);
const std::string getDateCommon(const std::string&);
const double getDoubleCommon(const std::string&);

#endif

