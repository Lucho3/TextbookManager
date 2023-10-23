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
    std::vector<std::shared_ptr<Certificate>> certificates_list;
    std::vector<std::shared_ptr<Author>> authors_list;
    std::vector<std::shared_ptr<DistributionOwner>> distribution_owners_list;
    std::vector<std::shared_ptr<Distribution>> distributions_list;
    std::vector<std::shared_ptr<Textbook>> textbooks_list;
    std::vector<std::shared_ptr<Order>> order_list;
    template <typename Container>
    void ClearList(Container&);
    template <typename T>
    void serializeToBinaryFile(const std::string&, const T&);
    template <typename T>
    std::vector<std::shared_ptr<T>> deserializeFromBinaryFile(const std::string&);
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
};

#endif
