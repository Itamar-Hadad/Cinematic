#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name, int id, int clubPoints, int visitCount)
    : Guest(name, id, visitCount), clubPoints(clubPoints) {}

int Customer::getClubPoints() const
{
    return clubPoints;
}

void Customer::setClubPoints(int points)
{
    clubPoints = points;
}

void Customer::addClubPoints(int points)
{
    clubPoints += points;
}

void Customer::printDetails() const {
    std::cout << "Customer: "    << getName()
              << " | ID: "       << getId()
              << " | Visits: "   << getVisitCount()
              << " | Tickets: "  << getNumTickets()
              << " | Points: "   << clubPoints
              << std::endl;
}
