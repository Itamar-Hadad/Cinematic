#include "Hall.h"
#include <iostream>

Hall::Hall(int hallNumber, const Movie& currentMovie)
    : hallNumber(hallNumber), seats(), currentMovie(currentMovie) {}

Hall::~Hall() {}

int          Hall::getHallNumber()   const { return hallNumber;    }
const Movie& Hall::getCurrentMovie() const { return currentMovie;  }

bool Hall::isSeatTaken(int seatIndex) const {
    return seats[seatIndex];
}

int Hall::countTakenSeats() const {
    int count = 0;
    for (int i = 0; i < NUM_SEATS; ++i)
        if (seats[i]) ++count;
    return count;
}

void Hall::setHallNumber(int num) { hallNumber = num; }

void Hall::takeSeat(int seatIndex) { seats[seatIndex] = true;  }
void Hall::freeSeat(int seatIndex) { seats[seatIndex] = false; }

bool Hall::operator!() const {
    for (int i = 0; i < NUM_SEATS; ++i)
        if (seats[i]) return false;
    return true;
}

bool Hall::isHall3D()          const { return false; }
int  Hall::getGlassesCount()   const { return 0;     }
void Hall::useGlass()                {               }
void Hall::addGlasses(int /*amount*/)  {               }

void Hall::printHall() const {
    std::cout << "Hall #"    << hallNumber
              << " | Movie: "<< currentMovie.getTitle()
              << " | Seats taken: " << countTakenSeats()
              << "/" << NUM_SEATS
              << std::endl;
}
