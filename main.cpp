/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo Tycoon - this game allows players to run a zoo
**                  business with different types of animals. The
**                  animals have prices, maintenance costs, and return
**                  a project each day.
**
*********************************************************************/
#include "zoo.hpp"
#include "menu.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"
#include <iostream>

int main() {
    // add game control here
    Zoo zoo;
    Menu menu;
    Animal animal;
    Tiger tiger;
    Turtle turtle;
    Penguin penguin;

//    zoo.addTigers();
    zoo.getTiger();
//    zoo.getTiger(1);
//    zoo.getTiger(2);
//    zoo.getTiger(3);
//    zoo.getTiger(4);
//    zoo.getTiger(5);
//    zoo.getTiger(6);


    return 0;
}