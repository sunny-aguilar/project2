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
#include "menu.hpp"

void Menu::mainMenu() {
    cout << "+-----------------------------------------------------------+\n"
         << "|     (\\ _ /)         /\\__/\\          ^---^        (O_      |\n"
         << "|     (' x ')        (=^.^=)         ( `o`)        //\\      |\n"
         << "|     c(\")(\")         (\")(\")_/       ( uu )        V_/_     |\n"
         << "+-----------------------------------------------------------+\n"
         << "|------------------- WELCOME TO ZOO TYCOON -----------------|\n"
         << "+-----------------------------------------------------------+\n\n"
         << "Game Rules:\n"
         << "- You are the owner of a zoo!\n"
         << "- Each turn counts as 1 day\n"
         << "- You start the game with $100,000 \n"
         << "- you will need to buy 3 different animals,\n"
         << "  1 or 2 of each kind\n"
         << "- buying an animal cost money\n"
         << "- animals must be fed each day at a cost\n"
         << "- animals can spawn babies\n"
         << "- animals can get sick and die\n"
         << "- if you balance goes below $0, game ends!\n\n";
}

/*********************************************************************
** Description:     sets selection member variable
*********************************************************************/
void Menu::setSelection(int sel) {
    selection = sel;
}

/*********************************************************************
** Description:     gets selection member variable
*********************************************************************/
int Menu::getSelection() {
    return selection;
}

/*********************************************************************
** Description:     mask how many initial tigers to start with
*********************************************************************/
void Menu::initialTigers() {
    cout << "+- TIGERS -------+\n"
         << "How many tigers do you want to start out with?\n"
         << "enter 1 or 2\n"
         << ">> ";
}

/*********************************************************************
** Description:     ask how many initial penguins to start with
*********************************************************************/
void Menu::initialPenguins() {
    cout << "+- Penguins -------+\n"
         << "How many penguins do you want to start out with?\n"
         << "enter 1 or 2\n"
         << ">> ";
}

/*********************************************************************
** Description:     ask how many initial penguins to start with
*********************************************************************/
void Menu::initialTurtles() {
    cout << "+- Turtles -------+\n"
         << "How many turtles do you want to start out with?\n"
         << "enter 1 or 2\n"
         << ">> ";
}

/*********************************************************************
** Description:     start up costs and remaining bank balance display
*********************************************************************/
void Menu::menuStartupCost(double bal, int cost) {
    cout << "+--------------------------------------------------+\n"
            "|                                                  |\n";
    cout << "| Start-up Costs: $ " << cost << "      Bank Bal: $ ";
    cout << bal <<"   |\n"
            "|                                                  |\n"
            "+--------------------------------------------------+\n";
//    cout << "\nHit ENTER to start the first day\n";
//    cin.get();
}

/*********************************************************************
** Description:     prompts user to select feed type
*********************************************************************/
void Menu::menuSelectFeed() {
    cout << "TIME TO FEED THE ANIMALS - SELECT FEED TYPE\n"
            "+--------------------------------------------------+\n";
    cout << " 1. Cheap   2. Generic   3. Premium\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     displays animals ages for all animals
*********************************************************************/
void Menu::menuAnimalAges(int aTiger, int bTiger, int aPenguin,
                          int bPenguin, int aTurtle, int bTurtle) {
    cout << "ANIMALS BY AGES REPORT\n"
            "+--------------------------------------------------+\n";
    cout << "    Adult Tigers:   " << std::setw(3) << aTiger << "     Baby Tigers:   "<< std::setw(3) << bTiger << endl;
    cout << "    Adult Penguins: " << std::setw(3) << aPenguin << "     Baby Penguins: "<< std::setw(3) << bPenguin << endl;
    cout << "    Adult Turtles:  " << std::setw(3) << aTurtle << "     Baby Turtles:  "<< std::setw(3) << bTurtle << endl << endl;
}

/*********************************************************************
** Description:     displays daily revenues, expenses, daily net income
**                  or loss, and bank balance
*********************************************************************/
void Menu::menuBudget(double *salesArr, double *costsArr, double *profitsArr) {
    cout << std::fixed << std::setprecision(0);
    cout << "\n DAILY REVENUES\n"
            "+--------------------------------------------------+\n";
    cout << "    $" << std::setw(7) << salesArr[0] << " - Tiger Revenues\n";
    cout << "    $" << std::setw(7) << salesArr[1] << " - Penguin Revenues\n";
    cout << "    $" << std::setw(7) << salesArr[2] << " - Turtle Revenues\n";
    cout << "    $" << std::setw(7) << salesArr[0] + salesArr[1] + salesArr[2];
    cout << " - Total Revenues\n\n";

    cout << " DAILY EXPENSES\n"
            "+--------------------------------------------------+\n";
    cout << "    $" << std::setw(7) << costsArr[0] << " - Tiger Feeding Costs\n";
    cout << "    $" << std::setw(7) << costsArr[1] << " - Penguin Feeding Costs\n";
    cout << "    $" << std::setw(7) << costsArr[2] << " - Turtle Feeding Costs\n";
    cout << "    $" << std::setw(7) << costsArr[0] + costsArr[1] + costsArr[2];
    cout << " - Total Expenses\n\n";

    cout << " DAILY NET INCOME & BANK BALANCE\n"
            "+--------------------------------------------------+\n";
    cout << "    $" << std::setw(7) << profitsArr[3] << " - Prior Bank Balance\n";
    cout << "    $" << std::setw(7) << profitsArr[0] << " - Boom Bonus\n";
    cout << "    $" << std::setw(7) << profitsArr[1] << " - Net Income / (Loss)\n";
    cout << "    $" << std::setw(7) << profitsArr[2] << " - Bank Balance\n\n";
}

/*********************************************************************
** Description:     display the start of a new day
*********************************************************************/
void Menu::starDayMessage(int day) {
    cout << "+--------------------------------------------------+\n"
            "|                                                  |\n"
            "|                IT'S A NEW DAY                    |\n";
    cout << "|                    DAY " << std::setw(3) << day << "                       |\n";
    cout << "|                                                  |\n"
            "+--------------------------------------------------+\n\n";
}

/*********************************************************************
** Description:     display banner when animal gets a disease
*********************************************************************/
void Menu::animalSick() {
    cout << "\n RANDOM EVENT - AN ANIMAL DISEASE IS GOING AROUND\n"
            "+--------------------------------------------------+\n";
}

/*********************************************************************
** Description:     display banner when spared from disease
*********************************************************************/
void Menu::menuAnimalSpared(int sel) {
    std::string animal[3] {"tigers", "penguins", "turtles"};
    cout << "    There is disease going around affecting " << animal[sel];
    cout << "\n    and luckily for you, you don't own any!\n";
}

/*********************************************************************
** Description:     display which animal has ied
*********************************************************************/
void Menu::menuAnimalDead(int sel) {
    std::string animal[3] {"tiger", "penguin", "turtle"};
    cout << "    Unfortunately your " << animal[sel] << " has died :(\n\n";
}

/*********************************************************************
** Description:     display the type of animal has been born
*********************************************************************/
void Menu::menuBabyBorn(int sel) {
    std::string animalType;
    switch (sel) {
        case 0:
            animalType = "tigers";
            break;
        case 1:
            animalType = "penguins";
            break;
        case 2:
            animalType = "turtles";
            break;
        default:
            cout << "Unable to determine the type of animal born!\n";
    }
    cout << "\n RANDOM EVENT - AN ANIMAL IS BORN\n"
            "+--------------------------------------------------+\n";
    cout << "    Congrats! Your " << animalType << " had babies!\n\n";
}

/*********************************************************************
** Description:     display no animals born banner
*********************************************************************/
void Menu::menuBabyNotBorn() {
    cout << "\n RANDOM EVENT - NO ANIMALS BORN\n"
            "+--------------------------------------------------+\n";
    cout << "    Spring has come however there are no adult\n"
         << "    animals to have babies\n\n";
}

/*********************************************************************
** Description:     display bonus banner
*********************************************************************/
void Menu::menuAttendanceBoom(double bonus) {
    cout << " BOOM BONUS!\n"
            "+--------------------------------------------------+\n";
    cout << "    Your recent advertisements have caused an attendance \n"
         << "    boom! Each tiger you own will generate extra revenue.\n"
         << "    You have generated an extra $" << bonus << endl;
}

/*********************************************************************
** Description:     display no random event banner
*********************************************************************/
void Menu::menuNoRandomEvent() {
    cout << " DAILY RANDOM EVENT\n"
            "+--------------------------------------------------+\n";
    cout << "    No random event happened today\n";
}

/*********************************************************************
** Description:     prompt user to purchase an adult animal
*********************************************************************/
void Menu::menuBuyNewAnimal() {
    cout << "Before the day is over, would you like to buy an adult animal?\n"
         << "1. Yes\n"
         << "2. No\n"
         << ">> ";
}

/*********************************************************************
** Description:     prompt user for animal type to purchase
*********************************************************************/
void Menu::menuBuyAnimalSelectionMade(int select) {
    switch (select) {
        case 1:
            cout << "Great, what kind of animal do you want?\n"
                 << "1. Adult tiger\n"
                 << "2. Adult penguin\n"
                 << "3. Adult turtle\n"
                 << ">> ";
            break;
        case 2:
            cout << "Ok, no animals have been purchased\n\n";
            break;
        default:
            cout << "Unable to determine selection made!\n";
    }
}

/*********************************************************************
** Description:     display animal purchase report
*********************************************************************/
void Menu::menuPurchaseReport(int select, double cost, double bal) {
    std::string animalType;
    switch (select) {
        case 0:
            animalType = "tiger";
            break;
        case 1:
            animalType = "penguin";
            break;
        case 2:
            animalType = "turtle";
            break;
        default:
            "Unable to determine animal!\n";
    }
    cout << " ANIMAL PURCHASE INFO\n"
            "+--------------------------------------------------+\n";
    cout << "Your new " << animalType << " is 3 days old.\n";
    cout << "$" << cost << " - Cost of purchased " << animalType << endl;
    cout << "$" << bal << " - Bank balance" << endl << endl;
}

/*********************************************************************
** Description:     this menu display information about the increase
**                  in size of the animal arrays. Animal arrays are
**                  increase by 10 each time.
*********************************************************************/
void Menu::menuCapacityIncrease(int sel, int animalQty, int cap) {
    std::string type[] = {"tigers", "penguins", "turtles"};

    cout << "+------------------------------------------------+\n"
            "|                                                |\n"
            "|  Your zoo keeps growing! You can now keep a    |\n"
            "|  a total of "<< std::setw(3) << cap << " " << type[sel-1] << "                        |\n"
            "|                                                |\n"
            "+------------------------------------------------+\n\n";
}

/*********************************************************************
** Description:     prompt user if they would like to keep playing
*********************************************************************/
void Menu::menuKeepPlaying() {
    cout << "The day is now over, would you like to continue playing?\n"
         << "1. Yes, keep playing\n"
         << "2. No, stop playing\n"
         << ">> ";
}

/*********************************************************************
** Description:     display bankruptcy banner
*********************************************************************/
void Menu::menuBankrupt(double balance) {
    cout << "YOU HAVE GONE BANKRUPT!\n"
         << "YOUR ACCOUNT BALANCE IS $" << balance << endl
         << "It was a good run while it lasted\n";
}

/*********************************************************************
** Description:     display thank you message for quitting game
*********************************************************************/
void Menu::quitGameMssg(double bal) {
    cout << "+------------------------------------------------+\n"
            "|                                                |\n"
            "|          Thanks for playing Zoo Tycoon!        |\n"
            "|          Lifetime Earnings: $" << std::setw(7) << bal << "           |\n"
            "|                                                |\n"
            "+------------------------------------------------+\n\n";

    cout << "                          (o<\n"
            "      _o)  (o_  (o<  (o<  //\\\n"
            "      (/)_ (/)_ (/)_ (/)_ V_/_\n\n";
}


/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Menu::validateNumber(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();

    do {
        // store user input
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (unsigned i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
        }

        // check if characters entered are within range
        notInRange = false;
        if (!isNotDigit && !tooLong) {
            convert.clear();
            convert << choice;
            convert >> validatedChoice;

            if (validatedChoice < min || validatedChoice > max) {
                notInRange = true;
                cout << "enter a number between "
                     << min << " or " << max << endl;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return validatedChoice;
}