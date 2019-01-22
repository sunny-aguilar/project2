/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo Tycoon - this game allows players to run a zoo
**                  business with different types of animals. The
**                  animals have prices, maintenance costs, can die
**                  and have babies. A player starts with a bank
 *                  balance of $100,000 and earns revenues for each
 *                  type of animal and pays expenses for feeding them.
 *                  If the bank balance falls below $0, the player
 *                  goes bankrupt and the game is over.
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
    Zoo zoo;            // create game object
    zoo.playGame();     // play the game
    return 0;
}