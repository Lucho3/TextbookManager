#ifndef ORDER_H
#define ORDER_H

#include "textbook.h"
#include "distribution.h"

class Order : public Base {
private:
    std::string date;
    std::vector<Textbook*> textbooks_to_buy;
    Distribution* distribution;
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
    Order(std::vector<Distribution*>& list_of_distributions);
    ~Order();
    const std::string& getDate() const;
    void setDate();
    Distribution* getDistribution();
    void setDistribution(std::vector<Distribution*>& list_of_distributions);
    const double getFinalPrice() const;
    std::vector<Textbook*>& getTextbooksToBuy();
    void calculateFinalPrice();
    void addTextbooksToOrder(std::vector<Textbook*>& list_of_tbs);
    std::ostream& print(std::ostream& os) const override;
};

#endif