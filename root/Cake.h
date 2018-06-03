//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#ifndef UNTITLED_CAKE_H
#define UNTITLED_CAKE_H


////------------------------------------
//A class for cakes, as it
//is the second most
//important thing in the cafe.
//Inherits from product.
////------------------------------------


#include "Product.h"

class Cake: public Product {
private:
    std::string flavour;
    int kcalPer100g;
    bool withLactose;
    bool isVegan;


public:
    Cake(std::string aName,
         double aPrice,
         bool aIsAvailable);
    ~Cake();
	
    void getCakeInfo();
	/**********************************
	* displays information about cake *
    * in the console, consequently:   *
    * flavour and calories per 100g,  *
    * also is it vegan and is it with *
    * lactose                         *	
	**********************************/
	
	
    bool isHighInCalories();
	/**********************************
	* returns true if the calories    *
	* per 100g is higher than 450     *
	**********************************/


};


#endif //UNTITLED_CAKE_H
