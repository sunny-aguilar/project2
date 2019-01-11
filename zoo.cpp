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

// initialize the tigerArray to hold ten animal pointers
//Zoo::Zoo()
//    : tigerArray( new Animal*[10] ), bankBalance{100000} {
//}

Zoo::Zoo()
        : tigerArray{new Tiger[2]}, bankBalance{100000} {
}

Zoo::~Zoo() { delete [] tigerArray; }

void Zoo::addTigers() {

}

void Zoo::resizeTigerArray(int size) {
    if (tigerQty > tigerArrayCapacity) {
        // this is a pointer to a pointer of type Animal that
        // holds an array of animal pointers - too much for
        // what we need here
//        Animal **newTigerArray = new Animal*[size];
//        for (int i = 0; i < 10; i++) {
//            newTigerArray[i] = tigerArray[i];
//        }

        // this is a pointer of Animal type that is being
        // assigned that is holding
        Animal *newTigerArray = new Tiger[size];
        for (int i = 0; i < 10; i++) {
            newTigerArray[i] = tigerArray[i];
        }

        tigerArrayCapacity *= 2;
        delete [] tigerArray;
        tigerArray = newTigerArray;

        // use this for debugging purposes
        // can also use to display total array capacity and usage
        std::cout << sizeof(tigerArray) / sizeof(tigerArray[0]) << std::endl;
    }
}







/*********************************************************************
** Description:    testing objects in array
*********************************************************************/
void Zoo::setTigerLegs() {
    tigerArray[0].legs = 4;
    tigerArray[1].legs = 5;
    tigerArray[2].legs = 6;
}

/*********************************************************************
** Description:    testing objects in array
*********************************************************************/
void Zoo::getTigerLegs() {
    if (&tigerArray[0] == nullptr) {
        std::cout << "Pointer is null\n";
    }

    std::cout << "0 Tiger: " << tigerArray[0].legs << std::endl;
    std::cout << "1 Tiger: " << tigerArray[1].legs << std::endl;
    std::cout << "2 Tiger: " << tigerArray[2].legs << std::endl;
}

Animal *Zoo::gettigerArrayPtr(int elem) {
//    return &tigerArray;
    return &tigerArray[0];
}