#ifndef CINEMA_H
#define CINEMA_H

#include <vector>
#include <memory>
#include "Employee.h"
#include "Guest.h"
#include "Hall.h"
#include "Movie.h"
#include "Shift.h"
#include "LinkedList.h"

class Cinema {
private:
    std::vector<Employee*>               employees;
    std::vector<Guest*>                  guests;
    std::vector<Hall*>                   halls;
    std::vector<std::unique_ptr<Movie>>  movies;
    LinkedList<Shift*>                   shifts;

    Cinema() = default;

public:
    static Cinema& getInstance();

    Cinema(const Cinema& other) = delete;
    Cinema& operator=(const Cinema& other) = delete;
    Cinema(Cinema&& other) = delete;
    Cinema& operator=(Cinema&& other) = delete;
    ~Cinema();

    int getNumEmployees() const;
    int getNumGuests()    const;
    int getNumHalls()     const;
    int getNumMovies()    const;
    int getNumShifts()    const;

    const Employee* getEmployeeByIndex(int index) const;
    Employee*       getEmployeeByIndex(int index);
    const Guest*    getGuestByIndex(int index)    const;
    Guest*          getGuestByIndex(int index);
    const Hall*     getHallByIndex(int index)     const;
    Hall*           getHallByIndex(int index);
    const Movie*    getMovieByIndex(int index)    const;
    Movie*          getMovieByIndex(int index);
    const Shift*    getShiftByIndex(int index)    const;

    Guest*    findGuestById(int id);
    Employee* findEmployeeById(int id);

    Cinema& operator+=(Employee* employee);
    Cinema& operator+=(Guest* guest);
    Cinema& operator+=(Hall* hall);
    Cinema& operator+=(Movie* movie);
    Cinema& operator+=(Shift* shift);

    Cinema& operator-=(int guestId);

    void printAllGuests()    const;
    void printAllEmployees() const;
    void printAllHalls()     const;
    void printAllMovies()    const;
    void printAllShifts()    const;
};

#endif
