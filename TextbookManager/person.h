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
    ~Person();
    const std::string& getName() const;
    const int getAge() const;
    const std::string& getGender() const;
    void setName();
    void setAge();
    void setGender();
};

#endif