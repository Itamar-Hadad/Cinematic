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

    // movies is a vector<unique_ptr<Movie>> — each Movie is freed automatically
    // when its unique_ptr is destroyed along with the vector, no manual delete needed.

    for (auto* node = shifts.getHead(); node; node = node->next) delete node->data;
}

// ── Count getters ─────────────────────────────────────────────────────────────

int Cinema::getNumEmployees() const
{
    return static_cast<int>(employees.size());
}

int Cinema::getNumGuests() const
{
    return static_cast<int>(guests.size());
}

int Cinema::getNumHalls() const
{
    return static_cast<int>(halls.size());
}

int Cinema::getNumMovies() const
{
    return static_cast<int>(movies.size());
}

int Cinema::getNumShifts() const
{
    return shifts.getSize();
}

// ── Index getters ─────────────────────────────────────────────────────────────

const Employee* Cinema::getEmployeeByIndex(int index) const {
    return (index >= 0 && index < (int)employees.size()) ? employees[index] : nullptr;
}
Employee* Cinema::getEmployeeByIndex(int index) {
    return (index >= 0 && index < (int)employees.size()) ? employees[index] : nullptr;
}

const Guest* Cinema::getGuestByIndex(int index) const {
    return (index >= 0 && index < (int)guests.size()) ? guests[index] : nullptr;
}
Guest* Cinema::getGuestByIndex(int index) {
    return (index >= 0 && index < (int)guests.size()) ? guests[index] : nullptr;
}

const Hall* Cinema::getHallByIndex(int index) const {
    return (index >= 0 && index < (int)halls.size()) ? halls[index] : nullptr;
}
Hall* Cinema::getHallByIndex(int index) {
    return (index >= 0 && index < (int)halls.size()) ? halls[index] : nullptr;
}

const Movie* Cinema::getMovieByIndex(int index) const {
    return (index >= 0 && index < (int)movies.size()) ? movies[index].get() : nullptr;
}
Movie* Cinema::getMovieByIndex(int index) {
    return (index >= 0 && index < (int)movies.size()) ? movies[index].get() : nullptr;
}

const Shift* Cinema::getShiftByIndex(int index) const {
    if (index < 0 || index >= shifts.getSize()) return nullptr;
    auto* node = shifts.getHead();
    for (int j = 0; j < index; ++j) node = node->next;
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

Cinema& Cinema::operator+=(Employee* employee)
{
    employees.push_back(employee);
    return *this;
}

Cinema& Cinema::operator+=(Guest* guest)
{
    guests.push_back(guest);
    return *this;
}

Cinema& Cinema::operator+=(Hall* hall)
{
    halls.push_back(hall);
    return *this;
}

Cinema& Cinema::operator+=(Movie* movie)
{
    movies.push_back(std::unique_ptr<Movie>(movie));
    return *this;
}

Cinema& Cinema::operator+=(Shift* shift)
{
    shifts.insert(shift);
    return *this;
}

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
    std::vector<std::unique_ptr<Movie>>::const_iterator itr    = movies.begin();
    std::vector<std::unique_ptr<Movie>>::const_iterator itrEnd = movies.end();
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