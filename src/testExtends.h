#include <iostream>
#include <string>
#include "animal.h"

#ifndef TESTEXTENDS_H
#define TESTEXTENDS_H

class AnimalOfLand : virtual public Animal{

};

class AnimalOfWater: virtual public Animal{

};

class AnimalOfLiangqi : public AnimalOfLand, public AnimalOfWater{

};

#endif
