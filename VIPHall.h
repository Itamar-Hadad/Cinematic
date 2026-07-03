#ifndef VIPHALL_H
#define VIPHALL_H

#include "Hall.h"

class VIPHall : virtual public Hall {
private:
    int waitersCount;

public:
    VIPHall(int hallNumber, const Movie& currentMovie, int waitersCount);
    VIPHall(const VIPHall& other) = delete;
    VIPHall& operator=(const VIPHall& other) = delete;
    ~VIPHall() override = default;

    int getWaitersCount() const;
    void setWaitersCount(int c);

    void printHall() const override;
};

#endif
