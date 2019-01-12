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
    // game variables
    bool playAgain = true;

    // add game control here
    Zoo zoo;
    Menu menu;
    Animal animal;
    Tiger tiger;
    Turtle turtle;
    Penguin penguin;

//    do {
//        // show main menu, validate & set selection
//        menu.mainMenu();
//        menu.setSelection( menu.validateNumber(1,2) );
//
//        if (menu.getSelection() == 1) {
//
//        }
//        else if (menu.getSelection() == 2) {
//            playAgain = false;
//        }
//
//
//
//    } while (playAgain);

    zoo.setTigerLegs();
    zoo.getTigerLegs();
//    zoo.resizeArray();

//    cout << "Array size :" << sizeof(zoo.tigerArray) / sizeof(zoo.tigerArray[0]) << endl;
//    cout << "Address held by zoo.tigerArray: " << zoo.tigerArray << endl;
//    cout << "Address assigned to testPtr1: " << testPtr1 << endl;
//    cout << "Address &zoo.tigerArray: " << &zoo.tigerArray << endl;
//    cout << "Address &testPtr1: " << &testPtr1 << endl;
//    cout << "Address tigerArray[0]: " << zoo.tigerArray[1] << endl;
//    if (zoo.tigerArray[10] == nullptr) {
//        cout << "null pointer\n";
//    }

//    zoo.tigerArrayAddress();
//    cout << "Address tigerArray[0]: " << zoo.gettigerArrayPtr(0) << endl;
//    cout << "Address tigerArray[1]: " << zoo.gettigerArrayPtr(1) << endl;
//    cout << "Address tigerArray[2]: " << zoo.gettigerArrayPtr(2) << endl;
//    cout << "Address tigerArray[3]: " << zoo.gettigerArrayPtr(3) << endl;
//    cout << "Address tigerArray[4]: " << zoo.gettigerArrayPtr(4) << endl;
//    zoo.setTigerLegs();
//    zoo.getTigerLegs();



    return 0;
}