#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include "controller.h"

class Menu {
private:
    std::shared_ptr<Controller> ctrl;

public:
    Menu();
    ~Menu();
    void createController();
    const int setGlobalMenu() const;
    const int setUserMenu() const;
    const int setElementMenu(const std::string element) const;
    const int setFileMenu() const;
    void startTheMainApp();
    void startUserControlledInputMenu();
    void startFileControlledInputMenu();
    void startElementMenu(const std::string element);
    void startTextbookMenu(const std::string);
    void startOrderMenu(const std::string);
    const int popUp() const;
};

#endif
