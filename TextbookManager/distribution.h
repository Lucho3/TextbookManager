#ifndef DISTRIBUTORS_H
#define DISTRIBUTORS_H

#include "textbook.h"
#include "distribution_owner.h"

class Distribution : public Base {
private:
    std::string name;
    std::string address;
    std::string phone_number;
    DistributionOwner* owner;
    std::vector<Textbook*> available_textbooks;

    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& name;
        ar& address;
        ar& phone_number;
        ar& owner;
        ar& available_textbooks;
    }

public:
    Distribution();
    Distribution(std::vector<Textbook*>& list_of_tbs, std::vector<DistributionOwner*>& list_of_owners);
    Distribution(const std::string& name, DistributionOwner* owner);
    ~Distribution();
    const std::string& getAddress() const;
    const std::string& getPhoneNumber() const;
    const std::string& getName() const;
    DistributionOwner* getOwner();
    void setName();
    void setAddress();
    void setPhoneNumber();
    void setOwner(std::vector<DistributionOwner*>& list_of_owners);
    std::vector<Textbook*>& getAvailableTextbooks();
    void setAvailableTextbooks(std::vector<Textbook*>& list_of_tbs);
    std::ostream& print(std::ostream& os) const override;
};

#endif
