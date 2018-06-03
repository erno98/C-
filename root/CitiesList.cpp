//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//

#include "CitiesList.h"

CitiesList::CitiesList() {


}

//========================================================================

CitiesList::~CitiesList() {



}

//========================================================================

bool CitiesList::exists(std::string cityName) {
    cityNode *travel = head;

    while (travel != NULL) {
        if (travel->cafeList.cityNameEquals(cityName)) return true;
        travel = travel->next;
    }
    return false;


}

//========================================================================

bool CitiesList::addCity(CafeList city) {

    cityNode *newCityNode;

    try {
        newCityNode = new cityNode;
    }
    catch (std::bad_alloc) {
        std::cerr << "Memory allocation failed. " << std::endl;
        return false;
    }

    newCityNode->cafeList = city;

// empty list scenario
    if (head == NULL) {
        head = newCityNode;
        newCityNode->next = NULL;
        return true;
    }

// 1 element list
    if (head->next == NULL) {
        head->next = newCityNode;
        newCityNode->next = NULL;
        return true;
    }

// list is non empty, more than 1 element
    cityNode *travel = head;      //setting up pointer 'travel' to go through the list
    while (travel->next != NULL) {
        travel = travel->next;
    } //here 'travel' is pointing at the last element of the list

    travel->next = newCityNode;    //adding the product at the end of the list, method has succeeded!
    newCityNode->next = NULL;

    return true;

}

//========================================================================


bool CitiesList::removeCity(std::string cityName) {
    // empty list
    if (head == NULL) {
        std::cerr << "Cities database is empty." << std::endl;
        return true;
    }
// 1 element list
    if (head->next == NULL) {
        if (head->cafeList.cityNameEquals(cityName)) {
            cityNode *temp = head;
            head = NULL;
            delete temp;
            return true;
        } else {
            std::cerr << "Couldn't find city of name " << cityName << "." << std::endl;
            return false;
        }
    }

// non empty list, more than 1 element

    cityNode *travel = head;

// sought element on the head of the list
    if (head->cafeList.cityNameEquals(cityName)) {
        cityNode *temp = head;
        head = travel->next;
        delete temp;
        return true;
    }
// travelling through the list to find the product

    while (travel->next != NULL) {
        if (travel->next->cafeList.cityNameEquals(cityName)) {
            cityNode *temp = travel->next;
            travel->next = travel->next->next;
            delete temp;
            return true;
        }
        travel = travel->next;
    }

    std::cerr << "Couldn't find city of name " << cityName << "." << std::endl;
    return false;

}

//========================================================================


void CitiesList::displayStatus() {
    if(head == NULL) std::cout << "Cities database is empty." << std::endl;

    else{
        cityNode* travel = head;
        while(travel != NULL){
            travel->cafeList.displayCafes();
            travel = travel->next;
        }
    }

}

//========================================================================

void CitiesList::displayCityStatus(std::string cityName) {
    if(head == NULL) std::cout << "Cities database is empty." << std::endl;

    else{
        cityNode* travel = head;
        while(travel != NULL){
            if(travel->cafeList.cityNameEquals(cityName)){
                travel->cafeList.displayCafes();
                break;
            }
            travel = travel->next;
        }

        if (travel == NULL) {
            std::cout << "Couldn't find city '" << cityName << "'." << std::endl;
        }

    }


}

//========================================================================

