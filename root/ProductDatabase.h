//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#ifndef UNTITLED_PRODUCTDATABASE_H
#define UNTITLED_PRODUCTDATABASE_H

////------------------------------------
// Class for holding products
// in a 'database' in form of a
// linked list
////------------------------------------


#include "Product.h"
#include <iostream>

class ProductDatabase {

private:

    struct productNode{
        Product product;
        productNode* next;
    };

    productNode* head = NULL;

public:
    ProductDatabase();
    ~ProductDatabase();

//=========================methods==================================================
    void displayProducts();
	/**********************************
	* displays info of each product   *
	* in the database, uses           *
	* Product::getInfo();
	**********************************/
	
	
    void displayProductInfo(std::string productName);
	/**********************************
	* displays info of product of     *
	* given name in the console       *
	* executing Product::getInfo()    *
	**********************************/

    bool add(std::string productName, double productPrice);
	/**********************************
	* adds a non existing product to  *
	* the database, returns false in  *
	* case of the memory allocation   *
	* failure                         *
	**********************************/
	
	
    bool add(Product product);
	/**********************************
	* adds existing product to the    *
	* database, returns false in case *
	* of memory allocation failure    *
	**********************************/
	
	
    bool removeByName(std::string productName);
	/**********************************
	* removes product of the given    *
	* name, returns false if product  *
	* wans't found                    *
	**********************************/
	
	
    void clearDatabase();
	/**********************************
	* removes every product from the  *
	* database                        *
	**********************************/
	
	
    bool exists(std::string productName);
	/**********************************
	* returns true if product of given*
	* ID exists in the database       *
	**********************************/
	
	
    bool setPointerOnProduct(Product* &productPtr, std::string productName);
	/**********************************
	* sets product pointer to the     *
	* product in the list of given    *
	* name, returns false if the      *
	* product hasn't been found       *
	**********************************/


//=========================operators==================================================
    ProductDatabase& operator=(const ProductDatabase &database);
    ProductDatabase(const ProductDatabase &database);
    ProductDatabase operator+ (const ProductDatabase &database);
    ProductDatabase operator- (const ProductDatabase &database);

};


#endif //UNTITLED_PRODUCTDATABASE_H
