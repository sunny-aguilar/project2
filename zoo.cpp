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
#include <iostream>
#include <iomanip>
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

Zoo::~Zoo() {
    for (int index = 0; index < 3; index++) {
        delete [] animals[index];
    }
    delete []  animals;
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

        // display daily budget
        dailyBudget();

        // feed the animals and pay feeding costs
        feedAnimals();

        // random event
        randomEvents();

        // calculate daily profit including bonus
        // possibly cout the daily profits here
        calculateDailyProfit();

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
    double totalRevenues = tigerRevenues+penguinRevenues+turtleRevenues;
    double totalFeedExpenses = tigerCosts+penguinCosts+turtleCosts;
    double netIncome = totalRevenues - totalFeedExpenses;

    cout << std::fixed << std::setprecision(2);
    cout << "Daily Revenues:\n";
    cout << "Tiger Revenues: $" << std::setw(10) << tigerRevenues << endl;
    cout << "Penguin Revenues: $" << std::setw(10) << penguinRevenues << endl;
    cout << "Turtle Revenues: $" << std::setw(10) << turtleRevenues << endl;
    cout << "Total Revenues: $" << std::setw(10) << totalRevenues << endl;

    cout << "\nDaily Expenses:\n";
    cout << "Tiger Feeding Costs: $" << tigerCosts << endl;
    cout << "Penguin Feeding Costs: $" << penguinCosts << endl;
    cout << "Turtle Feeding Costs: $" << turtleCosts << endl;
    cout << "Total Expenses: $" << totalFeedExpenses << endl << endl;

    cout << "Net Profit/(Loss): $" << netIncome << endl << endl;
}

void Zoo::feedAnimals() {
    double tigerCosts = (10 * 5) * tigerQty;
    double penguinCosts = 10 * penguinQty;
    double turtleCosts = (10 * 0.5) * turtleQty;
    double totalFeedExpenses = tigerCosts+penguinCosts+turtleCosts;
    bankBalance -= totalFeedExpenses;
}

void Zoo::randomEvents() {
    // generate a random number 1 - 4
    int randomNumber = rand() % 4 + 1;
    switch (randomNumber) {
        case 1:
            animalSickness();
            break;
        case 2:
            attendanceBoom();
            break;
        case 3:
            animalBorn();
            break;
        case 4:
            menu.menuNoRandomEvent();
            break;
        default:
            cout << "error! unable to generate a random event!\n";
    }
}

/*********************************************************************
** Description:     this function randomly chooses which animals gets
**                  sick and dies. Animal quantity is first reduced
**                  by one. A temporary animal pointer to an array of
**                  animals is then dynamically created from the
**                  remaining animals. The temporary array is then
**                  assigned the animal objects in the old array
**                  (except for the one that dies). The old array
**                  is then de-allocated and assigned the memory
**                  location of the temporary animal pointer.
*********************************************************************/
void Zoo::animalSickness() {
    menu.animalSick();
    // randomly pick an animal to die
    int randomAnimal = rand() % 2;
    switch (randomAnimal) {
        case 0:
            {
                int remaining = tigerQty--;
                Animal *tempAnimal = new Tiger[remaining];
                for (int index = 0; index < remaining; index++) {
                    tempAnimal[index] = animals[0][index];
                }
                delete [] animals[0];
                animals[0] = tempAnimal;
            }
            break;
        case 1:
            {
                int remaining = penguinQty - 1;
                Animal *tempAnimal = new Penguin[remaining];
                for (int index = 0; index < remaining; index++) {
                    tempAnimal[index] = animals[1][index];
                }
                delete [] animals[1];
                animals[1] = tempAnimal;
            }
            break;
        case 2:
            {
                int remaining = turtleQty - 1;
                Animal*tempAnimal = new Turtle[remaining];
                for (int index = 0; index < remaining; index++) {
                    tempAnimal[index] = animals[2][remaining];
                }
                delete [] animals[2];
                animals[2] = tempAnimal;
            }
            break;
        default:
            cout << "Unable to randomly choose an animal to die!\n";
    }
}

void Zoo::attendanceBoom() {
    menu.menuAttendanceBoom();
    double bonus = (rand() % (500 - 250 + 1)) + 250;
    bankBalance += bonus;
}

void Zoo::animalBorn() {
    bool adultTiger = false;
    bool adultPenguin = false;
    bool adultTurtle = false;
    bool selectAnimal = true;
    bool babiesAvailable = false;
    int animalBorn;

    // first check if there are any adults before randomly choosing
    // which animal to have babies
    babiesAvailable = adultCheck();

    // babies are available
    if (babiesAvailable) {
        // select a random animal to have babies. Not all animal types
        // may have adults therefore do while loop will keep checking
        // until it finds animals with adults
        do {
            // generate random number from 0 - 2
            animalBorn = rand() % 2;

            if (animalBorn == 0) {
                for (int index = 0; index < tigerQty; index++) {
                    if (animals[0][index].getAge() >= 3) {
                        selectAnimal = false;
                        spawnAnimal(animalBorn);
                    }
                }
            }
            else if (animalBorn == 1) {
                for (int index = 0; index < penguinQty; index++) {
                    if (animals[1][index].getAge() >= 3) {
                        selectAnimal = false;
                        spawnAnimal(animalBorn);
                    }
                }
            }
            else if (animalBorn == 2) {
                for (int index = 0; index < turtleQty; index++) {
                    if (animals[2][index].getAge() >= 3) {
                        selectAnimal = false;
                        spawnAnimal(animalBorn);
                    }
                }
            }
        } while (selectAnimal);

    }
    else {
        cout << "Spring is in the air however there are no adult "
             << "animals to have babies\n";
    }
}

bool Zoo::adultCheck() {
    for (int index = 0; index < tigerQty; index++) {
        if (animals[0][index].getAge() >= 3) {
            return true;
        }
    }
    for (int index = 0; index < penguinQty; index++) {
        if (animals[1][index].getAge() >= 3) {
            return true;
        }
    }
    for (int index = 0; index < turtleQty; index++) {
        if (animals[2][index].getAge() >= 3) {
            return true;
        }
    }
}

/*********************************************************************
** Description:     this function randomly chooses which animals gets
**                  sick and dies. Animal quantity is first reduced
**                  by one. A temporary animal pointer to an array of
**                  animals is then dynamically created from the
**                  remaining animals. The temporary array is then
**                  assigned the animal objects in the old array
**                  (except for the one that dies). The old array
**                  is then de-allocated and assigned the memory
**                  location of the temporary animal pointer.
*********************************************************************/
void Zoo::spawnAnimal(int num) {
    menu.menuBabyBorn(num);
    switch(num) {
        case 0:
            {
                tigerQty++;
                Animal *tempAnimal = new Tiger[tigerQty];
                for (int index = 0; index < tigerQty - 1; index++) {
                    tempAnimal[index] = animals[0][index];
                }
                delete [] animals[0];
                animals[0] = tempAnimal;

                for (int index = 0; index < 1; index++) {
                    animals[0][tigerQty - 1 + index] = Tiger(0);
                }
            }
            break;
        case 1:
            {
                penguinQty += 5;
                Animal *tempAnimal = new Penguin[penguinQty];
                for (int index = 0; index < penguinQty - 5; index++) {
                    tempAnimal[index] = animals[1][index];
                }
                delete [] animals[2];
                animals[1] = tempAnimal;

                for (int index = 0; index < 5; index++) {
                    animals[0][penguinQty - 5 + index] = Penguin(0);
                }
            }
            break;
        case 2:
            {
                turtleQty += 10;
                Animal *tempAnimal = new Turtle[turtleQty];
                for (int index = 0; index < turtleQty - 10; index++) {
                    tempAnimal[index] = animals[2][index];
                }
                delete [] animals[2];
                animals[2] = tempAnimal;

                for (int index = 0; index < 10; index++) {
                    animals[0][index - 10 + index] = Turtle{0};
                }
            }
            break;
        default:
            cout << "Unable to create a new baby!\n";
    }
}

void Zoo::calculateDailyProfit() {
    // Tiger Revenues 20% of 10,000/tiger
    // Penguin Revenues 10% of 1,000/penguin
    // Turtle Revenues 5% of 100/turtle
    double tigerRevenues = (10000 * .20) * tigerQty;
    double penguinRevenues = (1000 * .10 ) * penguinQty;
    double turtleRevenues = (100 * 0.05) * turtleQty;

    // base food costs is $10
    double tigerCosts = (10 * 5) * tigerQty;
    double penguinCosts = 10 * penguinQty;
    double turtleCosts = (10 * 0.5) * turtleQty;

    double totalRevenues = tigerRevenues+penguinRevenues+turtleRevenues;
    double totalFeedExpenses = tigerCosts+penguinCosts+turtleCosts;
    double netIncome = totalRevenues - totalFeedExpenses;

    dailyProfit = netIncome;
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

