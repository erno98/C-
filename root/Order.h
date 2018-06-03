//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#ifndef UNTITLED_ORDER_H
#define UNTITLED_ORDER_H

////------------------------------------
//A class for a linked list,which
//contains nodes of ordered Product.
////------------------------------------


#include "ProductDatabase.h"
#include <iostream>

static int nextOrderId = 1;

class Order {
    friend class OrderList;
private:
    int orderId;
    double totalCost;
    struct orderedProductNode{
        int productQuantity;
        Product* productPtr;
        orderedProductNode* next;
    };
    orderedProductNode* head=NULL;

public:
    Order();
    ~Order();
	
    bool add(std::string productName, int productQuantity, ProductDatabase& database);
	/**********************************
	* adds a new product to the order *
	* and allocates memory for it, in *
	* case of not existing product of *
	* given name in the given database*
	* method gets its price from the  *
	* console input, returns false if *
	* there was a memory allocation   *
	* failure
	**********************************/
	
	
    bool add(Product product, int productQuantity, ProductDatabase& database);
	/**********************************
	* adds an existing product to the  *
	* order,returns false in case of   *
	* memory allocation failure        *
	**********************************/
	
	
    void displayInfo();
	/**********************************
	* displays info about the order   *
	* in the console, consequently:   *
	* ID of order and each products   *
	* name, price, quantity and cost, *
	* in the end it also displays the *
	* full cost of the order          *
	**********************************/
	
	
    bool setProductQuantity(std::string productName, int newQuantity);
	/**********************************
	* sets quantity of product of     *
	* given name to the given value,  *
	* returns false if the product    *
	* hasn't been found               *
	**********************************/
	
	
    bool removeProduct(std::string productName);
	/**********************************
	* removes the product of given    *
	* name from th order, returns     *
	* false, if the product hasn't    *
	* been found and true in case of  *
	* empty database or correct       *
	* removal                         *
	**********************************/
	
    bool canBeOrdered(double moneyAvailable);
	/**********************************
	* returns true if the cost of     *
	* order is smaller than given     *
	* amount                          *
	**********************************/
	
    void payForOrder(double &moneyAvailable);
	/**********************************
	* decreases the budget of the cafe*
	* which has executed the order by *
	* value of its cost               *
	**********************************/


    friend inline bool operator==(const Order &order1, const Order &order2){
        if (order1.orderId != order2.orderId
            || order1.totalCost != order2.totalCost
            || (order1.head == NULL && order2.head != NULL)       //didn't implement if(o1.head == o2.head), since
            || (order1.head != NULL && order2.head == NULL)) {     //the order objects can be in different order

            return false;
        }

        if (order1.head == order2.head  && order1.head == NULL) return true;

        Order::orderedProductNode *travel1 = order1.head;
        Order::orderedProductNode *travel2 = order2.head;

        bool exists = false;

        // for every element from order1, the loop looks through order2, and if it finds the same, it allows the first while to go on.

        while(travel1 != NULL){
            while(travel2 != NULL){
                if(travel1->productPtr == travel2->productPtr){
                    exists = true;
                    break;
                }
                travel2 = travel2->next;
            }
            if(!exists){
                return false;
            }

            travel2 = order2.head;
            travel1 = travel1->next;
        }

        return true;

    }

};




#endif //UNTITLED_ORDER_H
