#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base {
private:
    virtual std::ostream& print(std::ostream& os) const = 0;
public:
    std::ostream& operator<<(std::ostream& os);
};

#endif