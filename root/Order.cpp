//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#include "Order.h"


Order::Order() {

    this->orderId = nextOrderId;
    nextOrderId++;
    totalCost = 0.0;


}

//========================================================================

Order::~Order() {


}

//========================================================================

bool Order::add(std::string productName, int aProductQuantity, ProductDatabase &database) {

    orderedProductNode *newOrderedProduct;
    try {
        newOrderedProduct = new orderedProductNode;
    }
    catch (std::bad_alloc) {
        std::cerr << "Memory allocation failed. " << std::endl;
        return false;
    }
// allocation succeeded

// list is empty
    if (head == NULL) {
        head = newOrderedProduct;
// checking if product already exists in database
        if (database.exists(productName)) {
            database.setPointerOnProduct(newOrderedProduct->productPtr, productName);
            newOrderedProduct->productQuantity = aProductQuantity;
            newOrderedProduct->next = NULL;
            totalCost += (newOrderedProduct->productPtr->getPrice() * newOrderedProduct->productQuantity);
            return true;

        } else { //doesn't exist

            std::cout << "New product '" << productName
                      << "' being added to the database. Input its price: " << std::endl;

            double newPrice;
            std::cin >> newPrice;

            database.add(productName, newPrice);
            newOrderedProduct->productQuantity = aProductQuantity;
            newOrderedProduct->next = NULL;
            totalCost += (newOrderedProduct->productPtr->getPrice() * newOrderedProduct->productQuantity);
            return true;
        }
    }

// 1 element list
    if (head->next == NULL) {
        head->next = newOrderedProduct;
        if (database.exists(productName)) {
            database.setPointerOnProduct(newOrderedProduct->productPtr, productName);
            newOrderedProduct->productQuantity = aProductQuantity;
            newOrderedProduct->next = NULL;
            totalCost += (newOrderedProduct->productPtr->getPrice() * newOrderedProduct->productQuantity);
            return true;
        } else {
            std::cout << "New product '" << productName
                      << "' being added to the database. Input its price: " << std::endl;

            double newPrice;
            std::cin >> newPrice;

            database.add(productName, newPrice);
            newOrderedProduct->productQuantity = aProductQuantity;
            newOrderedProduct->next = NULL;
            totalCost += (newOrderedProduct->productPtr->getPrice() * newOrderedProduct->productQuantity);
            return true;
        }
    }

// non empty list, more than 1 element

    orderedProductNode *travel = head;


    while (travel->next != NULL) {
        travel = travel->next;
    }
    travel->next = newOrderedProduct;
    if (database.exists(productName)) {
        database.setPointerOnProduct(newOrderedProduct->productPtr, productName);
        newOrderedProduct->productQuantity = aProductQuantity;
        newOrderedProduct->next = NULL;
        totalCost += (newOrderedProduct->productPtr->getPrice() * newOrderedProduct->productQuantity);
        return true;
    } else {
        std::cout << "New product '" << productName
                  << "' being added to the database. Input its price: " << std::endl;

        double newPrice;
        std::cin >> newPrice;

        database.add(productName, newPrice);
        database.setPointerOnProduct(newOrderedProduct->productPtr, productName);
        newOrderedProduct->productQuantity = aProductQuantity;
        newOrderedProduct->next = NULL;
        totalCost += (newPrice * newOrderedProduct->productQuantity);
        return true;

    }

}


//========================================================================

bool Order::add(Product product, int productQuantity, ProductDatabase& database) {

    return add(product.getName(), productQuantity, database);

}

//========================================================================

void Order::displayInfo() {

    orderedProductNode *travel = head;


    if (head == NULL) std::cout << "Order is empty." << std::endl;

    else {
        double totalProductPrice;
        int count = 1;
        std::cout << "=============================" << std::endl;
        std::cout << "Order ID: " << orderId << std::endl;
        while (travel != NULL) {
            totalProductPrice = (travel->productPtr->getPrice() * travel->productQuantity);
            std::cout << "Product " << count << ", "
                      << travel->productPtr->getName() << std::endl
                      << "quantity: " << travel->productQuantity << std::endl
                      << "cost: " << totalProductPrice << std::endl
                      << "-----------------------------" << std::endl;
            travel = travel->next;
            count++;
        }
        std::cout << "Total cost: " << totalCost << std::endl;
        std::cout << "=============================" << std::endl;
    }
}


//========================================================================

bool Order::setProductQuantity(std::string productName, int newQuantity) {

    orderedProductNode *travel = head;
    while (travel != NULL) {
        if (travel->productPtr->getName() == productName) {
            if (travel->productQuantity > newQuantity) {
                totalCost = {
                        totalCost - ((travel->productQuantity - newQuantity) *
                                     travel->productPtr->getPrice())
                };
            } else if (travel->productQuantity < newQuantity) {
                totalCost = {
                        totalCost + ((newQuantity - travel->productQuantity)
                                     * travel->productPtr->getPrice())
                };
            }

            travel->productQuantity = newQuantity;
            return true;
        }
        travel = travel->next;
    }

    std::cerr << "Couldn't find product '"
              << productName << "'." << std::endl;
    return false;
}

//========================================================================

bool Order::removeProduct(std::string productName) {

// empty list
    if (head == NULL) {
        std::cerr << "Order is empty." << std::endl;
        return true;
    }
// 1 element list
    if (head->next == NULL) {
        if (head->productPtr->getName() == productName) {
            totalCost -= (head->productPtr->getPrice() * head->productQuantity);
            orderedProductNode *temp = head;
            head = NULL;
            delete temp;
            return true;
        } else {
            std::cerr << "Couldn't find product '" << productName << "'." << std::endl;
            return false;
        }
    }

// non empty list, more than 1 element

    orderedProductNode *travel = head;

// sought element on the head of the list
    if (head->productPtr->getName() == productName) {
        totalCost -= (head->productPtr->getPrice() * head->productQuantity);
        orderedProductNode *temp = head;
        head = travel->next;
        delete temp;
        return true;
    }
// travelling through the list to find the product

    while (travel->next != NULL) {
        if (travel->next->productPtr->getName() == productName) {
            totalCost -= (travel->next->productPtr->getPrice() * travel->next->productQuantity);
            orderedProductNode *temp = travel->next;
            travel->next = travel->next->next;
            delete temp;
            return true;
        }
        travel = travel->next;
    }

    std::cerr << "Couldn't find product '" << productName << "'." << std::endl;
    return false;

}

//========================================================================

bool Order::canBeOrdered(double moneyAvailable) {

    return moneyAvailable > totalCost;

}

//========================================================================

void Order::payForOrder(double &moneyAvailable){

    moneyAvailable -= totalCost;

}

//========================================================================

//bool operator==(const Order &order1, const Order &order2) {
//
//    if (order1.orderId != order2.orderId
//        || order1.totalCost != order2.totalCost
//        || (order1.head == NULL && order2.head != NULL)       //didn't implement if(o1.head == o2.head), since
//        || (order1.head != NULL && order2.head == NULL)) {     //the order objects can be in different order
//
//        return false;
//    }
//
//    if (order1.head == order2.head == NULL) return true;
//
//    Order::orderedProductNode *travel1 = order1.head;
//    Order::orderedProductNode *travel2 = order2.head;
//
//    bool exists = false;
//
//// for every element from order1, the loop looks through order2, and if it finds the same, it allows the first while to go on.
//
//    while(travel1 != NULL){
//        while(travel2 != NULL){
//            if(travel1->productPtr == travel2->productPtr){
//                exists = true;
//                break;
//            }
//            travel2 = travel2->next;
//        }
//        if(!exists){
//            return false;
//        }
//
//        travel2 = order2.head;
//        travel1 = travel1->next;
//    }
//
//    return true;
//
//
//}

//========================================================================