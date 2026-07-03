#include "Ticket.h"
#include <stdexcept>

const double Ticket::BASE_PRICE        = 40.0;
const double Ticket::THREE_D_SURCHARGE = 15.0;

Ticket::Ticket(const Hall& hall, int seatNumber)
    : hallRef(hall), seatNumber(seatNumber) {
    if (seatNumber < 1 || seatNumber > Hall::NUM_SEATS)
        throw std::invalid_argument("Seat number out of range");
    if (hall.isSeatTaken(seatNumber - 1))
        throw std::invalid_argument("Seat is already taken");
}

Ticket::Ticket(const Ticket& other)
    : hallRef(other.hallRef), seatNumber(other.seatNumber) {}

Ticket::~Ticket() {}

const Movie& Ticket::getMovie()      const { return hallRef.getCurrentMovie(); }
const Hall&  Ticket::getHall()       const { return hallRef;                   }
int          Ticket::getHallNumber() const { return hallRef.getHallNumber();   }
int          Ticket::getSeatNumber() const { return seatNumber;                }

bool Ticket::isSeatFree() const {
    return !hallRef.isSeatTaken(seatNumber - 1);
}

double Ticket::calcFinalPrice() const {
    return BASE_PRICE + (hallRef.isHall3D() ? THREE_D_SURCHARGE : 0.0);
}

bool Ticket::operator>(const Ticket& other) const {
    return calcFinalPrice() > other.calcFinalPrice();
}
