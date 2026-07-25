#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Guest.h"

class Customer : public Guest {
private:
    int clubPoints;

public:
    Customer(const std::string& name, int id, int clubPoints = 0, int visitCount = 0);
    Customer(const Customer& other) = delete;
    Customer& operator=(const Customer& other) = delete;

    int getClubPoints() const;
    void setClubPoints(int points);
    void addClubPoints(int points);

    void printDetails() const override;
};

#endif
