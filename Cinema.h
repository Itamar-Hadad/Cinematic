#ifndef CINEMA_H
#define CINEMA_H

#include <vector>
#include "Employee.h"
#include "Guest.h"
#include "Hall.h"
#include "Movie.h"
#include "Shift.h"
#include "LinkedList.h"

class Cinema {
private:
    std::vector<Employee*> employees;
    std::vector<Guest*>    guests;
    std::vector<Hall*>     halls;
    std::vector<Movie*>    movies;
    LinkedList<Shift*>     shifts;

    Cinema() = default;

public:
    static Cinema& getInstance();

    Cinema(const Cinema& other) = delete;
    Cinema& operator=(const Cinema& other) = delete;
    ~Cinema();

    int getNumEmployees() const;
    int getNumGuests()    const;
    int getNumHalls()     const;
    int getNumMovies()    const;
    int getNumShifts()    const;

    const Employee* getEmployeeByIndex(int i) const;
    Employee*       getEmployeeByIndex(int i);
    const Guest*    getGuestByIndex(int i)    const;
    Guest*          getGuestByIndex(int i);
    const Hall*     getHallByIndex(int i)     const;
    Hall*           getHallByIndex(int i);
    const Movie*    getMovieByIndex(int i)    const;
    Movie*          getMovieByIndex(int i);
    const Shift*    getShiftByIndex(int i)    const;

    Guest*    findGuestById(int id);
    Employee* findEmployeeById(int id);

    Cinema& operator+=(Employee* e);
    Cinema& operator+=(Guest* g);
    Cinema& operator+=(Hall* h);
    Cinema& operator+=(Movie* m);
    Cinema& operator+=(Shift* s);

    Cinema& operator-=(int guestId);

    void printAllGuests()    const;
    void printAllEmployees() const;
    void printAllHalls()     const;
    void printAllMovies()    const;
    void printAllShifts()    const;
};

#endif
