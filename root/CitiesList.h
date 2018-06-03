//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//


#ifndef UNTITLED_CITIESLIST_H
#define UNTITLED_CITIESLIST_H

////------------------------------------
// Class for storing CafeList
// objects in a linked list
////------------------------------------

#include "CafeList.h"

class CitiesList {
private:
    struct cityNode{
        CafeList cafeList;
        cityNode* next;
    };

    cityNode* head = NULL;


public:
    CitiesList();
    ~CitiesList();

    bool addCity(CafeList city);
	/**********************************
	* adds an existing CafeList object*
	* to the cities list, returns     *
	* false in case of memory         *
	* allocation failure              *
	**********************************/
	
	
    bool removeCity(std::string cityName);
	/**********************************
	* removes city of given name from *
	* the list, returns false if      *
	* there's no city of given name in*
	* the list                        *
	**********************************/

    bool exists(std::string cityName);
	/**********************************
	* returns true if the city of     *
	* given name exists in the list   *
	**********************************/

    void displayStatus();
	/**********************************
	* displays in the console info    *
	* about all cities in the list,   *
	* uses the displayCityStatus()    *
	**********************************/
	
	
    void displayCityStatus(std::string cityName);
	/**********************************
	* displays in the console info    *
	* about cafes in city of given    *
	* name, uses                      *
	* CafeList::displayCafes()        *
	**********************************/


};


#endif //UNTITLED_CITIESLIST_H
