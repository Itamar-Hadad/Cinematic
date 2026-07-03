#include "Guest.h"
#include "Ticket.h"
#include <iostream>

Guest::Guest(const char* name, int id, int visitCount)
    : Person(name, id), visitCount(visitCount),
      tickets(new Ticket*[INITIAL_TICKETS_CAPACITY]),
      numTickets(0),
      ticketsCapacity(INITIAL_TICKETS_CAPACITY) {}

Guest::~Guest() {
    for (int i = 0; i < numTickets; ++i) delete tickets[i];
    delete[] tickets;
}

void Guest::resizeTickets() {
    ticketsCapacity *= 2;
    Ticket** newArr = new Ticket*[ticketsCapacity];
    for (int i = 0; i < numTickets; ++i) newArr[i] = tickets[i];
    delete[] tickets;
    tickets = newArr;
}

int  Guest::getVisitCount() const { return visitCount; }
int  Guest::getNumTickets() const { return numTickets;  }

void Guest::setVisitCount(int v)  { visitCount = v; }
void Guest::incrementVisitCount() { ++visitCount;   }

const Ticket* Guest::getTicket(int index) const {
    if (index < 0 || index >= numTickets) return nullptr;
    return tickets[index];
}

void Guest::addTicket(Ticket* t) {
    if (numTickets == ticketsCapacity) resizeTickets();
    tickets[numTickets++] = t;
}

void Guest::printDetails() const {
    std::cout << "Guest: "      << getName()
              << " | ID: "      << getId()
              << " | Visits: "  << visitCount
              << " | Tickets: " << numTickets
              << std::endl;
}
