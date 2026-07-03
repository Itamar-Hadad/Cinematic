#ifndef HALL_H
#define HALL_H

#include "Movie.h"

class Hall {
public:
    static const int NUM_SEATS = 100;

private:
    int hallNumber;
    bool seats[NUM_SEATS];
    const Movie& currentMovie;

public:
    Hall(int hallNumber, const Movie& currentMovie);
    Hall(const Hall& other) = delete;
    Hall& operator=(const Hall& other) = delete;
    virtual ~Hall();

    int getHallNumber() const;
    const Movie& getCurrentMovie() const;
    bool isSeatTaken(int seatIndex) const;
    int countTakenSeats() const;

    void setHallNumber(int num);

    void takeSeat(int seatIndex);
    void freeSeat(int seatIndex);

    bool operator!() const;

    virtual bool isHall3D()          const;
    virtual int  getGlassesCount()   const;
    virtual void useGlass();
    virtual void addGlasses(int amount);
    virtual void printHall() const;
};

#endif
