//
// Created by Ernest Pokropekon 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Coffee.h"


Coffee::Coffee(short int aRoastLevel,
               double amount,
               const std::string aName,
               double aPrice,
               bool aIsAvailable) : Product(aName, aPrice, aIsAvailable) {


    this->roastLevel = aRoastLevel;
   
    srand((int)time(0));
    int random = rand() % 5 + 1;
    switch (random) {
        case 1:
            this->originCountry = "Vietnam";
        case 2:
            this->originCountry = "Colombia";
        case 3:
            this->originCountry = "Nicaragua";
        case 4:
            this->originCountry = "Mexico";
        case 5:
            this->originCountry = "Indonesia";
        default:
            this->originCountry = "Brazil";

    }

}

//========================================================================

Coffee::~Coffee() = default;

//========================================================================

bool Coffee::roast() {

    if (this->roastLevel == 10) {
        std::cerr << "Roast level is maximal. You could've burnt it!" << std::endl;
        return false;
    }

    this->roastLevel++;
    std::cout << "New level of roast: " << this->roastLevel << "/10." << std::endl;
    return true;
}

//========================================================================

void Coffee::getCoffeeInfo() {
    std::cout << this->getName() << ", "
              << " from " << this->originCountry << ", "
              << "roast level: " << this->roastLevel << "/10, "
              << "amount per container: " << this->amount << ", "
              << "price for container: " << this->getPrice() << ", ";
    if (this->isCurrentlyAvailable()) std::cout << "available" << std::endl;
    else std::cout << "not available" << std::endl;


}