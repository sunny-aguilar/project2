/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo Tycoon -
**
**
**
**
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstring>
#include <sstream>
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
    void animalSick();
    void menuAnimalDead(int num);
    void menuBabyBorn(int num);
    void menuAttendanceBoom(double bonustigersQty);
    void menuNoRandomEvent();
    void menuBuyNewAnimal();
    void menuBuyAnimalSelectionMade(int select);
    void menuPurchaseReport(int select, double cost, double balance);
    void menuCapacityIncrease(int sel, int qty, int cap);
    void menuKeepPlaying();
    void menuBankrupt(double balance);
    void quitGameMssg();

private:
    int selection;
};

#endif
