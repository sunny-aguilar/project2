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
    void startUpCosts();
    bool startDay();
    void ageAnimals();
    void countAnimals();
    void dailyBudget();
    void feedAnimals();
    void randomEvents();
    void animalSickness();
    void attendanceBoom();
    void animalBorn();
    bool adultCheck();
    void spawnAnimal(int num);
    void calculateDailyProfit();
    void purchaseAdultAnimals();

private:
    Animal **animals;      // array of pointers
    int tigerQty;
    int penguinQty;
    int turtleQty;
    int bearQty;
    double bankBalance;
    bool continueDay;
    bool gameOver;
    double dailyProfit;
    double baseFoodCost;
    bool randomEvent;
};

#endif