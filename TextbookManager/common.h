#ifndef COMMON_H
#define COMMON_H

#include <string>

bool isValidDate(const std::string& dateStr);
bool tryParseInt(const std::string& str, int& result);
bool tryParseDouble(const std::string& str, double& result);

#endif

