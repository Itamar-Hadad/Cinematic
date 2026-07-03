#include "VIPTicket.h"

const double VIPTicket::VIP_SURCHARGE = 25.0;
const double VIPTicket::MEAL_PRICE    = 20.0;

VIPTicket::VIPTicket(const Hall& hall, int seatNumber, bool includesMeal)
    : Ticket(hall, seatNumber), includesMeal(includesMeal) {}

VIPTicket::VIPTicket(const VIPTicket& other)
    : Ticket(other), includesMeal(other.includesMeal) {}

bool VIPTicket::getIncludesMeal() const  { return includesMeal; }
void VIPTicket::setIncludesMeal(bool m)  { includesMeal = m;    }

double VIPTicket::calcFinalPrice() const {
    return Ticket::calcFinalPrice() + VIP_SURCHARGE + (includesMeal ? MEAL_PRICE : 0.0);
}
