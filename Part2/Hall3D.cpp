#include "Hall3D.h"
#include <iostream>

Hall3D::Hall3D(int hallNumber, const Movie& currentMovie, int glassesCount)
    : Hall(hallNumber, currentMovie), glassesCount(glassesCount) {}

Hall3D::~Hall3D() {}

int  Hall3D::getGlassesCount() const  { return glassesCount; }
void Hall3D::setGlassesCount(int c)   { glassesCount = c;    }
void Hall3D::addGlasses(int amount)   { glassesCount += amount; }
void Hall3D::useGlass()               { --glassesCount;         }

bool Hall3D::isHall3D() const { return true; }

void Hall3D::printHall() const {
    Hall::printHall();
    std::cout << "  [3D] Glasses available: " << glassesCount << std::endl;
}
