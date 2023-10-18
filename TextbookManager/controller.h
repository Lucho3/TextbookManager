#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "textbook.h"
#include "distribution.h"
#include "author.h"
#include "distribution_owner.h"
#include "textbook.h"
#include "order.h"
#include "controller.h"

class Controller {
private:
    std::vector<Certificate*> certificates_list;
    std::vector<Author*> authors_list;
    std::vector<DistributionOwner*> distribution_owners_list;
    std::vector<Distribution*> distributions_list;
    std::vector<Textbook*> textbooks_list;
    std::vector<Order*> order_list;

public:
    Controller();
    ~Controller();
    void createNewElement(const std::string&);
    void printAllElements(const std::string& element);
    void finishOrder();
    void addTextBookToOrder();
    void addCertificteToTextbook();
    void saveVectorsToFile();
    void loadVectorsFromFile();
    void ClearLists();
    template <typename T>
    void serializeToBinaryFile(const std::string&, const T&);
    template <typename T>
    T deserializeFromBinaryFile(const std::string&);
};

#endif
