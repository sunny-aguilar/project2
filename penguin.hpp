/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Penguin class is derived from Animal class. Instances
**                  of Penguin are initialized with their age. Penguin
**                  inherits publicly from Animal.
*********************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "animal.hpp"                   // base class header

class Penguin : public Animal {
public:
    Penguin();
    Penguin(int age);

private:

};

#endif
