#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include "person.h"

class Author : public Person {
private:
    int number_of_tb_published;
    std::string guild;
    std::ostream& print(std::ostream& os) const override;
public:
    Author();
    Author(const std::string& name, int age, const std::string& gender, const std::string& guild);
    ~Author();
    const std::string& getGuild() const;
    const int getNumberOfTbPublished() const;
    void setGuild();
    void setNumberOfTbPublished();

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& this->number_of_tb_published;
        ar& this->guild;
    }
};

#endif