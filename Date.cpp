#include "Date.h"
#include <iomanip>

bool Date::isValidDate(int d, int m, int y) {
    if (y < 1 || m < 1 || m > 12 || d < 1)
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        daysInMonth[1] = 29;
    return d <= daysInMonth[m - 1];
}

Date::Date(int day, int month, int year) {
    if (isValidDate(day, month, year)) {
        this->day   = day;
        this->month = month;
        this->year  = year;
    } else {
        this->day   = 1;
        this->month = 1;
        this->year  = 2000;
    }
}

int Date::getDay()   const { return day;   }
int Date::getMonth() const { return month; }
int Date::getYear()  const { return year;  }

void Date::setDay(int d) {
    if (isValidDate(d, month, year)) day = d;
}

void Date::setMonth(int m) {
    if (isValidDate(day, m, year)) month = m;
}

void Date::setYear(int y) {
    if (isValidDate(day, month, y)) year = y;
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << std::setfill('0')
       << std::setw(2) << d.day   << '/'
       << std::setw(2) << d.month << '/'
       << std::setw(4) << d.year;
    return os;
}
