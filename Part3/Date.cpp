#include "Date.h"
#include <iomanip>

bool Date::isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;
    return day <= daysInMonth[month - 1];
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

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

void Date::setDay(int newDay) {
    if (isValidDate(newDay, month, year)) day = newDay;
}

void Date::setMonth(int newMonth) {
    if (isValidDate(day, newMonth, year)) month = newMonth;
}

void Date::setYear(int newYear) {
    if (isValidDate(day, month, newYear)) year = newYear;
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setfill('0')
       << std::setw(2) << date.day   << '/'
       << std::setw(2) << date.month << '/'
       << std::setw(4) << date.year;
    return os;
}
