#ifndef DISTRIBUTORS_H
#define DISTRIBUTORS_H

#include <string>
#include <vector>
#include "textbook.h"
#include "distribution_owner.h"

class Distribution : public Base {
private:
    std::string name;
    std::string address;
    std::string phone_number;
    DistributionOwner owner;
    std::vector<Textbook> available_textbooks;

public:
    Distribution();
    Distribution(const std::string& name, const DistributionOwner& owner);
    ~Distribution();
    const std::string& getAddress() const;
    const std::string& getPhoneNumber() const;
    DistributionOwner& getOwner();
    void setName();
    void setAddress();
    void setPhoneNumber();
    void setOwner(const DistributionOwner&);
    std::vector<Textbook>& getAvailableTextbooks();
    void setAvailableTextbooks();
    std::ostream& print(std::ostream& os) const override;
};

#endif
