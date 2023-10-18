#ifndef DISTRIBUTORS_H
#define DISTRIBUTORS_H

#include "textbook.h"
#include "distribution_owner.h"

class Distribution : public Base {
private:
    std::string name;
    std::string address;
    std::string phone_number;
    std::shared_ptr<DistributionOwner> owner;
    std::vector<std::shared_ptr<Textbook>> available_textbooks;

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
    Distribution(std::vector<std::shared_ptr<Textbook>> list_of_tbs, std::vector<std::shared_ptr<DistributionOwner>> list_of_owners);
    Distribution(const std::string& name, std::shared_ptr<DistributionOwner> owner);
    ~Distribution();
    const std::string& getAddress() const;
    const std::string& getPhoneNumber() const;
    const std::string& getName() const;
    std::shared_ptr<DistributionOwner> getOwner();
    void setName();
    void setAddress();
    void setPhoneNumber();
    void setOwner(std::vector<std::shared_ptr<DistributionOwner>>);
    std::vector<std::shared_ptr<Textbook>> getAvailableTextbooks();
    void setAvailableTextbooks(std::vector<std::shared_ptr<Textbook>>);
    void printFullInformation() const;
    std::ostream& print(std::ostream& os) const override;
};

#endif
