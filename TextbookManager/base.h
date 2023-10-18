#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <vector>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/access.hpp>

class Base {
private:
    virtual std::ostream& print(std::ostream& os) const = 0;
public:
    friend std::ostream& operator<<(std::ostream& os, const Base& base);
};

#endif