#include "Customer.h"
#include <iostream>

Customer::Customer(const char* name, int id, int clubPoints, int visitCount)
    : Guest(name, id, visitCount), clubPoints(clubPoints) {}

int  Customer::getClubPoints() const { return clubPoints; }
void Customer::setClubPoints(int p)  { clubPoints = p;    }
void Customer::addClubPoints(int p)  { clubPoints += p;   }

void Customer::printDetails() const {
    std::cout << "Customer: "   << getName()
              << " | ID: "      << getId()
              << " | Visits: "  << getVisitCount()
              << " | Tickets: " << getNumTickets()
              << " | Points: "  << clubPoints
              << std::endl;
}
