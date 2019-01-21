/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo Tycoon -
**
**
**
**
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
    // menu class
    Menu menu;
    // zoo class
    Zoo();
    ~Zoo();
    void playGame();
    void initializeAnimals();
    void doubleCapacity(int select);
    void startUpCosts();
    bool startDay();
    void ageAnimals();
    void countAnimals();
    void feedAnimals();
    void randomEvents();
    void animalSickness();
    void attendanceBoom();
    void animalBorn();
    bool adultCheck(bool animalArr[]);
    void spawnAnimal(int num);
    void calculateDailyProfit();
    void purchaseAdultAnimal();
    void addPurchasedAnimal(int selection);
    void purchaseBalanceUpdate(int selection);
    void dailyFinancialReport();
    bool keepPlaying();

private:
    Animal **animals;      // array of pointers
    int tigerQty;
    int penguinQty;
    int turtleQty;
    int tigerCap;
    int penguinCap;
    int turtleCap;
    int chickenQty;
    double bankBalance;
    bool continueDay;
    bool gameOver;
    double boomBonus;
    double dailyProfit;
    double baseFoodCost;
    bool randomEvent;
};

#endif