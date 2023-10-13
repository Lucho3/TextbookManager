#include "base.h"

std::ostream& Base::operator<<(std::ostream& os) {
    return this->print(os);
}