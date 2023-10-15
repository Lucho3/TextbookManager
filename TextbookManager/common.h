#ifndef COMMON_H
#define COMMON_H

#include <string>

bool isValidDate(std::string& dateStr);
bool tryParseInt(const std::string& str, int& result);
bool tryParseDouble(const std::string& str, double& result);
int setInt(const std::string&);

#endif

