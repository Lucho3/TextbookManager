#ifndef OWNER_H
#define OWNER_H

#include "person.h"

class DistributionOwner : public Person {
private:
    double salary;
    int days_owner;

    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Person>(*this);
        ar& this->salary;
        ar& this->days_owner;
    }

public:
    DistributionOwner();
    DistributionOwner(int);
    DistributionOwner(const std::string& name, int age, const std::string& gender, double salary);
    ~DistributionOwner();
    const double getSalary() const;
    const int getDaysOwner() const;
    void setDaysOwner();
    void setSalary();
    std::ostream& print(std::ostream& os) const override;
};

#endif
