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
    const double get_salary() const;
    const int get_days_owner() const;
    void set_days_owner();
    void set_salary();
    std::ostream& print(std::ostream& os) const override;
};

#endif
