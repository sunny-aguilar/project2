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
    // create random number seed
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    // create game object
    Zoo zoo;
    // play the game
    zoo.playGame();
    return 0;
}