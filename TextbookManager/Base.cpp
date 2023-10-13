#include "base.h"

std::ostream& operator<<(std::ostream& os, const Base& obj) {
    return obj.print(os);
}