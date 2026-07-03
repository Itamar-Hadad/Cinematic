#ifndef TICKET_H
#define TICKET_H

#include "Hall.h"

class Ticket {
private:
    const Hall& hallRef;
    int         seatNumber;

    static const double BASE_PRICE;
    static const double THREE_D_SURCHARGE;

public:
    Ticket(const Hall& hall, int seatNumber);
    Ticket(const Ticket& other);
    Ticket& operator=(const Ticket& other) = delete;
    virtual ~Ticket() = default;

    const Movie& getMovie()      const;
    const Hall&  getHall()       const;
    int          getHallNumber() const;
    int          getSeatNumber() const;

    bool isSeatFree() const;

    virtual double calcFinalPrice() const;

    bool operator>(const Ticket& other) const;
};

#endif
