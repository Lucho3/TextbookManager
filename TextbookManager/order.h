#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "textbook.h"
#include "distribution.h"

class Order : public Base {
private:
    std::string date;
    std::vector<Textbook*> textbooks_to_buy;
    Distribution* distribution;
    double final_price;

public:
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