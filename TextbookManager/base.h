#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base {
public:
    virtual std::ostream& print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Base& obj);
};

#endif