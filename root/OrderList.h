//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#ifndef UNTITLED_ORDERLIST_H
#define UNTITLED_ORDERLIST_H

////------------------------------------
// Class made for storing objects of the
// Order class in a linked list, i.e.
// database for orders.
////------------------------------------

#include "Order.h"

class OrderList {
private:
    struct orderNode{
        Order order;
        orderNode* next;
    };

    orderNode* head = NULL;

public:
    OrderList();
    ~OrderList();
	
    bool addOrder(Order order);
	/**********************************
	* adds an existing order to the   *
	* list, returns false in case of  *
	* memory allocation failure       *
	**********************************/
	
	
    bool removeOrder(Order order);
	/**********************************
	* removes order object from the   *
	* list, returns false if order    *
	* hasn't been found               *
	**********************************/
	
	
	
    bool removeOrder(int orderId);
	/**********************************
	* removes order of the given ID   *
	* from the list, returns false if *
	* order of given ID wans't found  *
	**********************************/
	
	
    bool exists(Order order);
	/**********************************
	* returns true if given order     *
	* exists in the list              *
	**********************************/
	
	
    void displayOrder(int orderId);
	/**********************************
	* displays info about the order   *
	* in the console, consequently:   *
	* ID of order and each products   *
	* name, price, quantity and cost, *
	* in the end it also displays the *
	* full cost of the order, uses    *
	* Order::displayInfo()            *
	**********************************/
	
	
	void displayStatus();
	/**********************************
	* executes displayOrder() on each *
	* order in the list               *
	**********************************/
	
	
    bool setPointerOnOrder(Order* &orderPtr, int orderId);
	/**********************************
	* sets the given order pointer on *
	* the order of given ID, returns  *
	* if order wasn't found           *
	**********************************/




};


#endif //UNTITLED_ORDERLIST_H
