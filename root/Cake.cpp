//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Cake.h"

Cake::Cake(std::string aName,
           double aPrice,
           bool aIsAvailable) : Product(aName, aPrice, aIsAvailable) {

    this->kcalPer100g = rand() % 600 + 300;
	
    srand((int)time(0));
    int randomFlavour = rand() % 3 + 1;

    switch (randomFlavour) {
        case 1:
            this->flavour = "Chocolate";
            this->isVegan = false;
            this->withLactose = true;
        case 2:
            this->flavour = "Strawberry";
            this->isVegan = true;
            this->withLactose = false;
        case 3:
            this->flavour = "Coconut";
            this->isVegan = false;
            this->withLactose = false;
        default:
            this->flavour = "Vanilla";
            this->isVegan = false;
            this->withLactose = true;
    }


}

//========================================================================

Cake::~Cake(){

}


//========================================================================

bool Cake::isHighInCalories() {

    return this->kcalPer100g > 450;
}



//========================================================================

void Cake::getCakeInfo() {
    std::cout << this->flavour << " cake,"
              << this->kcalPer100g << " kcal per 100g, ";
    if (isVegan) std::cout << "vegan, ";
    else std::cout << "not vegan, ";
    if (withLactose) std::cout << "with lactose." << std::endl;
    else std::cout << "without lactose." << std::endl;

}

