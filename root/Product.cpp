//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//

#include <iostream>
#include "Product.h"


Product::Product() = default;

//========================================================================

Product::Product(std::string aName,
                 double aPrice,
                 bool aIsAvailable) {

    this->name = aName;
    this->price = aPrice;
    this->isAvailable = aIsAvailable;


}


//========================================================================

Product::~Product() {


}

//========================================================================

void Product::getInfo() {
    std::cout << this->name << ", price: "
              << this->price;
    std::cout << (this->isAvailable ? ", available." : ", not available.") << std::endl;
}

//========================================================================

std::string Product::getName() {
    return this->name;
}


//========================================================================

double Product::getPrice() {
    return price;
}

//========================================================================


void Product::makeAvailable() {

    if (this->isAvailable) std::cout << this->name << " already available." << std::endl;
    else {
        this->isAvailable = true;
        std::cout << this->name << " is now available." << std::endl;
    }

}

//========================================================================

bool Product::isCurrentlyAvailable() {
    return isAvailable;
}