//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#ifndef UNTITLED_PRODUCT_H
#define UNTITLED_PRODUCT_H

////------------------------------------
//It’s an abstract class of product
//which has to be ordered to cafe.
////------------------------------------

#include <string>


class Product {
    friend class ProductDatabase;
private:

    std::string name;
    double price;
    bool isAvailable;

public:

    Product();
    Product(std::string aName,
            double aPrice = 0,
            bool aIsAvailable = false);

    virtual ~Product();
	

    void getInfo();
	/**********************************
	* displays information about the  *
	* product in the console: its     *
	* name, price and availability    *
	**********************************/
	
	
    std::string getName();
	/**********************************
	* returns name of the product     *
	**********************************/
	
	
    double getPrice();
	/**********************************
	* returns price of the product    *
	**********************************/
	
	
    void makeAvailable();
	/**********************************
	* sets the product availability   *
	* to true                         *
	**********************************/
	
	
    bool isCurrentlyAvailable();
	/**********************************
	* returns true if isAvailable is  *
	* true                            *
	**********************************/

};


#endif //UNTITLED_PRODUCT_H
