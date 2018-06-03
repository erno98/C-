//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#ifndef UNTITLED_COFFEE_H
#define UNTITLED_COFFEE_H

////------------------------------------
//As the coffee is the most important
//product in Cafe, it gets its own
//class for specific ‘coffee values’.
//It inherits from a Product class.
////------------------------------------


#include "Product.h"

class Coffee: public Product {
private:
    short int roastLevel;
    double amount;
    std::string originCountry;

public:
    Coffee(short int aRoastLevel,
           double amount,
           std::string aName,
           double aPrice,
           bool aIsAvailable);
    ~Coffee();
	
	
    bool roast();
	/**********************************
	* increases the roastLevel by 1,  *
	* returns false if the roastLevel *
	* is maximum (10)                 *
	**********************************/
	
	
    void getCoffeeInfo();
	/**********************************
	* displays information about the  *
	* coffee in the console: name,    *
	* origin country, roast, amount   *
	* per containter in kilograms,    *
	* price and availability          *
	**********************************/

};


#endif //UNTITLED_COFFEE_H
