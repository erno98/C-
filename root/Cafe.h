//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//

#ifndef UNTITLED_CAFE_H
#define UNTITLED_CAFE_H


////------------------------------------
// Class Cafe creates objects
// that are individual cafes.
// It contains information
// about its address and budget.
////------------------------------------


#include <string>
#include "OrderList.h"

static int nextId = 1;

// as new Cafe is created, value of nextId is assigned
// to it, and then increases by 1.
// [look Cafe.cpp -> constructor Cafe::Cafe(...)]

class Cafe {
private:
    int cafeId;
    struct address{
        std::string city;
        std::string postalCode;
        std::string streetName;
        short int houseNumber;
    };

    address cafeAddress;

    Order* orderPtr = NULL;
    double budgetAvailable;

public:
    Cafe();
    Cafe(std::string aCity,
         std::string aPostalCode,
         std::string aStreetName,
         short int aHouseNumber);

    ~Cafe();
    void displayAddress();
	/**********************************
	* displays in console information *
	* about address, consequently:    *
	* id, city, postal code, street   *
	* name, house number              *
	**********************************/
	
	
    bool canOrder(Order order);
	/**********************************
	* returns true if the budget of   * 
	* the cafe is higher than cost of *
	* the order                       *
	**********************************/
	
	
    void addToBudget(double amountOfMoney);
	/**********************************
	* adds given amount of money to   *
	* cafe's budget                   *
	**********************************/
	
	
    bool setOrderAsDefault(int orderId, OrderList orderDatabase);
	/**********************************
	* sets deafult order for cafe     *
	* from given database, after this *
	* method executeOrder() will      *
	* be executed on the default order*
	**********************************/
	
	
    bool executeOrder();
	/**********************************
	* executes the default order,     *
    * returns false if default order  *
    * hasn't been specified, or       *
    * canOrder() wasn't satisfied     *	
	**********************************/
	
	
    bool executeOrder(Order order, OrderList orderDatabase);
	/**********************************
	* executes the given order from   *
    * given database, returns false if*
    * canOrder() wasn't satisfied     *	
	**********************************/	
	
	
    bool sameId(int anotherId);
	/**********************************
	* returns true if given ID is the *
	* same as cafe's                  *
	**********************************/
	
	
    bool sameCity(std::string anotherCity);
	/**********************************
	* returns true if given city name *
	* is same as cafe's               *
	**********************************/

};


#endif //UNTITLED_CAFE_H
