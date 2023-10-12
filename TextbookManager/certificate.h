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
	const std::string& get_name() const;
	void set_name();
	const std::string& get_assigner() const;
	void set_assigner();
	const std::string& get_date() const;
	void set_date();
	std::ostream& print(std::ostream& os) const override;
};

#endif
