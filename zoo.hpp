/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo class is used to control the game operations.
**                  Zoo class contains and animal object and menu
**                  object. The game parameters are first set before
**                  the game begins. Game operations consist of
**                  tracking a user's player bank balance, calculating
**                  profits, adding and subtracting animals, and
**                  displaying the information to the user.
*********************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include <ctime>
#include "menu.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

class Zoo {
public:
    Zoo();
    ~Zoo();
    void playGame();
    void initializeAnimals();
    void doubleCapacity(int select);
    void startUpCosts();
    bool startDay();
    void ageAnimals();
    void countAnimals();
    void selectFeed();
    void feedAnimals();
    void randomEvents();
    void animalSickness();
    void attendanceBoom();
    void animalBorn();
    bool adultCheck(bool animalArr[]);
    void spawnAnimal(int num);
    void dailyFinancialReport();
    void purchaseAdultAnimal();
    void addPurchasedAnimal(int selection);
    void purchaseBalanceUpdate(int selection);
    bool keepPlaying();

private:
    Menu menu;              // menu class
    Animal **animals;       // pointer to pointer
    int tigerQty;
    int penguinQty;
    int turtleQty;
    int tigerCap;
    int penguinCap;
    int turtleCap;
    double bankBalance;
    bool continueDay;
    bool gameOver;
    double boomBonus;
    double dailyProfit;
    double baseFoodCost;
    bool randomEvent;
};

#endif