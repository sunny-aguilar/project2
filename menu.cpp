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
    cout << "----------------------------------\n";
    cout << " (\\ _ /)       /\\__/\\       ^---^\n";
    cout << " (' x ')      (=^.^=)      ( `o`)\n";
    cout << " c(\")(\")       (\")(\")_/    ( uu )\n";
    cout << "----------------------------------\n";
    cout << "--- Welcome To Zoo Tycoon ---\n\n";
    cout << "1. Enter 1 to Play the Game\n";
    cout << "2. Enter 2 to Exit the Game\n";
    cout << ">> \n";
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