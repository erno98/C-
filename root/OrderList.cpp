//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//



#include "OrderList.h"

OrderList::OrderList() {


}

//========================================================================

OrderList::~OrderList() {


}

//========================================================================

bool OrderList::addOrder(Order order) {

    orderNode *newOrderNode;

    try {
        newOrderNode = new orderNode;
    }
    catch (std::bad_alloc) {
        std::cerr << "Memory allocation failed. " << std::endl;
        return false;
    }

    newOrderNode->order = order;

// empty list scenario
    if (head == NULL) {
        head = newOrderNode;
        newOrderNode->next = NULL;
        return true;
    }

// 1 element list
    if (head->next == NULL) {
        head->next = newOrderNode;
        newOrderNode->next = NULL;
        return true;
    }

// list is non empty, more than 1 element
    orderNode *travel = head;      //setting up pointer 'travel' to go through the list
    while (travel->next != NULL) {
        travel = travel->next;
    } //here 'travel' is pointing at the last element of the list

    travel->next = newOrderNode;    //adding the product at the end of the list, method has succeeded!
    newOrderNode->next = NULL;

    return true;
}

//========================================================================

bool OrderList::removeOrder(int orderId) {

    // empty list
    if (head == NULL) {
        std::cerr << "Order database is empty." << std::endl;
        return true;
    }
// 1 element list
    if (head->next == NULL) {
        if (head->order.orderId == orderId) {
            orderNode *temp = head;
            head = NULL;
            delete temp;
            return true;
        } else {
            std::cerr << "Couldn't find order of ID " << orderId << "." << std::endl;
            return false;
        }
    }

// non empty list, more than 1 element

    orderNode *travel = head;

// sought element on the head of the list
    if (head->order.orderId == orderId) {
        orderNode *temp = head;
        head = travel->next;
        delete temp;
        return true;
    }
// travelling through the list to find the product

    while (travel->next != NULL) {
        if (travel->next->order.orderId == orderId) {
            orderNode *temp = travel->next;
            travel->next = travel->next->next;
            delete temp;
            return true;
        }
        travel = travel->next;
    }

    std::cerr << "Couldn't find order of ID " << orderId << "." << std::endl;
    return false;

}

//========================================================================

bool OrderList::removeOrder(Order order) {

    return removeOrder(order.orderId);

}


//========================================================================

bool OrderList::exists(Order order) {

    orderNode *travel = head;

    while (travel != NULL) {
        if (travel->order == order) return true;
        travel = travel->next;
    }
    return false;

}


//========================================================================

void OrderList::displayOrder(int orderId) {
    if (head == NULL) std::cout << "Order database is empty." << std::endl;
    else {
        orderNode *travel = head;
        while (travel != NULL) {
            if (travel->order.orderId == orderId) {
                travel->order.displayInfo();
                break;
            }
            travel = travel->next;
        }
        if (travel == NULL) {
            std::cout << "Couldn't find order of ID " << orderId << "." << std::endl;
        }
    }


}


//========================================================================

void OrderList::displayStatus() {

    if (head == NULL) std::cout << "Order database is empty." << std::endl;

    else {
        orderNode *travel = head;
        while (travel != NULL) {
            travel->order.displayInfo();
            travel = travel->next;
        }
    }


}

//========================================================================

bool OrderList::setPointerOnOrder(Order* &orderPtr, int orderId) {

    orderNode *travel = head;
    while (travel != NULL) {
        if (orderId == travel->order.orderId) {
            orderPtr = &travel->order;
            return true;
        }
        travel = travel->next;
    }
    return false;

}

//========================================================================



