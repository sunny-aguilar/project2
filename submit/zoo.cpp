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

    // check if game should continue
    while (!startDay()) {
        // while startDay() returns true, game continues
        // if startDay() returns false, end game
    }

    // game over message
    menu.gameOverMssg();
}

/*********************************************************************
** Description:     dynamically allocate starting animal amount for
**                  each type of animal
*********************************************************************/
void Zoo::initializeAnimals() {
    // initialize starting animals
    animals[0] = new Animal[tigerQty];
    animals[1] = new Animal[penguinQty];
    animals[2] = new Animal[turtleQty];

    for (int index = 0; index < tigerQty; index++) {
        animals[0][index] = Tiger(0);
    }
    for (int index = 0; index < penguinQty; index++) {
        animals[1][index] = Penguin(0);
    }
    for (int index = 0; index < turtleQty; index++) {
        animals[2][index] = Turtle(0);
    }

    // subtract animal start-up costs
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
        // boom revenues, if chosen, are added in randomEvents();
        calculateDailyProfit();

        // ask user to purchase an adult animal
        purchaseAdultAnimal();

        // show daily profit
        cout << "Daily Profit: $REPORT HERE\n\n";

        // prompt user if keep playing
        continueDay = keepPlaying();

        day++;
    } while (continueDay);

}

/*********************************************************************
** Description:     increase animal age by 1 day each time this
**                  function is called
*********************************************************************/
void Zoo::ageAnimals() {
    // loop through all animal array and increase their ages
    int animalArr[] = {tigerQty, penguinQty, turtleQty};
    for (int type = 0; type < 3; type++) {
        for (int total = 0; total < animalArr[type]; total++) {
            animals[type][total].increaseAnimalAge();
        }
    }

    for (int index = 0; index < tigerQty; index++) {
        cout << "Tiger Age: " << animals[0][index].getAge() << " ";
    }
    cout << endl;
    for (int index = 0; index < penguinQty; index++) {
        cout << "Penguin Age: " << animals[1][index].getAge() << " ";
    }
    cout << endl;
    for (int index = 0; index < turtleQty; index++) {
        cout << "Turtle Age: " << animals[2][index].getAge() << " ";
    }
    cout << endl;
}

void Zoo::countAnimals() {
    cout << "Total Tigers: " << tigerQty << endl;
    cout << "Total Penguins: " <<  penguinQty << endl;
    cout << "Total Turtles: " <<  turtleQty << endl << endl;
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
    cout << "  Tiger Revenues: $" << std::setw(10) << tigerRevenues << endl;
    cout << "  Penguin Revenues: $" << std::setw(10) << penguinRevenues << endl;
    cout << "  Turtle Revenues: $" << std::setw(10) << turtleRevenues << endl;
    cout << "  Total Revenues: $" << std::setw(10) << totalRevenues << endl;

    cout << "\nDaily Expenses:\n";
    cout << "  Tiger Feeding Costs: $" << tigerCosts << endl;
    cout << "  Penguin Feeding Costs: $" << penguinCosts << endl;
    cout << "  Turtle Feeding Costs: $" << turtleCosts << endl;
    cout << "  Total Expenses: $" << totalFeedExpenses << endl << endl;

    cout << "Daily Net Profit/(Loss):\n"
         << "  Total Revenues: $" << totalRevenues << endl
         << "  Total Expenses: $" << totalFeedExpenses << endl
         << "  Net Profit/(Loss): $" << netIncome << endl << endl;

    cout << "Bank Balance $" << bankBalance + netIncome << endl << endl;
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
    // ADD LOGIC HERE SKIP OVER ANIMALS WHERE QTY = 0 AND IT SHOULD
    // FLOW DOWN BELOW TO THE SWITCH STATEMENT

    menu.menuAnimalDead(randomAnimal);
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
                int remaining = penguinQty--;
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
                int remaining = turtleQty--;
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
    double bonus = (rand() % (500 - 250 + 1)) + 250;
    cout << "Bonus: $" << bonus << endl;
    bonus *= tigerQty;
    bankBalance += bonus;
    menu.menuAttendanceBoom(bonus);
}

void Zoo::animalBorn() {
    bool babiesAvailable;
    int animalBorn;

    // first check if there are any adults before randomly choosing
    // which animal to have babies
    bool adultAnimals[3] = {false, false, false};
    babiesAvailable = adultCheck(adultAnimals);

    // babies are available
    if (babiesAvailable) {
        // if adultAnimals[n] array has any adults, randomly select
        // a value in the array until one selected is true
        bool findAnimal = true;
        do {
            // generate random number from 0 - 2
            animalBorn = rand() % 2;
            if (adultAnimals[animalBorn]) {
                spawnAnimal(animalBorn);
                findAnimal = false;
            }
        } while (findAnimal);
    }
    else {
        cout << "Spring has come however there are no adult "
             << "animals to have babies\n\n";
    }
}

bool Zoo::adultCheck(bool adultAnimals[]) {
    bool adultsPresent = false;
    int animalArr[] = {tigerQty, penguinQty, turtleQty};
    for (int type = 0; type < 3; type++) {
        for (int total = 0; total < animalArr[type]; total++) {
            if (animals[type][total].getAge() >= 3) {
                adultsPresent = adultAnimals[type] = true;
            }
        }
    }
    return adultsPresent;
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
                delete [] animals[1];
                animals[1] = tempAnimal;

                for (int index = 0; index < 5; index++) {
                    animals[1][penguinQty - 5 + index] = Penguin(0);
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
                    animals[2][index - 10 + index] = Turtle{0};
                }
            }
            break;
        default:
            cout << "Unable to create a new baby!\n";
    }
}

void Zoo::calculateDailyProfit() {
    // calculate revenues for all animals
    double tigerRevenues = animals[0]->getPayOff() * tigerQty;
    double penguinRevenues = animals[1]->getPayOff() * penguinQty;
    double turtleRevenues = animals[2]->getPayOff() * turtleQty;

    // calculate feed expenses for all animals
    double tigerCosts = animals[0]->getFoodCost() * tigerQty;
    double penguinCosts = animals[1]->getFoodCost() * penguinQty;
    double turtleCosts = animals[2]->getFoodCost() * turtleQty;

    // calculate net income for the day
    double totalRevenues = tigerRevenues+penguinRevenues+turtleRevenues;
    double totalFeedExpenses = tigerCosts+penguinCosts+turtleCosts;
    double netIncome = totalRevenues - totalFeedExpenses;

    dailyProfit = netIncome;
}

/*********************************************************************
** Description:     a
**                  function is called
*********************************************************************/
void Zoo::purchaseAdultAnimal() {
    menu.menuBuyNewAnimal();
    int selection = menu.validateNumber(1,2);

    if (selection == 1) {
        menu.menuBuyAnimalSelectionMade(selection);
        selection = menu.validateNumber(1,3);
        addPurchasedAnimal(selection);
    }
    else if (selection == 2) {
        menu.menuBuyAnimalSelectionMade(selection);
    }
}

/*********************************************************************
** Description:     functions takes an int parameter that is used to
**                  select the type of animal to add and dynamically
 *                  adds the animal to the right category
*********************************************************************/
void Zoo::addPurchasedAnimal(int selection) {
    switch (selection) {
        case 1: // add one adult tiger
            {
                tigerQty++;
                Animal *tempAnimal = new Tiger[tigerQty];
                for (int index = 0; index < tigerQty - 1; index++) {
                    tempAnimal[index] = animals[0][index];
                }
                delete [] animals[0];
                animals[0] = tempAnimal;

                for (int index = 0; index < 1; index++) {
                    animals[0][tigerQty - 1] = Tiger(3);
                }
            }
            purchaseBalanceUpdate(selection);
            break;
        case 2: // add one adult penguin
            {
                penguinQty++;
                Animal *tempAnimal = new Penguin[penguinQty];
                for (int index = 0; index < penguinQty - 1; index++) {
                    tempAnimal[index] = animals[1][index];
                }
                delete [] animals[1];
                animals[1] = tempAnimal;

                for (int index = 0; index < 1; index++) {
                    animals[1][penguinQty - 1] = Penguin(3);
                }
            }
            purchaseBalanceUpdate(selection);
            break;
        case 3: // add one adult turtle
            {
                turtleQty++;
                Animal *tempAnimal = new Turtle[turtleQty];
                for (int index = 0; index < turtleQty - 1; index++) {
                    tempAnimal[index] = animals[2][index];
                }
                delete [] animals[2];
                animals[2] = tempAnimal;

                for (int index = 0; index < 1; index++) {
                    animals[2][turtleQty - 1] = Turtle(3);
                }
            }
            purchaseBalanceUpdate(selection - 1);
            cout << "Turtle cost subtracted\n";
            break;
        default:
            cout << "Unable to add an animal!\n";
    }
}

/*********************************************************************
** Description:     functions takes an int parameter that is used to
**                  select the type of animal that was purchased,
**                  determines the cost, and updates the bank balance
**                  accordingly
*********************************************************************/
void Zoo::purchaseBalanceUpdate(int selection) {
    double animalCost = animals[selection]->getAnimalCost();
    bankBalance -= animalCost;
}

void Zoo::dailyFinancialReport() {

}


bool Zoo::keepPlaying() {
    menu.menuKeepPlaying();
    int selection = menu.validateNumber(1,2);
    switch (selection) {
        case 1:
            return true;
            break;
        case 2:
            return false;
            break;
        default:
            cout << "Unable to determine whether to keep playing!\n";
    }
}