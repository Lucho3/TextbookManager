#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include "certificate.h"
#include "base.h"
#include "author.h"

class Textbook : public Base {
private:
	std::string title;
	std::vector<std::shared_ptr<Author>> authors;
	int issue;
	std::string ISBN;
	std::string release_date;
	int circulation;
	std::vector<std::shared_ptr<Certificate>> certificates;
	double price;

	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& title;
		ar& authors;
		ar& issue;
		ar& ISBN;
		ar& release_date;
		ar& circulation;
		ar& certificates;
		ar& price;
	}
public:
	Textbook();
	Textbook(std::vector<std::shared_ptr<Author>>);
	Textbook(std::string&);
	~Textbook();
	const std::string& getTitle() const;
	void setTitle();
	std::vector<std::shared_ptr<Author>> getAuthors();
	void setAuthors(std::vector<std::shared_ptr<Author>>);
	const int getIssue() const;
	void setIssue();
	const std::string& getISBN() const;
	void setISBN();
	const std::string& getReleaseDate() const;
	void setReleaseDate();
	const int getCirculation() const;
	void setCirculation();
	std::vector<std::shared_ptr<Certificate>> getCertificates();
	void setCertificate();
	const double getPrice() const;
	void setPrice();
	void printFullInformation() const;
	std::ostream& print(std::ostream& os) const override;
};
#endif