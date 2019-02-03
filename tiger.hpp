/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
** Description:     Tiger class is derived from Animal class. Instances
**                  of Tiger are initialized with their age. Tiger
**                  inherits publicly from Animal.
*********************************************************************/
#ifndef TIGER_HPP
#define TIGER_HPP

#include "animal.hpp"                   // base class header

class Tiger : public Animal {
public:
    Tiger();
    Tiger(int age);

private:
};

#endif
