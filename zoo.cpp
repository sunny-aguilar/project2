/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:
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

/*********************************************************************
** Description:     default constructor that initializes variables
**                  and the three animals arrays
*********************************************************************/
Zoo::Zoo() :
    animals(new Animal*[3]),
    bankBalance{100000},
    boomBonus{0},
    dailyProfit{0},
    randomEvent{false},
    tigerQty{0},
    penguinQty{0},
    turtleQty{0},
    tigerCap{10},
    penguinCap{10},
    turtleCap{10},
    baseFoodCost{1} {
}

/*********************************************************************
** Description:     destructor that de-allocates the 2D array holding
**                  the three animal arrays
*********************************************************************/
Zoo::~Zoo() {
    for (int index = 0; index < 3; index++) {
        delete [] animals[index];
    }
    delete []  animals;
}

/*********************************************************************
** Description:     this function starts the game play by calling the
**                  main menu. It then initializes the starting
 *                  animal amounts, calls a function that dynamically
 *                  allocates the animal arrays, and then it uses a
 *                  loop to that is used to control and call the
 *                  activities composed in each day. The day ends
 *                  when the function startDay returns false from
 *                  the player choosing to quit or the player has
 *                  gone bankrupt.
*********************************************************************/
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

    // quit game message
    menu.quitGameMssg();
}

/*********************************************************************
** Description:     dynamically allocate starting animal amount for
**                  each type of animal. Each animal is set with age
 *                  of 0 so that the animals are 1 day old on day 1.
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
** Description:     this function takes in an int parameter that is
**                  used to select which animal capacity needs to be
**                  increase. Capacity increase is increased by 10
**                  each time.
*********************************************************************/
void Zoo::doubleCapacity(int select) {
    switch (select) {
        case 1: // resize tiger array
            {
                tigerCap += 10;
                menu.menuCapacityIncrease(select, tigerQty, tigerCap);
                Animal *tempAnimal = new Tiger[tigerCap];
                for (int index = 0; index < tigerQty; index++) {
                    tempAnimal[index] = animals[0][index];
                }
                delete [] animals[0];
                animals[0] = tempAnimal;
            }
            break;
        case 2: // resize penguin array
            {
                penguinCap += 10;
                menu.menuCapacityIncrease(select, penguinQty, penguinCap);
                Animal *tempAnimal = new Penguin[penguinCap];
                for (int index = 0; index < penguinCap; index++) {
                    tempAnimal[index] = animals[1][index];
                }
                delete [] animals[1];
                animals[1] = tempAnimal;
            }
            break;
        case 3: // resize turtle array
            {
                turtleCap += 10;
                menu.menuCapacityIncrease(select, turtleQty, turtleCap);
                Animal *tempAnimal = new Tiger[turtleCap];
                for (int index = 0; index < turtleCap; index++) {
                    tempAnimal[index] = animals[2][index];
                }
                delete [] animals[2];
                animals[2] = tempAnimal;
            }
            break;
        default:
            cout << "Unable to double the capacity!\n";
    }
}

/*********************************************************************
** Description:     purchase animals and determine the costs of the
**                  animals to subtract from the bank balance
*********************************************************************/
void Zoo::startUpCosts() {
    int startCosts = 0;
    startCosts = (tigerQty      * 10000)
               + (penguinQty    * 1000)
               + (turtleQty     * 100);

    bankBalance -= startCosts;
    menu.menuStartupCost(bankBalance, startCosts);
}

/*********************************************************************
** Description:     start each day and repeat until user quits or goes
**                  bankrupt. This function controls the daily
**                  activities of each turn.
*********************************************************************/
bool Zoo::startDay() {
    int day = 1;

    do {
        // show start of day banner
        menu.starDayMessage(day);
        // check bank balance, game ends if player is bankrupt
        if (bankBalance < 0) {
            gameOver = true;
            continueDay = false;
            menu.menuBankrupt(bankBalance);
            return gameOver;
        }

        /*      DAY ACTIVITIES      */
        // increase animal age by 1 day
        ageAnimals();

        // display animals
        countAnimals();

        // feed the animals and pay feeding costs
        selectFeed();
        feedAnimals();

        // random event
        randomEvents();

        // calculate daily profit including bonus
        // possibly cout the daily profits here
        // boom revenues, if chosen, are added in randomEvents();
        dailyFinancialReport();

        // ask user to purchase an adult animal
        purchaseAdultAnimal();

        // prompt user if keep playing
        continueDay = keepPlaying();

        day++;
    } while (continueDay);

    // if player quits, game ends
    if (!continueDay) {
        return true;
    }

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
}

/*********************************************************************
** Description:     counts baby and adult animals and calls a function
**                  to display the information
*********************************************************************/
void Zoo::countAnimals() {
    int adultTiger = 0;
    int adultPenguin = 0;
    int adultTurtle = 0;
    int babyTiger = 0;
    int babyPenguin = 0;
    int babyTurtle = 0;

    // compute tiger adult and baby ages
    for (int index = 0; index < tigerQty; index++) {
        if (animals[0][index].getAge() >= 3) {
            adultTiger++;
        }
        else if (animals[0][index].getAge() < 3) {
            babyTiger++;
        }
    }
    // compute penguin adult and baby ages
    for (int index = 0; index < penguinQty; index++) {
        if (animals[1][index].getAge() >= 3) {
            adultPenguin++;
        }
        else if (animals[1][index].getAge() < 3) {
            babyPenguin++;
        }
    }
    // compute turtle adult and baby ages
    for (int index = 0; index < turtleQty; index++) {
        if (animals[2][index].getAge() >= 3) {
            adultTurtle++;
        }
        else if (animals[2][index].getAge() < 3) {
            babyTurtle++;
        }
    }

    // display ages report
    menu.menuAnimalAges(adultTiger, babyTiger, adultPenguin, babyPenguin, adultTurtle, babyTurtle);
}

/*********************************************************************
** Description:     Extra Credit - Select feed type
*********************************************************************/
void Zoo::selectFeed() {
    menu.menuSelectFeed();
    int select = menu.validateNumber(1,3);
    switch (select) {
        case 1:
            baseFoodCost = 2;
            break;
        case 2:
            baseFoodCost = 1;
            break;
        case 3:
            baseFoodCost = 0.50;
            break;
        default:
            cout << "Unable to process the selection made";
    }
}

/*********************************************************************
** Description:     this function computes the feeding costs for the
**                  animals and subtracts it from the bank balance.
*********************************************************************/
void Zoo::feedAnimals() {
    double tigerCosts = 0;
    double penguinCosts = 0;
    double turtleCosts = 0;

    for (int index = 0; index < tigerQty; index++) {
        tigerCosts = animals[0]->getFoodCost() * tigerQty * baseFoodCost;
    }
    for (int index = 0; index < penguinQty; index++) {
        penguinCosts = animals[1]->getFoodCost() * penguinQty * baseFoodCost;
    }
    for (int index = 0; index < turtleQty; index++) {
        turtleCosts = animals[2]->getFoodCost() * turtleQty * baseFoodCost;
    }

    double totalFeedExpenses = tigerCosts+penguinCosts+turtleCosts;
    bankBalance -= totalFeedExpenses;
}

/*********************************************************************
** Description:     this function is in charge of generating a random
**                  event and calling the appropriate function that
**                  produces the event.
*********************************************************************/
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
    int randomAnimal = rand() % 3;

    // end function if the zoo has no animals of the kind chosen to
    // die from disease and display message with this information
    if (tigerQty < 1 && randomAnimal == 0) {
        menu.menuAnimalSpared(randomAnimal); return;
    }
    if (penguinQty < 1 && randomAnimal == 1) {
        menu.menuAnimalSpared(randomAnimal); return;
    }
    if (turtleQty < 1 && randomAnimal == 2) {
        menu.menuAnimalSpared(randomAnimal); return;
    }

    // display that animal has died
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
                    tempAnimal[index] = animals[2][index];
                }
                delete [] animals[2];
                animals[2] = tempAnimal;
            }
            break;
        default:
            cout << "Unable to randomly choose an animal to die!\n";
    }
    countAnimals();
}

/*********************************************************************
** Description:     generates a random bonus between 250 and 500 per
**                  tiger
*********************************************************************/
void Zoo::attendanceBoom() {
    double bonus = (rand() % (500 - 250 + 1)) + 250;
    if (tigerQty < 0) {
        boomBonus = 0;
        menu.menuAttendanceBoom(bonus);
    }
    bonus *= tigerQty;
    boomBonus = bonus;
    menu.menuAttendanceBoom(bonus);
}

/*********************************************************************
** Description:     this function starts the process spawning baby
**                  animals. It calls other functions to check if
**                  there are any adult animals to spawn and randomly
**                  chooses an animal to spawn from the available
**                  animals.
*********************************************************************/
void Zoo::animalBorn() {
    bool babiesAvailable;
    int animalBorn = 0;

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
            animalBorn = rand() % 3;
            if (adultAnimals[animalBorn]) {
                spawnAnimal(animalBorn);
                findAnimal = false;
            }
        } while (findAnimal);
    }
    else {
        // menu to display if no adults available for babies
        menu.menuBabyNotBorn();
    }
}

/*********************************************************************
** Description:     checks if there are any adults available to have
**                  babies. The information is saved in the array
**                  that is passed in as a bool value. Function returns
**                  true if adults are present.
*********************************************************************/
bool Zoo::adultCheck(bool *adultAnimals) {
    bool adultsPresent = false;
    int animalArr[] = {tigerQty, penguinQty, turtleQty};

    for (int type = 0; type < 3; type++) {
        for (int total = 0; total < animalArr[type]; total++) {
            if (animals[type][total].getAge() >= 3) {
                adultsPresent = adultAnimals[type] = true;
            }
        }
    }

//    for (int index = 0; index <= tigerQty; index++) {
//        if (animals[0][index].getAge() >= 3) {
//            adultsPresent = adultAnimals[0] = true;
//        }
//    }
//    for (int index = 0; index <= penguinQty; index++) {
//        if (animals[1][index].getAge() >= 3) {
//            adultsPresent = adultAnimals[1] = true;
//        }
//    }
//    for (int index = 0; index <= turtleQty; index++) {
//        if (animals[2][index].getAge() >= 3) {
//            adultsPresent = adultAnimals[2] = true;
//        }
//    }

    return adultsPresent;
}

/*********************************************************************
** Description:     this function adds a new animal for that type of
**                  animal that was chosen to spawn. Before adding a
**                  new animal, a check is made to see if the array
**                  capacity needs to be increased before adding a
**                  new animal. After animal capacity is increased
**                  (if needed), an animal is added to the animal
**                  array.
*********************************************************************/
void Zoo::spawnAnimal(int num) {
    menu.menuBabyBorn(num);
    switch(num) {
        case 0:
            {
                tigerQty++;
                // check for capacity
                if (tigerQty > tigerCap) { doubleCapacity(num+1); }
                // add animal
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
                // check for capacity
                if (penguinQty > penguinCap) { doubleCapacity(num+1); }
                // add animal
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
                // check for capacity
                if (turtleQty > turtleCap) { doubleCapacity(num+1); }
                // add animal
                Animal *tempAnimal = new Turtle[turtleQty];
                for (int index = 0; index < turtleQty - 10; index++) {
                    tempAnimal[index] = animals[2][index];
                }
                delete [] animals[2];
                animals[2] = tempAnimal;

                for (int index = 0; index < 10; index++) {
                    animals[2][turtleQty - 10 + index] = Turtle{0};
                }
            }
            break;
        default:
            cout << "Unable to create a new baby!\n";
    }
    countAnimals();
}

/*********************************************************************
** Description:     calculates daily profits by computing all revenues
**                  and expenses to obtain net income, plus any
**                  boom bonuses received. It calls a menu function
**                  from the menu class to display this information
**                  to the player.
*********************************************************************/
void Zoo::dailyFinancialReport() {
    // reset daily profits
    dailyProfit = 0;
    double tigerRevenues = 0;
    double penguinRevenues = 0;
    double turtleRevenues = 0;

    double tigerCosts = 0;
    double penguinCosts = 0;
    double turtleCosts = 0;

    // calculate revenues for all animals
    // check animal qty greater than zero
    for (int index = 0; index < tigerQty; index++) {
        tigerRevenues = animals[0]->getPayOff() * tigerQty;
    }
    for (int index = 0; index < penguinQty; index++) {
        penguinRevenues = animals[1]->getPayOff() * penguinQty;
    }
    for (int index = 0; index < turtleQty; index++) {
        turtleRevenues = animals[2]->getPayOff() * turtleQty;
    }

    // calculate feed expenses for all animals
    for (int index = 0; index < tigerQty; index++) {
        tigerCosts = animals[0]->getFoodCost() * tigerQty;
    }
    for (int index = 0; index < penguinQty; index++) {
        penguinCosts = animals[1]->getFoodCost() * penguinQty;
    }
    for (int index = 0; index < turtleQty; index++) {
        turtleCosts = animals[2]->getFoodCost() * turtleQty;
    }

    // calculate net income for the day
    double totalRevenues = tigerRevenues + penguinRevenues + turtleRevenues;
    double totalFeedExpenses = tigerCosts + penguinCosts + turtleCosts;

    // feed expenses are already subtracted by feedAnimals()
    double netIncome = totalRevenues - totalFeedExpenses;

    // add any bonus earned during the round
    dailyProfit += boomBonus;

    // set daily profit; add back expenses already subtracted by totalFeedExpenses()
    dailyProfit += netIncome + totalFeedExpenses;

    // save prior day bank balance
    double priorBankBalance = bankBalance + totalFeedExpenses;

    // add daily profit to bank balance
    bankBalance += dailyProfit;

    // store financial info in arrays to send to menu class for display
    double revenueArr[] = {tigerRevenues, penguinRevenues, turtleRevenues};
    double costsArr[] = {tigerCosts, penguinCosts, turtleCosts};
    double profitsArr[] = {boomBonus, netIncome, bankBalance, priorBankBalance};

    // pass financial information to display on menu
    menu.menuBudget(revenueArr, costsArr, profitsArr);
}

/*********************************************************************
** Description:     this function starts the process of purchasing a
**                  new animal by asking the user if they would like
**                  to buy one.
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
**                  adds the animal to the right category. A check is
**                  made to check if the animal capacity in the array
**                  needs to be increased first.
*********************************************************************/
void Zoo::addPurchasedAnimal(int selection) {
    switch (selection) {
        case 1: // add one adult tiger
            {
                tigerQty++;
                // check for capacity
                if (tigerQty > tigerCap) { doubleCapacity(selection); }
                // add animal
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
            purchaseBalanceUpdate(selection - 1);
            break;
        case 2: // add one adult penguin
            {
                penguinQty++;
                // check for capacity
                if (penguinQty > penguinCap) { doubleCapacity(selection); }
                // add animal
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
            purchaseBalanceUpdate(selection - 1);
            break;
        case 3: // add one adult turtle
            {
                turtleQty++;
                // check for capacity
                if (turtleQty > turtleCap) { doubleCapacity(selection); }
                // add animal
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
    menu.menuPurchaseReport(selection, animalCost, bankBalance);
}

/*********************************************************************
** Description:     this function is used to prompt the user if they
**                  want to keep playing or if they want to quit the
**                  game.
*********************************************************************/
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