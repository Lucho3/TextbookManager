#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "textbook.h"
#include "distribution.h"

class Order : public Base {
private:
    std::string date;
    std::vector<Textbook> textbooks_to_buy;
    Distribution distributor;
    double final_price;

public:
    Order();
    Order(const std::string& date, const Distribution& distributor);
    ~Order();
    const std::string& get_date() const;
    void set_date();
    Distribution& get_distributor();
    void set_distributor(const Distribution&);
    const double get_final_price() const;
    void set_final_price(double price);
    std::vector<Textbook>& get_textbooks_to_buy
    double calculate_final_price();
    void add_text_book_to_order();
    std::ostream& print(std::ostream& os) const override;
};

#endif
