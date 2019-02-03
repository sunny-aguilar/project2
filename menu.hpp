/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
** Description:     Menu class contains all of the menu and prompts
**                  that appear during the game. Menu objects lives
**                  inside of the Game Class. Menu functions may
**                  receive parameters from the game for display
**                  purposes. Menu class also contains the input
**                  validation function.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    int validateNumber(int min, int max);
    void mainMenu();
    void setSelection(int sel);
    int getSelection();
    void initialTigers();
    void initialPenguins();
    void initialTurtles();
    void menuStartupCost(double bal, int cost);
    void starDayMessage(int day);
    void menuSelectFeed();
    void menuAnimalAges(int, int, int, int, int, int);
    void menuBudget(double salesArr[], double costsArr[], double profitsArr[]);
    void animalSick();
    void menuAnimalSpared(int sel);
    void menuAnimalDead(int num);
    void menuBabyBorn(int num);
    void menuBabyNotBorn();
    void menuAttendanceBoom(double bonustigersQty);
    void menuNoRandomEvent();
    void menuBuyNewAnimal();
    void menuBuyAnimalSelectionMade(int select);
    void menuPurchaseReport(int select, double cost, double balance);
    void menuCapacityIncrease(int sel, int qty, int cap);
    void menuKeepPlaying();
    void menuBankrupt(double balance);
    void quitGameMssg(double balance);

private:
    int selection;
};

#endif
