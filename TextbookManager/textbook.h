#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include <iostream>
#include <vector>
#include "certificate.h"
#include "base.h"
#include "author.h"

class Textbook : public Base {
private:
	std::string title;
	std::vector<Author> authors;
	int issue;
	std::string ISBN;
	std::string release_date;
	int circulation;
	std::vector<Certificate> certificates;
	double price;
public:
	Textbook();
	Textbook(std::string&);
	~Textbook();
	const std::string& get_title() const;
	void set_title();
	std::vector<Author>& get_authors();
	void set_authors();
	const int get_issue() const;
	void set_issue();
	const std::string& get_ISBN() const;
	void set_ISBN();
	const std::string& get_release_date() const;
	void set_release_date();
	const int get_circulation() const;
	void set_circulation();
	std::vector<Certificate>& get_certificates();
	void set_certificates();
	const double get_price() const;
	void set_price();
	std::ostream& print(std::ostream& os) const override;
};
#endif