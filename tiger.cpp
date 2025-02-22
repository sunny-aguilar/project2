/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
** Description:     Tiger class is derived from Animal class. Instances
**                  of Tiger are initialized with their age. Tiger
**                  inherits publicly from Animal.
*********************************************************************/
#include "tiger.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
Tiger::Tiger() {}

/*********************************************************************
** Description:     default constructor that initializes variables
**                  in the base class
*********************************************************************/
Tiger::Tiger(int age) : Animal{age, 10000, 1, 100*5, 2000} {}