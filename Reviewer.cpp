#include "Reviewer.h"
#include <iostream>

Reviewer::Reviewer(const std::string& name, int id, const std::string& publicationName, int visitCount)
    : Guest(name, id, visitCount), publicationName(publicationName) {}

const std::string& Reviewer::getPublicationName() const { return publicationName; }

void Reviewer::setPublicationName(const std::string& name) { publicationName = name; }

void Reviewer::printDetails() const {
    std::cout << "Reviewer: "       << getName()
              << " | ID: "          << getId()
              << " | Visits: "      << getVisitCount()
              << " | Tickets: "     << getNumTickets()
              << " | Publication: " << publicationName
              << std::endl;
}
