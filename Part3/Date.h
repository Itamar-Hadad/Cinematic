#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

    static bool isValidDate(int day, int month, int year);

public:
    Date(int day = 1, int month = 1, int year = 2000);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);

    bool operator==(const Date& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif
