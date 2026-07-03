#include "VIPHall.h"
#include <iostream>

VIPHall::VIPHall(int hallNumber, const Movie& currentMovie, int waitersCount)
    : Hall(hallNumber, currentMovie), waitersCount(waitersCount) {}

int  VIPHall::getWaitersCount() const  { return waitersCount; }
void VIPHall::setWaitersCount(int c)   { waitersCount = c;    }

void VIPHall::printHall() const {
    Hall::printHall();
    std::cout << "  [VIP] Waiters on duty: " << waitersCount << std::endl;
}
