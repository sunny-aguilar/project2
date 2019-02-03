/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
** Description:     Turtle class is derived from Animal class. Instances
**                  of Turtle are initialized with their age. Turtle
**                  inherits publicly from Animal.
*********************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "animal.hpp"                   // base class header

class Turtle : public Animal {
public:
    Turtle();
    Turtle(int age);

private:
};

#endif
