#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include "person.h"

class Author : public Person {
private:
    int number_of_tb_published;
    std::string guild;

public:
    Author();
    Author(const std::string& name, const std::string& guild);
    ~Author();
    const std::string& get_guild() const;
    const int get_number_of_tb_published() const;
    void set_guild();
    void set_number_of_tb_published();
    std::ostream& print(std::ostream& os) const override;
};

#endif