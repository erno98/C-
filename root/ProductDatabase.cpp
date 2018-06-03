//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#include "ProductDatabase.h"


ProductDatabase::ProductDatabase() {



}

//========================================================================


ProductDatabase::~ProductDatabase() {


}

//========================================================================


void ProductDatabase::displayProductInfo(std::string productName) {

// empty list
    if (head == NULL) std::cerr << "Database is empty." << std::endl;

// non empty list
    productNode *travel = head;
    while (travel != NULL) {
        if (travel->product.name == productName) {
            // checking whether travel is pointing at the product we're looking for
            travel->product.getInfo();
            break; // product found, breaking out of the while loop
        } else travel = travel->next; // product not found (yet), moving on to next one
    }

    if (travel == NULL) { // travel went through the whole while loop, product not found
        std::cerr << "Couldn't find product of given name: '" << productName << "'." << std::endl;
    }
}

//========================================================================


void ProductDatabase::displayProducts() {

//empty list
    if (head == NULL) std::cerr << "Database is empty." << std::endl;

//list is not empty
    productNode *travel = head;
    while (travel != NULL) {
        displayProductInfo(travel->product.name);
        travel = travel->next;
    }

}

//========================================================================


bool ProductDatabase::add(std::string productName, double productPrice) {

    productNode *newProductNode;

    try {
        newProductNode = new productNode;
    }
    catch (std::bad_alloc) {
        std::cerr << "Memory allocation failed. " << std::endl;
        return false;
    }
    newProductNode->product = Product(productName, productPrice);
    //here we assume, that the newly added product is immediately available, therefore 'true'

// empty list scenario
    if (head == NULL) {
        head = newProductNode;
        newProductNode->next = NULL;
        return true;
    }

// 1 element list
    if (head->next == NULL) {
        head->next = newProductNode;
        newProductNode->next = NULL;
        return true;
    }

// list is non empty, more than 1 element
    productNode *travel = head;      //setting up pointer 'travel' to go through the list
    while (travel->next != NULL) {
        travel = travel->next;
    } //here 'travel' is pointing at the last element of the list

    travel->next = newProductNode;    //adding the product at the end of the list, method has succeeded!
    newProductNode->next = NULL;

    return true;

}

//========================================================================

bool ProductDatabase::add(Product product){

    return add(product.name, product.price);

}

//========================================================================

bool ProductDatabase::removeByName(std::string productName) {
// list is empty
    if (head == NULL) {
        std::cerr << "The database is empty, nothing to remove." << std::endl;
        return true;
    }

// list has only 1 element
    else if (head->next == NULL) {
        if (head->product.name == productName) {
//list has only 1 element and its our sought! yay!
            productNode *temp = head;
            head = NULL;
            delete temp;

            return true;
        }
//the element in the list isn't one we're looking for.
        std::cout << head->product.name << " " << productName << std::endl;
        return false;
    }


// list is non empty and it has more than 1 element
    productNode *travel = head;

    if (head->product.name == productName) {
// first product in list is what we are looking for
        productNode *temp = head;
        head = NULL;
        delete temp;
        return true;
    }

// first element is not the one we are looking for
    while (travel->next != NULL) {
        if (travel->next->product.name == productName) {
            // given product was found!
            // travel pointing at the product just before the sought one
            productNode *temp = travel->next;
            travel->next = travel->next->next;
            delete temp;
            return true;

            return true; // yay!
        }

        // condition not satisfied, while still going
        travel = travel->next;
    }

    //end of while, given product not found
    std::cerr << "Couldn't find product '" << productName << "'." << std::endl;
    return false;
}

//=================================================================


void ProductDatabase::clearDatabase() {

//list is empty
    if (head == NULL) {
        std::cerr << "Database is already empty." << std::endl;
    }


//list has only 1 element
    if (head->next == NULL) {
        removeByName(head->product.name);
    }

//list is non empty, more than 1 element
    productNode *travel = head;
    while (travel != NULL) {
        productNode *temp = travel;
        travel = travel->next;
        head = travel;
        delete temp;
    }

}

//========================================================================


bool ProductDatabase::exists(std::string productName) {

    productNode *travel = head;

    while (travel != NULL) {
        if (travel->product.name == productName) return true;
        travel = travel->next;
    }
    return false;
}

//========================================================================



bool ProductDatabase::setPointerOnProduct(Product* &productPtr, std::string productName) {
    productNode *travel = head;

    while (travel != NULL) {
        if (productName == travel->product.name) {
            productPtr = &travel->product;
            return true;
        }
        travel = travel->next;
    }
    return false;


}



//=====================OPERATORS===========================================

ProductDatabase &ProductDatabase::operator=(const ProductDatabase &database) {

// checking whether databases are the same
    if (this == &database) return *this;

// databases different
    clearDatabase();
    productNode *travel = database.head;
    while (travel != NULL) {
        add(travel->product.name, travel->product.price);
        travel = travel->next;
    }
    return *this;
}

//=======================COPY CONSTRUCTOR==================================

ProductDatabase::ProductDatabase(const ProductDatabase &database) {

    head = NULL;
    *this = database; //using overloaded '='

}

//========================================================================

ProductDatabase ProductDatabase::operator+(const ProductDatabase &database) {

    ProductDatabase newDatabase = *this;
    productNode *travel = database.head;

    while (travel != NULL) {
        newDatabase.add(travel->product.name, travel->product.price);
        travel = travel->next;
    }
    return newDatabase;
}

//========================================================================


ProductDatabase ProductDatabase::operator-(const ProductDatabase &database) {

    ProductDatabase newDatabase = *this;
    productNode *travel = database.head;

    while (travel != NULL) {
        newDatabase.removeByName(travel->product.name);
        travel = travel->next;
    }

    return newDatabase;
}