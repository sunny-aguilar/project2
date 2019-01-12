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
    : tigerArray( new Animal*[3]{new Tiger} ), bankBalance{100000} {
}

//Zoo::Zoo() {
//    tigerArray = new Animal*[10];
//    for (int i = 0; i < 10; i++) {
//        tigerArray[0] = new Animal;
//    }
//}

void Zoo::resizeArray() {
    Animal **newTigerArray = new Animal*[20];
    for (int i = 0; i < 20; i++) {
        newTigerArray[i] = new Tiger;
    }

    // deallocate prior memory
    for (int i = 0; i < 6; i++) {
        delete tigerArray[i];
    }
    delete [] tigerArray;
    // assign new pointer address to old pointer
    tigerArray = newTigerArray;
}



void Zoo::addTigers() {

}

void Zoo::resizeTigerArray(int size) {
    if (tigerQty > tigerArrayCapacity) {
        // this is a pointer to a pointer of type Animal that
        // holds an array of animal pointers - too much for
        // what we need here
        Animal **newTigerArray = new Animal*[size];
        for (int i = 0; i < 10; i++) {
            newTigerArray[i] = tigerArray[i];
        }

        // deallocate prior memory
        for (int i = 0; i < 6; i++) {
            delete tigerArray[i];
        }
        delete [] tigerArray;
        // assign new pointer address to old pointer
        tigerArray = newTigerArray;

        // this is a pointer of Animal type that is being
        // assigned that is holding
//        Animal *newTigerArray = new Tiger[size];
//        for (int i = 0; i < 10; i++) {
//            newTigerArray[i] = tigerArray[i];
//        }

//        tigerArrayCapacity *= 2;
//        delete tigerArray[0];
//        tigerArray[0] = newTigerArray;

        // use this for debugging purposes
        // can also use to display total array capacity and usage
    }
}

/*********************************************************************
** Description:    testing objects in array
*********************************************************************/
void Zoo::setTigerLegs() {
    tigerArray[0][0].legs = 4;
    tigerArray[0][1].legs = 5;
    tigerArray[0][2].legs = 6;
//    cout << tigerArray[0][0].legs << endl;
//    cout << tigerArray[0][1].legs << endl;
//    cout << tigerArray[0][2].legs << endl;
//    tigerArray[1]->legs = 5;
//    tigerArray[2]->legs = 6;
}

/*********************************************************************
** Description:    testing objects in array
*********************************************************************/
void Zoo::getTigerLegs() {
    if (tigerArray[0] == nullptr) {
        cout << "Pointer is null\n";
    }

    cout << "0 Tiger: " << tigerArray[0]->legs << endl;
    cout << "1 Tiger: " << tigerArray[0][1].legs << endl;
    cout << "2 Tiger: " << tigerArray[0][2].legs << endl;
}

//Animal *Zoo::gettigerArrayPtr(int elem) {
////    return &tigerArray;
//    return &tigerArray[elem];
//}

void Zoo::tigerArrayAddress() {
    cout << "*tigerArray address: " << tigerArray << endl;
    cout << "*tigerArray[0] address: " << &tigerArray[0] << endl;
//    cout << "*tigerArray[0] address held: " << tigerArray[0] << endl;

    if (&tigerArray[0] == nullptr) {
        cout << "null pointer!\n";
    }
    cout << "Array size :" << sizeof(tigerArray) / sizeof(tigerArray[0]) << endl;

//    if (tigerArray[0] == nullptr) {
//        std::cout << "null pointer!\n";
//    }

}