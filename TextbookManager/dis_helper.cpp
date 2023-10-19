#include "dis_helper.h"

bool DistributionHelper::isValidNumber(const std::string& number) {
    if (number.empty() || (number[0] != '+' && !isdigit(number[0]))) {
        return false;
    }

    for (int i = 1; i < number.length(); ++i) {
        if (!isdigit(number[i])) {
            return false;
        }
    }
	return true;
}
