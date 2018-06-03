//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//

#include "Cafe.h"
#include <iostream>

//========================================================================

Cafe::Cafe(){

}

//========================================================================

Cafe::Cafe(std::string aCity,
           std::string aPostalCode,
           std::string aStreetName,
           short int aHouseNumber){

    this->cafeId = nextId;
    nextId++;

    this->cafeAddress.city = aCity;
    this->cafeAddress.postalCode = aPostalCode;
    this->cafeAddress.streetName = aStreetName;
    this->cafeAddress.houseNumber = aHouseNumber;

    budgetAvailable = 0.0;

}

//========================================================================

Cafe::~Cafe(){


}

//========================================================================


void Cafe::displayAddress(){

    std::cout << "ID: " << this->cafeId << ", "
              << this->cafeAddress.city << " "
              << this->cafeAddress.postalCode << ", "
              << this->cafeAddress.streetName << " "
              << this->cafeAddress.houseNumber << std::endl;
}



//========================================================================

bool Cafe:: canOrder(Order order){

    return order.canBeOrdered(budgetAvailable);

}

//========================================================================

void Cafe::addToBudget(double amountOfMoney){

    budgetAvailable += amountOfMoney;

}

//========================================================================

bool Cafe::setOrderAsDefault(int orderId, OrderList orderDatabase){
    return orderDatabase.setPointerOnOrder(this->orderPtr, orderId);
}

//========================================================================

bool Cafe::executeOrder(){

    if (orderPtr == NULL){
        std::cerr << "No default order assigned." << std::endl;
        return false;
    }

    if (!orderPtr->canBeOrdered(budgetAvailable)){
        std::cerr << "Too small budget." << std::endl;
        return false;
    }

    // woosh!
    // some magic happening...

    orderPtr->payForOrder(budgetAvailable);
    std::cout << "Order was correctly executed. Budget Left: "
                 << budgetAvailable << std::endl;
    return true;


}

//========================================================================

bool Cafe::executeOrder(Order order, OrderList orderDatabase){

    if(!orderDatabase.exists(order)){
        std::cerr << "Such order doesn't exist in given order database." << std::endl;
        return false;
    }
    if (!order.canBeOrdered(budgetAvailable)){
        std::cerr << "Too small budget." << std::endl;
        return false;
    }


    // woosh!
    // some magic happening...

    order.payForOrder(budgetAvailable);
    std::cout << "Order was correctly executed. Budget Left: "
              << budgetAvailable << std::endl;
    return true;


}

//========================================================================

bool Cafe::sameId(int anotherId) {

    return anotherId==this->cafeId;

}

//========================================================================

bool Cafe::sameCity(std::string anotherCity){

    return anotherCity == this->cafeAddress.city;

}