#include "Guest.h"
#include "Ticket.h"
#include <iostream>

Guest::Guest(const std::string& name, int id, int visitCount)
    : Person(name, id), visitCount(visitCount) {}

Guest::~Guest() {
    std::vector<Ticket*>::iterator itr    = tickets.begin();
    std::vector<Ticket*>::iterator itrEnd = tickets.end();
    for ( ; itr != itrEnd ; ++itr ) delete *itr;
}

int Guest::getVisitCount() const
{
    return visitCount;
}

int Guest::getNumTickets() const
{
    return static_cast<int>(tickets.size());
}

void Guest::setVisitCount(int newVisitCount)
{
    visitCount = newVisitCount;
}

void Guest::incrementVisitCount()
{
    ++visitCount;
}

const Ticket* Guest::getTicket(int index) const {
    if (index < 0 || index >= (int)tickets.size()) return nullptr;
    return tickets[index];
}

void Guest::addTicket(Ticket* ticket) {
    tickets.push_back(ticket);
}

void Guest::printDetails() const {
    std::cout << "Guest: "      << getName()
              << " | ID: "      << getId()
              << " | Visits: "  << visitCount
              << " | Tickets: " << tickets.size()
              << std::endl;
}
