#ifndef CERTIFICATE_H
#define CERTIFICATE_H

#include <iostream>
#include <vector>
#include "base.h"

class Certificate : public Base {
private:
	std::string name;
	std::string assigner;
	std::string date_earned;
public:
	Certificate();
	Certificate(std::string&);
	~Certificate();
	const std::string& getName() const;
	void setName();
	const std::string& getAssigner() const;
	void setAssigner();
	const std::string& getDate() const;
	void setDate();
	std::ostream& print(std::ostream& os) const override;
};


#endif
