#ifndef GUEST_H
#define GUEST_H

#include "Person.h"
#include <vector>

class Ticket;

class Guest : public Person {
private:
    int visitCount;
    std::vector<Ticket*> tickets;

public:
    Guest(const std::string& name, int id, int visitCount = 0);
    Guest(const Guest& other) = delete;
    Guest& operator=(const Guest& other) = delete;
    virtual ~Guest();

    int getVisitCount() const;
    int getNumTickets() const;
    const Ticket* getTicket(int index) const;

    void setVisitCount(int v);
    void incrementVisitCount();

    void addTicket(Ticket* t);

    void printDetails() const override;
};

#endif
