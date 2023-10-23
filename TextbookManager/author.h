#ifndef AUTHOR_H
#define AUTHOR_H

#include "person.h" 

class Author : public Person {
private:
    int number_of_tb_published;
    std::string guild;
    std::ostream& print(std::ostream& os) const override;

    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Person>(*this);
        ar& this->number_of_tb_published;
        ar& this->guild;
    }
public:
    Author();
    Author(int);
    ~Author();
    const std::string& getGuild() const;
    const int getNumberOfTbPublished() const;
    void setGuild();
    void setNumberOfTbPublished();
    void printFullInformation() const;
};


#endif