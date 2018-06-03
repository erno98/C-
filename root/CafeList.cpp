//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//

#include "CafeList.h"

CafeList::CafeList() {

}

//========================================================================

CafeList::CafeList(const std::string cityName){

    this->listCity = cityName;


}

//========================================================================

CafeList::~CafeList(){



}

//========================================================================

void CafeList::displayCafeInfo(const short int aCafeId){

    if (head == NULL) std::cout << "No cafes in the given city." << std::endl;

    else {
        cafeNode *travel = head;
        while (travel != NULL) {
            if(travel->cafe.sameId(aCafeId)) {
                travel->cafe.displayAddress();
            }
            travel = travel->next;
        }
    }

}

//========================================================================

void CafeList::displayCafes() {

    if (head == NULL) std::cout << "No cafes in the given city." << std::endl;

    else {

        std::cout << this->listCity << std::endl;

        cafeNode *travel = head;
        while (travel != NULL) {
            travel->cafe.displayAddress();
            travel = travel->next;
        }
    }

}


//========================================================================

bool CafeList::exists(int cafeId) {
    cafeNode *travel = head;

    while (travel != NULL) {
        if (travel->cafe.sameId(cafeId)) return true;
        travel = travel->next;
    }
    return false;


}


//========================================================================

bool CafeList::addCafe(Cafe cafe) {

    if(!cafe.sameCity(this->listCity)){
        std::cerr << "Cafe in wrong city." << std::endl;
        return false;
    }

    cafeNode *newCafeNode;

    try {
        newCafeNode = new cafeNode;
    }
    catch (std::bad_alloc) {
        std::cerr << "Memory allocation failed. " << std::endl;
        return false;
    }

    newCafeNode->cafe = cafe;

// empty list scenario
    if (head == NULL) {
        head = newCafeNode;
        newCafeNode->next = NULL;
        return true;
    }

// 1 element list
    if (head->next == NULL) {
        head->next = newCafeNode;
        newCafeNode->next = NULL;
        return true;
    }

// list is non empty, more than 1 element
    cafeNode *travel = head;      //setting up pointer 'travel' to go through the list
    while (travel->next != NULL) {
        travel = travel->next;
    } //here 'travel' is pointing at the last element of the list

    travel->next = newCafeNode;    //adding the product at the end of the list, method has succeeded!
    newCafeNode->next = NULL;

    return true;

}

//========================================================================

bool CafeList::removeCafe(int cafeId) {

    // empty list
    if (head == NULL) {
        std::cerr << "No cafes in the given city." << std::endl;
        return true;
    }
// 1 element list
    if (head->next == NULL) {
        if (head->cafe.sameId(cafeId)) {
            cafeNode *temp = head;
            head = NULL;
            delete temp;
            return true;
        } else {
            std::cerr << "Couldn't find cafe of ID " << cafeId << "." << std::endl;
            return false;
        }
    }

// non empty list, more than 1 element

    cafeNode *travel = head;

// sought element on the head of the list
    if (head->cafe.sameId(cafeId)) {
        cafeNode *temp = head;
        head = travel->next;
        delete temp;
        return true;
    }
// travelling through the list to find the product

    while (travel->next != NULL) {
        if (travel->next->cafe.sameId(cafeId)) {
            cafeNode *temp = travel->next;
            travel->next = travel->next->next;
            delete temp;
            return true;
        }
        travel = travel->next;
    }

    std::cerr << "Couldn't find cafe of ID " << cafeId << "." << std::endl;
    return false;

}

//========================================================================

bool CafeList::cityNameEquals(std::string aCityName) {

    return this->listCity==aCityName;

}