#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "base.h"

//abstract
class Person : public Base {
private:
    std::string name;
    int age;
    std::string gender;

public:
    Person();
    Person(const std::string& name, int age, const std::string& gender);
    //TODO ~Person();
    const std::string& get_name() const;
    const int get_age() const;
    const std::string& get_gender() const;
    void set_name();
    void set_age();
    void set_gender();
};

class person
{
};

#endif