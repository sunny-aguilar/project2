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
#include <iostream>
using std::cout;
using std::endl;

// initialize starting variable amounts
Zoo::Zoo() :
    animals(new Animal*[3]),
    bankBalance{100000},
    randomEvent{false},
    tigerQty{0},
    penguinQty{0},
    turtleQty{0},
    baseFoodCost{10} {
}

void Zoo::playGame() {
    // show main menu
    menu.mainMenu();

    // display menus to purchase initial animals
    menu.initialTigers();
    tigerQty = menu.validateNumber(1,2);
    menu.initialPenguins();
    penguinQty = menu.validateNumber(1,2);
    menu.initialTurtles();
    turtleQty = menu.validateNumber(1,2);

    // dynamically allocate animals
    initializeAnimals();

    // check if game shoudl continue
    while (!startDay()) {
        // while startDay() returns true, game continues
        // if startDay() returns false, end game
    }

    // game over message
    menu.gameOverMssg();
}

/*********************************************************************
** Description:     dynamically allocate starting animal amount
*********************************************************************/
void Zoo::initializeAnimals() {
    // initialize starting animals
    animals[0] = new Animal[tigerQty];
    animals[1] = new Animal[penguinQty];
    animals[2] = new Animal[turtleQty];

    startUpCosts();
}

/*********************************************************************
** Description:     purchase animals and
*********************************************************************/
void Zoo::startUpCosts() {
    int startCosts = 0;
    startCosts = (tigerQty      * 10000)
               + (penguinQty    * 1000)
               + (turtleQty     * 100);

    bankBalance -= startCosts;

    cout << "Total start up costs $" << startCosts << endl;
    cout << "Remaining Bank Balance $" << bankBalance << endl;
}

/*********************************************************************
** Description:     start each day and repeat
*********************************************************************/
bool Zoo::startDay() {
    int day = 1;
    menu.starDayMessage(day);

    do {
        // check bank balance
        if (bankBalance < 0) {
            gameOver = true;
            continueDay = false;
            return gameOver;
        }
        // increase animal age by 1 day
        ageAnimals();

        // display animals
        countAnimals();

        // feed the animals and pay feeding costs


        // subtract feeding costs form bank

        // random event

        // calculate daily profit including bonus

        // ask user to purchase an adult animal

        // prompt user if keep playing

        // show daily profit

        cout << "press ENTER to continue\n";
        cin.get();

        day++;
    } while (continueDay);

}

/*********************************************************************
** Description:     increase animal age by 1 day each time this
**                  function is called
*********************************************************************/
void Zoo::ageAnimals() {
    for (int index = 0; index < tigerQty; index++) {
        animals[0][index].increaseAnimalAge();
    }
    for (int index = 0; index < penguinQty; index++) {
        animals[1][index].increaseAnimalAge();
    }
    for (int index = 0; index < turtleQty; index++) {
        animals[2][index].increaseAnimalAge();
    }

//    int index = 0;
//    int animalArr[] = {tigerQty, penguinQty, turtleQty};
//
//    for (int type = 0; type < 3; type++) {
//        for (int num = 0; num < animalArr[index]; num++) {
//            animals[type][num].increaseAnimalAge();
//        }
//        index++;
//    }

    cout << "Tiger Ages: ";
    for (int index = 0; index < tigerQty; index++) {
        cout << animals[0][index].getAge() << " ";
    }
    cout << endl;
}

void Zoo::countAnimals() {
    cout << tigerQty << endl;
    cout << penguinQty << endl;
    cout << turtleQty << endl;
}

void Zoo::dailyBudget() {
    double tigerRevenues = (10000 * .20) * tigerQty;
    double penguinRevenues = (1000 * .10 ) * penguinQty;
    double turtleRevenues = (100 * 0.05) * turtleQty;
    double tigerCosts = (10 * 5) * tigerQty;
    double penguinCosts = 10 * penguinQty;
    double turtleCosts = (10 * 0.5) * turtleQty;

    cout << "Daily Revenues:\n";
    cout << "Tiger Revenues: $" << tigerRevenues << endl;
    cout << "Penguin Revenues: $" << penguinRevenues << endl;
    cout << "Turtle Revenues: $" << turtleRevenues << endl;
    cout << "Total Revenues: $" << tigerRevenues+penguinRevenues+turtleRevenues << endl;

    cout << "Daily Expenses:\n";
    cout << "Tiger Feeding Costs: $" << (10 * 5) * << endl;
    cout << "Penguin Feeding Costs: $" <<
    cout << "Turtle Feeding Costs: $" <<
    cout << "Total Expenses: $" <<
}











//void Zoo::resizeArray() {
//    Animal **newTigerArray = new Animal*[10];
//    for (int i = 0; i < 20; i++) {
//        newTigerArray[i] = new Tiger;
//    }
//
//    // deallocate prior memory
//    for (int i = 0; i < 6; i++) {
//        delete animals[i];
//    }
//    delete [] animals;
//    // assign new pointer address to old pointer
//    animals = newTigerArray;
//}



//void Zoo::resizeTigerArray(int size) {
//    if (tigerQty > tigerArrayCapacity) {
//        // this is a pointer to a pointer of type Animal that
//        // holds an array of animal pointers - too much for
//        // what we need here
//        Animal **newTigerArray = new Animal*[size];
//        for (int i = 0; i < 10; i++) {
//            newTigerArray[i] = animals[i];
//        }
//
//        // deallocate prior memory
//        for (int i = 0; i < 6; i++) {
//            delete animals[i];
//        }
//        delete [] animals;
//        // assign new pointer address to old pointer
//        animals = newTigerArray;
//
//        // this is a pointer of Animal type that is being
//        // assigned that is holding
////        Animal *newTigerArray = new Tiger[size];
////        for (int i = 0; i < 10; i++) {
////            newTigerArray[i] = tigerArray[i];
////        }
//
////        tigerArrayCapacity *= 2;
////        delete tigerArray[0];
////        tigerArray[0] = newTigerArray;
//
//        // use this for debugging purposes
//        // can also use to display total array capacity and usage
//    }
//}

