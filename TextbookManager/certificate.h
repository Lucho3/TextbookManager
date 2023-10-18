#ifndef CERTIFICATE_H
#define CERTIFICATE_H

#include "base.h"

class Certificate : public Base {
private:
	std::string name;
	std::string assigner;
	std::string date_earned;

	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& this->name;
		ar& this->assigner;
		ar& this->date_earned;
	}
public:
	Certificate();
	Certificate(int);
	Certificate(std::string&);
	~Certificate();
	const std::string& getName() const;
	void setName();
	const std::string& getAssigner() const;
	void setAssigner();
	const std::string& getDate() const;
	void setDate();
	void printFullInformation() const;
	std::ostream& print(std::ostream& os) const override;
};
#endif
