#include "Reviewer.h"
#include <cstring>
#include <iostream>

Reviewer::Reviewer(const char* name, int id, const char* publicationName, int visitCount)
    : Guest(name, id, visitCount) {
    this->publicationName = new char[strlen(publicationName) + 1];
    strcpy(this->publicationName, publicationName);
}

Reviewer::~Reviewer() {
    delete[] publicationName;
}

const char* Reviewer::getPublicationName() const { return publicationName; }

void Reviewer::setPublicationName(const char* name) {
    delete[] publicationName;
    publicationName = new char[strlen(name) + 1];
    strcpy(publicationName, name);
}

void Reviewer::printDetails() const {
    std::cout << "Reviewer: "       << getName()
              << " | ID: "          << getId()
              << " | Visits: "      << getVisitCount()
              << " | Tickets: "     << getNumTickets()
              << " | Publication: " << publicationName
              << std::endl;
}
