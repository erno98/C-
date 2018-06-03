//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#ifndef UNTITLED_BEVERAGE_H
#define UNTITLED_BEVERAGE_H

////------------------------------------
//Class for beverages such as
//water, cola, beer (not coffee)
////------------------------------------

#include "Product.h"

class Beverage: public Product {
private:
    double volume;
    double alcohol_in;
    double fatPercentage;
    std::string type = "Drink";
    bool isVegan;

public:
    Beverage(std::string aName,
             double aPrice,
             bool aIsAvailable);
    ~Beverage();
    void getBeverageInfo();
	/******************************************
	* displays information about the beverage *
	* uses getInfo(); from the Product class, *
	* also displays its volume and alcohol    *
	* content / fat content if there is one.  *
	******************************************/
};


#endif //UNTITLED_BEVERAGE_H
