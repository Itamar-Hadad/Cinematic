#include "Cinema.h"
#include <iostream>
#include <stdexcept>

// ── Singleton ─────────────────────────────────────────────────────────────────

Cinema& Cinema::getInstance() {
    static Cinema instance;
    return instance;
}

// ── Destructor ────────────────────────────────────────────────────────────────

Cinema::~Cinema() {
    std::vector<Employee*>::iterator eItr = employees.begin();
    for ( ; eItr != employees.end() ; ++eItr ) delete *eItr;

    std::vector<Guest*>::iterator gItr = guests.begin();
    for ( ; gItr != guests.end() ; ++gItr ) delete *gItr;

    std::vector<Hall*>::iterator hItr = halls.begin();
    for ( ; hItr != halls.end() ; ++hItr ) delete *hItr;

    std::vector<Movie*>::iterator mItr = movies.begin();
    for ( ; mItr != movies.end() ; ++mItr ) delete *mItr;

    for (auto* node = shifts.getHead(); node; node = node->next) delete node->data;
}

// ── Count getters ─────────────────────────────────────────────────────────────

int Cinema::getNumEmployees() const { return static_cast<int>(employees.size()); }
int Cinema::getNumGuests()    const { return static_cast<int>(guests.size());    }
int Cinema::getNumHalls()     const { return static_cast<int>(halls.size());     }
int Cinema::getNumMovies()    const { return static_cast<int>(movies.size());    }
int Cinema::getNumShifts()    const { return shifts.getSize();                   }

// ── Index getters ─────────────────────────────────────────────────────────────

const Employee* Cinema::getEmployeeByIndex(int i) const {
    return (i >= 0 && i < (int)employees.size()) ? employees[i] : nullptr;
}
Employee* Cinema::getEmployeeByIndex(int i) {
    return (i >= 0 && i < (int)employees.size()) ? employees[i] : nullptr;
}

const Guest* Cinema::getGuestByIndex(int i) const {
    return (i >= 0 && i < (int)guests.size()) ? guests[i] : nullptr;
}
Guest* Cinema::getGuestByIndex(int i) {
    return (i >= 0 && i < (int)guests.size()) ? guests[i] : nullptr;
}

const Hall* Cinema::getHallByIndex(int i) const {
    return (i >= 0 && i < (int)halls.size()) ? halls[i] : nullptr;
}
Hall* Cinema::getHallByIndex(int i) {
    return (i >= 0 && i < (int)halls.size()) ? halls[i] : nullptr;
}

const Movie* Cinema::getMovieByIndex(int i) const {
    return (i >= 0 && i < (int)movies.size()) ? movies[i] : nullptr;
}
Movie* Cinema::getMovieByIndex(int i) {
    return (i >= 0 && i < (int)movies.size()) ? movies[i] : nullptr;
}

const Shift* Cinema::getShiftByIndex(int i) const {
    if (i < 0 || i >= shifts.getSize()) return nullptr;
    auto* node = shifts.getHead();
    for (int j = 0; j < i; ++j) node = node->next;
    return node->data;
}

// ── Search ────────────────────────────────────────────────────────────────────

Guest* Cinema::findGuestById(int id) {
    std::vector<Guest*>::iterator itr    = guests.begin();
    std::vector<Guest*>::iterator itrEnd = guests.end();
    for ( ; itr != itrEnd ; ++itr )
        if ((*itr)->getId() == id) return *itr;
    return nullptr;
}

Employee* Cinema::findEmployeeById(int id) {
    std::vector<Employee*>::iterator itr    = employees.begin();
    std::vector<Employee*>::iterator itrEnd = employees.end();
    for ( ; itr != itrEnd ; ++itr )
        if ((*itr)->getId() == id) return *itr;
    return nullptr;
}

// ── operator+= (add) ─────────────────────────────────────────────────────────

Cinema& Cinema::operator+=(Employee* e) { employees.push_back(e); return *this; }
Cinema& Cinema::operator+=(Guest* g)    { guests.push_back(g);    return *this; }
Cinema& Cinema::operator+=(Hall* h)     { halls.push_back(h);     return *this; }
Cinema& Cinema::operator+=(Movie* m)    { movies.push_back(m);    return *this; }
Cinema& Cinema::operator+=(Shift* s)    { shifts.insert(s);       return *this; }

// ── operator-= (remove guest) ─────────────────────────────────────────────────

Cinema& Cinema::operator-=(int guestId) {
    std::vector<Guest*>::iterator itr    = guests.begin();
    std::vector<Guest*>::iterator itrEnd = guests.end();
    for ( ; itr != itrEnd ; ++itr ) {
        if ((*itr)->getId() == guestId) {
            delete *itr;
            guests.erase(itr);
            return *this;
        }
    }
    throw std::invalid_argument("Guest ID not found");
}

// ── Print methods ─────────────────────────────────────────────────────────────

void Cinema::printAllGuests() const {
    std::vector<Guest*>::const_iterator itr    = guests.begin();
    std::vector<Guest*>::const_iterator itrEnd = guests.end();
    int i = 1;
    for ( ; itr != itrEnd ; ++itr ) {
        std::cout << "[" << i++ << "] ";
        (*itr)->printDetails();
    }
}

void Cinema::printAllEmployees() const {
    std::vector<Employee*>::const_iterator itr    = employees.begin();
    std::vector<Employee*>::const_iterator itrEnd = employees.end();
    int i = 1;
    for ( ; itr != itrEnd ; ++itr ) {
        std::cout << "[" << i++ << "] ";
        (*itr)->printDetails();
    }
}

void Cinema::printAllHalls() const {
    std::vector<Hall*>::const_iterator itr    = halls.begin();
    std::vector<Hall*>::const_iterator itrEnd = halls.end();
    int i = 1;
    for ( ; itr != itrEnd ; ++itr ) {
        std::cout << "[" << i++ << "] ";
        (*itr)->printHall();
    }
}

void Cinema::printAllMovies() const {
    std::vector<Movie*>::const_iterator itr    = movies.begin();
    std::vector<Movie*>::const_iterator itrEnd = movies.end();
    int i = 1;
    for ( ; itr != itrEnd ; ++itr )
        std::cout << "[" << i++ << "] " << **itr << std::endl;
}

void Cinema::printAllShifts() const {
    int i = 1;
    for (auto* node = shifts.getHead(); node; node = node->next) {
        std::cout << "[" << i++ << "] ";
        node->data->printShift();
    }
}
