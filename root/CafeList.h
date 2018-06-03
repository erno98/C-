//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#ifndef UNTITLED_CAFELIST_H
#define UNTITLED_CAFELIST_H

////------------------------------------
//CafeList contains a linked list
//containing objects of Cafe, making
//all its objects to be connected.
//Every city has its own list of cafes.
////------------------------------------


#include "Cafe.h"

class CafeList {
private:
    struct cafeNode{
        Cafe cafe;
        cafeNode *next;
    };


    cafeNode* head = NULL;
    std::string listCity;

public:
    CafeList();
    explicit CafeList(std::string cityName);
    ~CafeList();
    void displayCafeInfo(short int aCafeId);
	/**********************************
	* displays information about given*
	* cafe (ID) in the console:       *
	* id, city, postal code, street   *
	* name, house number. It uses the *
	* method displayAddress() from    *
	* class Cafe                      *
	**********************************/
	
	
    void displayCafes();
	/**********************************
	* displays information about all  *
	* cafes in the console, in same   *
	* way as in displayCafeInfo()     *
	**********************************/

	
    bool exists(int cafeId);
	/**********************************
	* returns true if Cafe of the     *
	* given ID exists in the list     *
	**********************************/
	
	
    bool addCafe(Cafe cafe);
	/**********************************
	* adds existing object of Cafe to *
	* the the list                    *
	**********************************/
	
	
    bool removeCafe(int cafeId);
	/**********************************
	* removes existing Cafe object of *
	* given ID from the list, returns *
	* false if there's no cafe of     *
	* given ID                        *
	**********************************/
	
	
    bool cityNameEquals(std::string aCityName);
	/**********************************
	* returns true if the given city  *
	* name is the same as list's      *
	**********************************/

};


#endif //UNTITLED_CAFELIST_H
