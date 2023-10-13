#ifndef OWNER_H
#define OWNER_H

#include <string>
#include "person.h"

class DistributionOwner : public Person {
private:
    double salary;
    int days_owner;

public:
    DistributionOwner();
    DistributionOwner(const std::string& name, double salary);
    ~DistributionOwner();
    const double getSalary() const;
    const int getDaysOwner() const;
    void setDaysOwner();
    void setSalary();
    std::ostream& print(std::ostream& os) const override;
};

#endif
