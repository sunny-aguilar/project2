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
        : tigerArray( new Tiger[10] ), bankBalance{100000} {
}

Zoo::~Zoo() { delete [] tigerArray; }

void Zoo::addTigers() {

}

void Zoo::resizeTigerArray(int size) {
    if (tigerQty > tigerArrayCapacity) {
//        Animal **newTigerArray = new Animal*[size];
//        for (int i = 0; i < 10; i++) {
//            newTigerArray[i] = tigerArray[i];
//        }

        Animal *newTigerArray = new Tiger[size];
        for (int i = 0; i < 10; i++) {
            newTigerArray[i] = tigerArray[i];
        }

        tigerArrayCapacity *= 2;
        delete [] tigerArray;
        tigerArray = newTigerArray;
    }
}







/*********************************************************************
** Description:    testing objects in array
*********************************************************************/
void Zoo::setTigerLegs() {
    tigerArray[0]->legs = 4;
    tigerArray[1]->legs = 5;
    tigerArray[2]->legs = 6;
}

/*********************************************************************
** Description:    testing objects in array
*********************************************************************/
void Zoo::getTigerLegs() {
    std::cout << "0 Tiger: " << tigerArray[0]->legs << std::endl;
    std::cout << "1 Tiger: " << tigerArray[1]->legs << std::endl;
    std::cout << "2 Tiger: " << tigerArray[2]->legs << std::endl;
}