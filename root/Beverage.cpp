//
// Created by Ernest Pokropek on 2018-05-23
// for Warsaw University of Technology
// EOOP Project
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Beverage.h"

Beverage::Beverage(std::string aName,
                   double aPrice,
                   bool aIsAvailable) : Product(aName, aPrice, aIsAvailable) {

    this->isVegan = !(aName == "Milk");
    if(aName == "Milk"){
        fatPercentage = 3;
        this->type = "Milk";
    }

    if(aName == "Vodka" || aName == "Whisky" || aName == "Brandy") this->alcohol_in = 40;
    else if (aName == "Beer") this->alcohol_in = 5;
    else if (aName == "Wine") this->alcohol_in = 12;
    else this->alcohol_in = 0;

    if(this->alcohol_in > 0.0) this->type = "Alcohol";


    srand((int)time(0));
    int randomVolume = rand()%2;
    switch(randomVolume){
        case 0:
            this->volume = 250;
        case 1:
            this->volume = 330;
        case 2:
            this->volume = 500;
        default:
            this->volume = 200;

    }
}

//========================================================================

Beverage::~Beverage() {


}

//========================================================================

void Beverage::getBeverageInfo() {

    this->getInfo();
    std::cout << type << ", "
              << "volume per bottle: " << volume << " " << std::endl;
    if(this->type == "Alcohol") std::cout << alcohol_in << "% alcohol." << std::endl;
    else if(this->type == "Milk") std::cout << fatPercentage << "% fat." << std::endl;


}