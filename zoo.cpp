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
#include <iostream>
using std::cout;
using std::endl;

// initialize the tigerArray to hold ten animal pointers
Zoo::Zoo()
    : animals(new Animal*[4]), bankBalance{100000}, randomEvent{false} {
}

void Zoo::playGame() {
    menu.mainMenu();
}

void Zoo::start() {

}

void Zoo::resizeArray() {
    Animal **newTigerArray = new Animal*[10];
    for (int i = 0; i < 20; i++) {
        newTigerArray[i] = new Tiger;
    }

    // deallocate prior memory
    for (int i = 0; i < 6; i++) {
        delete animals[i];
    }
    delete [] animals;
    // assign new pointer address to old pointer
    animals = newTigerArray;
}

void Zoo::setNull(int val) {
    animals[0] = nullptr;
}


void Zoo::addTigers() {

}

void Zoo::resizeTigerArray(int size) {
//    if (tigerQty > tigerArrayCapacity) {
//        // this is a pointer to a pointer of type Animal that
//        // holds an array of animal pointers - too much for
//        // what we need here
//        Animal **newTigerArray = new Animal*[size];
//        for (int i = 0; i < 10; i++) {
//            newTigerArray[i] = animals[i];
//        }
//
//        // deallocate prior memory
//        for (int i = 0; i < 6; i++) {
//            delete animals[i];
//        }
//        delete [] animals;
//        // assign new pointer address to old pointer
//        animals = newTigerArray;
//
//        // this is a pointer of Animal type that is being
//        // assigned that is holding
////        Animal *newTigerArray = new Tiger[size];
////        for (int i = 0; i < 10; i++) {
////            newTigerArray[i] = tigerArray[i];
////        }
//
////        tigerArrayCapacity *= 2;
////        delete tigerArray[0];
////        tigerArray[0] = newTigerArray;
//
//        // use this for debugging purposes
//        // can also use to display total array capacity and usage
//    }
}


Animal *Zoo::gettigerArrayPtr(int elem) {
//    return &tigerArray;
    return animals [elem];
}
