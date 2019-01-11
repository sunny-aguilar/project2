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

void Zoo::addTigers() {
    for (int x = 0; x < 2; x++) {
        Animal *t = new Tiger;
        tigers[x] = t;
    }
//    tigers[0] = new Tiger;
}

void Zoo::getTiger() {
    tigers[0]->shout();
    tigers[1]->shout();
    std::cout << std::endl;
}