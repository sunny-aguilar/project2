/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo Tycoon -
**
**
**
**
*********************************************************************/
#include "zoo.hpp"
#include "tiger.hpp"

Zoo::Zoo() : tigerArray( new Tiger[10] ) {}

void Zoo::addTigers() {


}

void Zoo::resizeArray(int size) {
    Animal *newTigerArray = new Tiger[size];
    for (int i = 0; i < 10; i++) {
        newTigerArray[i] = tigerArray[i];
    }
    delete [] tigerArray;
    tigerArray = newTigerArray;
}

void Zoo::getTiger() {
//    tigers[0]->shout();
//    tigers[1]->shout();
    std::cout << std::endl;
}