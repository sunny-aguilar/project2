/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Penguin class is derived from Animal class. Instances
**                  of Penguin are initialized with their age. Penguin
**                  inherits publicly from Animal.
*********************************************************************/
#include "penguin.hpp"

Penguin::Penguin() {}

Penguin::Penguin(int age) : Animal{age, 1000, 5,  10, 100} {}