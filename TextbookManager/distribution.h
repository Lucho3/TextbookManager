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
    const std::string& get_address() const;
    const std::string& get_phone_number() const;
    DistributionOwner& get_owner();
    void set_name();
    void set_address();
    void set_phone_number();
    void set_owner(const DistributionOwner&);
    std::vector<Textbook>& get_available_textbooks();
    void set_available_textbooks();
    std::ostream& print(std::ostream& os) const override;
};

#endif
