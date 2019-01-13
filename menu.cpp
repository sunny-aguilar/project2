/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo Tycoon -
**
**
**
**
*********************************************************************/
#include "menu.hpp"

void Menu::mainMenu() {
    cout << "-----------------------------------------\n"
         << "   (\\ _ /)       /\\__/\\        ^---^\n"
         << "   (' x ')      (=^.^=)       ( `o`)\n"
         << "   c(\")(\")       (\")(\")_/     ( uu )\n"
         << "-----------------------------------------\n"
         << "--------- Welcome to Zoo Tycoon ---------\n\n"
         << "Game Rules:\n"
         << "- You are the owner of a zoo!\n"
         << "- Each turn counts as 1 day\n"
         << "- You start the game with $100,000 \n"
         << "- you will need to buy 3 different animals,\n"
         << "  1 or 2 of each kind\n"
         << "- buying an animal cost money\n"
         << "- animals must be fed each day at a cost\n"
         << "- animals can spawn babies\n"
         << "- animals can die\n"
         << "- if you balance goes below $0, game ends!\n"
         << "  GET READY, BEGIN!\n\n";
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
    cout << "-+TIGERS+-\n"
         << "How many tigers do you want to start out with?\n"
         << "enter 1 or 2\n"
         << ">> ";
}

/*********************************************************************
** Description:     ask how many initial penguins to start with
*********************************************************************/
void Menu::initialPenguins() {
    cout << "-+Penguins+-\n"
         << "How many penguins do you want to start out with?\n"
         << "enter 1 or 2\n"
         << ">> ";
}

/*********************************************************************
** Description:     ask how many initial penguins to start with
*********************************************************************/
void Menu::initialTurtles() {
    cout << "-+Penguins+-\n"
         << "How many turtles do you want to start out with?\n"
         << "enter 1 or 2\n"
         << ">> ";
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
        for (int i = 0; i < strlen(choice); i++) {
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