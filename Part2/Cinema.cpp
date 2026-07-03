#include "Cinema.h"
#include <iostream>
#include <stdexcept>

// ── Constructor / Destructor ──────────────────────────────────────────────────

Cinema::Cinema()
    : employees(new Employee*[INITIAL_CAPACITY]), numEmployees(0),
      employeesCapacity(INITIAL_CAPACITY),
      guests(new Guest*[INITIAL_CAPACITY]),    numGuests(0),
      guestsCapacity(INITIAL_CAPACITY),
      halls(new Hall*[INITIAL_CAPACITY]),      numHalls(0),
      hallsCapacity(INITIAL_CAPACITY),
      movies(new Movie*[INITIAL_CAPACITY]),    numMovies(0),
      moviesCapacity(INITIAL_CAPACITY),
      shifts(new Shift*[INITIAL_CAPACITY]),    numShifts(0),
      shiftsCapacity(INITIAL_CAPACITY) {}

Cinema::~Cinema() {
    for (int i = 0; i < numEmployees; ++i) delete employees[i];
    delete[] employees;

    for (int i = 0; i < numGuests; ++i) delete guests[i];
    delete[] guests;

    for (int i = 0; i < numHalls; ++i) delete halls[i];
    delete[] halls;

    for (int i = 0; i < numMovies; ++i) delete movies[i];
    delete[] movies;

    for (int i = 0; i < numShifts; ++i) delete shifts[i];
    delete[] shifts;
}

// ── Private resize helpers ────────────────────────────────────────────────────

void Cinema::resizeEmployees() {
    int newCap = employeesCapacity * 2;
    Employee** arr = new Employee*[newCap];
    for (int i = 0; i < numEmployees; ++i) arr[i] = employees[i];
    delete[] employees;
    employees = arr;
    employeesCapacity = newCap;
}

void Cinema::resizeGuests() {
    int newCap = guestsCapacity * 2;
    Guest** arr = new Guest*[newCap];
    for (int i = 0; i < numGuests; ++i) arr[i] = guests[i];
    delete[] guests;
    guests = arr;
    guestsCapacity = newCap;
}

void Cinema::resizeHalls() {
    int newCap = hallsCapacity * 2;
    Hall** arr = new Hall*[newCap];
    for (int i = 0; i < numHalls; ++i) arr[i] = halls[i];
    delete[] halls;
    halls = arr;
    hallsCapacity = newCap;
}

void Cinema::resizeMovies() {
    int newCap = moviesCapacity * 2;
    Movie** arr = new Movie*[newCap];
    for (int i = 0; i < numMovies; ++i) arr[i] = movies[i];
    delete[] movies;
    movies = arr;
    moviesCapacity = newCap;
}

void Cinema::resizeShifts() {
    int newCap = shiftsCapacity * 2;
    Shift** arr = new Shift*[newCap];
    for (int i = 0; i < numShifts; ++i) arr[i] = shifts[i];
    delete[] shifts;
    shifts = arr;
    shiftsCapacity = newCap;
}

// ── Count getters ─────────────────────────────────────────────────────────────

int Cinema::getNumEmployees() const { return numEmployees; }
int Cinema::getNumGuests()    const { return numGuests;    }
int Cinema::getNumHalls()     const { return numHalls;     }
int Cinema::getNumMovies()    const { return numMovies;    }
int Cinema::getNumShifts()    const { return numShifts;    }

// ── Index getters ─────────────────────────────────────────────────────────────

const Employee* Cinema::getEmployeeByIndex(int i) const {
    return (i >= 0 && i < numEmployees) ? employees[i] : nullptr;
}
Employee* Cinema::getEmployeeByIndex(int i) {
    return (i >= 0 && i < numEmployees) ? employees[i] : nullptr;
}

const Guest* Cinema::getGuestByIndex(int i) const {
    return (i >= 0 && i < numGuests) ? guests[i] : nullptr;
}
Guest* Cinema::getGuestByIndex(int i) {
    return (i >= 0 && i < numGuests) ? guests[i] : nullptr;
}

const Hall* Cinema::getHallByIndex(int i) const {
    return (i >= 0 && i < numHalls) ? halls[i] : nullptr;
}
Hall* Cinema::getHallByIndex(int i) {
    return (i >= 0 && i < numHalls) ? halls[i] : nullptr;
}

const Movie* Cinema::getMovieByIndex(int i) const {
    return (i >= 0 && i < numMovies) ? movies[i] : nullptr;
}
Movie* Cinema::getMovieByIndex(int i) {
    return (i >= 0 && i < numMovies) ? movies[i] : nullptr;
}

const Shift* Cinema::getShiftByIndex(int i) const {
    return (i >= 0 && i < numShifts) ? shifts[i] : nullptr;
}

// ── Search ────────────────────────────────────────────────────────────────────

Guest* Cinema::findGuestById(int id) {
    for (int i = 0; i < numGuests; ++i)
        if (guests[i]->getId() == id) return guests[i];
    return nullptr;
}

Employee* Cinema::findEmployeeById(int id) {
    for (int i = 0; i < numEmployees; ++i)
        if (employees[i]->getId() == id) return employees[i];
    return nullptr;
}

// ── operator+= (add) ─────────────────────────────────────────────────────────

Cinema& Cinema::operator+=(Employee* e) {
    if (numEmployees == employeesCapacity) resizeEmployees();
    employees[numEmployees++] = e;
    return *this;
}

Cinema& Cinema::operator+=(Guest* g) {
    if (numGuests == guestsCapacity) resizeGuests();
    guests[numGuests++] = g;
    return *this;
}

Cinema& Cinema::operator+=(Hall* h) {
    if (numHalls == hallsCapacity) resizeHalls();
    halls[numHalls++] = h;
    return *this;
}

Cinema& Cinema::operator+=(Movie* m) {
    if (numMovies == moviesCapacity) resizeMovies();
    movies[numMovies++] = m;
    return *this;
}

Cinema& Cinema::operator+=(Shift* s) {
    if (numShifts == shiftsCapacity) resizeShifts();
    shifts[numShifts++] = s;
    return *this;
}

// ── operator-= (remove guest) ─────────────────────────────────────────────────

Cinema& Cinema::operator-=(int guestId) {
    for (int i = 0; i < numGuests; ++i) {
        if (guests[i]->getId() == guestId) {
            delete guests[i];
            for (int j = i; j < numGuests - 1; ++j)
                guests[j] = guests[j + 1];
            --numGuests;
            return *this;
        }
    }
    throw std::invalid_argument("Guest ID not found");
}

// ── Print methods ─────────────────────────────────────────────────────────────

void Cinema::printAllGuests() const {
    for (int i = 0; i < numGuests; ++i) {
        std::cout << "[" << (i + 1) << "] ";
        guests[i]->printDetails();
    }
}

void Cinema::printAllEmployees() const {
    for (int i = 0; i < numEmployees; ++i) {
        std::cout << "[" << (i + 1) << "] ";
        employees[i]->printDetails();
    }
}

void Cinema::printAllHalls() const {
    for (int i = 0; i < numHalls; ++i) {
        std::cout << "[" << (i + 1) << "] ";
        halls[i]->printHall();
    }
}

void Cinema::printAllMovies() const {
    for (int i = 0; i < numMovies; ++i)
        std::cout << "[" << (i + 1) << "] " << *movies[i] << std::endl;
}

void Cinema::printAllShifts() const {
    for (int i = 0; i < numShifts; ++i) {
        std::cout << "[" << (i + 1) << "] ";
        shifts[i]->printShift();
    }
}
