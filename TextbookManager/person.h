#ifndef PERSON_H
#define PERSON_H

#include "base.h"


//abstract
class Person : public Base {
private:
    std::string name;
    int age;
    std::string gender;

    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& this->name;
        ar& this->age;
        ar& this->gender;
    }

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