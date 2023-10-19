#include "menu.h"
#include <iostream>
#include <map>
#include "common.h"

Menu::Menu()  {
    this->startTheMainApp();
}

Menu::~Menu() {
    this->ctrl.reset();
}

void Menu::setChosenOption(int number) {
    this->chosen_option = number;
}

const double Menu::getChosenOpion() const {
    return chosen_option;
}

void Menu::createController()  {
    this->ctrl = std::make_shared<Controller>();
}

const int Menu::setElementMenu(const std::string element) const {
    std::system("cls");
    std::cout << "Element Menu For: "<< element << ".\n";
    std::cout << "0. Create new " << element << ".\n";
    std::cout << "1. Print all of the " << element << "s.\n";
    if (element == "Textbook") {
        std::cout << "2. Add certificate.\n";
        std::cout << "3. Go Back.\n";
    }
    else if (element == "Order") {
        std::cout << "2. Add textbook to order.\n";
        std::cout << "3. Finish Order.\n";
        
        std::cout << "4. Go Back.\n";
    }
    else {
        std::cout << "2. Go Back.\n";
    }

    return Common::getIntCommon("your choice");
}

void Menu::startTextbookMenu(const std::string element) {
    while (true) {
        switch (this->setElementMenu(element)) {
        case 0:
            this->ctrl->createNewElement(element);
            break;
        case 1:
            this->ctrl->printAllElements(element);
            std::cout << "Press any key to continue.";
            std::getchar();
            break;
        case 2:
            this->ctrl->addCertificteToTextbook();
            break;
        case 3:
            std::cout << "Goodbye\n";
            return;
        default:
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}

void Menu::startOrderMenu(const std::string element) {
    while (true) {
        switch (this->setElementMenu(element)) {
        case 0:
            this->ctrl->createNewElement(element);
            break;
        case 1:
            this->ctrl->printAllElements(element);
            std::cout << "Press any key to continue.";
            std::getchar();
            break;
        case 2:
             this->ctrl->addTextBookToOrder();
             break;
        case 3:
             this->ctrl->finishOrder();
             std::cout << "Press any key to continue.";
             std::getchar();
             break;
        case 4:
            std::cout << "Goodbye\n";
            return;
        default:
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}

void Menu::startElementMenu(const std::string element) {
    while (true) {
        switch (this->setElementMenu(element)) {
        case 0:
            this->ctrl->createNewElement(element);
            break;
        case 1:
            this->ctrl->printAllElements(element);
            std::cout << "Press any key to continue.";
            std::getchar();
            break;
        case 2:
            std::cout << "Goodbye\n";
            return;
        default:
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}

void Menu::setGlobalMenu() {
    std::system("cls");
    std::cout << "Manin Menu:\n";
    std::cout << "0. User controlled inputs.\n";
    std::cout << "1. File actions\n";
    std::cout << "2. Exit\n";

    this->chosen_option = Common::getIntCommon("your choice");
}

void Menu::startTheMainApp() {
    this->createController();
    while (true) {
        this->setGlobalMenu();
        switch (this->chosen_option) {
        case 0:
            this->startUserControlledInputMenu();
            break;
        case 1:
            this->startFileControlledInputMenu();
            break;
        case 2:
            std::cout << "Goodbye\n";
            return;
        default:
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}
const int Menu::setUserMenu() const{
    std::system("cls");
    std::cout << "User Controlled Inputs Menu:\n";
    std::cout << "0. Element menu for distribution owner.\n";
    std::cout << "1. Element menu for author.\n";
    std::cout << "2. Element menu for textbook.\n";
    std::cout << "3. Element menu for distribution.\n";
    std::cout << "4. Element menu for order.\n";
    std::cout << "5. Go Back.\n";

    return Common::getIntCommon("your choice");
}

void Menu::startUserControlledInputMenu() {
    while (true) {
        switch (setUserMenu()) {
        case 0:
            this->startElementMenu("Distribution Owner");
            break;
        case 1:
            this->startElementMenu("Author");
            break;
        case 2:
            this->startTextbookMenu("Textbook");
            break;
        case 3:
            this->startElementMenu("Distribution");
            break;
        case 4:
            this->startOrderMenu("Order");
            break;
        case 5:
            return;
        default:
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}

const int Menu::setFileMenu() const {
    std::system("cls");
    std::cout << "File Menu: " << std::endl;
    std::cout << "0. Load From Files " << std::endl;
    std::cout << "1. Save To Files " << std::endl;
    std::cout << "2. Go Back.\n";

    return Common::getIntCommon("your choice");
}

const int Menu::popUp() const {
    std::system("cls");
    std::cout << "Note that the loading/saving will erase all of the current/saved data."<<std::endl;
    std::cout << "An empty vectors may be there." << std::endl;
    std::cout << "Are you sure?" << std::endl;
    std::cout << "0. No" << std::endl;
    std::cout << "1. Yes" << std::endl;

    return Common::getIntCommon("your choice");
}

void Menu::startFileControlledInputMenu() {
    while (true) {
        switch (setFileMenu()) {
        case 0:
            if (this->popUp()) {
                std::system("cls");
                this->ctrl->loadVectorsFromFile();
                std::cout << "Loading Completed. Press any key.";
                std::getchar();
            }
            break;
        case 1:
            std::system("cls");
            if (this->popUp()) {
                this->ctrl->saveVectorsToFile();
                std::cout << "Saving Copleted. Press any key.";
                std::getchar();
            }

            break;
        case 2:
            return;
        default:
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}