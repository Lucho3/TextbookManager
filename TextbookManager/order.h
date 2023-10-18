#ifndef ORDER_H
#define ORDER_H

#include "textbook.h"
#include "distribution.h"

class Order : public Base {
private:
    std::string date;
    std::vector<std::shared_ptr<Textbook>> textbooks_to_buy;
    std::shared_ptr<Distribution> distribution;
    double final_price;

    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& date;
        ar& textbooks_to_buy;
        ar& distribution;
        ar& final_price;
    }

public:
    Order();
    Order(std::vector<std::shared_ptr<Distribution>> list_of_distributions);
    ~Order();
    const std::string& getDate() const;
    void setDate();
    std::shared_ptr<Distribution> getDistribution();
    void setDistribution(std::vector<std::shared_ptr<Distribution>> list_of_distributions);
    const double getFinalPrice() const;
    std::vector<std::shared_ptr<Textbook>> getTextbooksToBuy();
    void calculateFinalPrice();
    void addTextbooksToOrder(std::vector<std::shared_ptr<Textbook>> list_of_tbs);
    void printFullInformation() const;
    std::ostream& print(std::ostream& os) const override;
};

#endif