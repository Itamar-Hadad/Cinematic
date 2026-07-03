#include "Hall3DVIP.h"
#include <iostream>

Hall3DVIP::Hall3DVIP(int hallNumber, const Movie& currentMovie,
                     int waitersCount, int glassesCount)
    : Hall(hallNumber, currentMovie),
      VIPHall(hallNumber, currentMovie, waitersCount),
      Hall3D(hallNumber, currentMovie, glassesCount) {}

Hall3DVIP::~Hall3DVIP() {}

void Hall3DVIP::printHall() const {
    Hall::printHall();
    std::cout << "  [VIP] Waiters on duty: "   << getWaitersCount() << std::endl;
    std::cout << "  [3D]  Glasses available: "  << getGlassesCount() << std::endl;
}
