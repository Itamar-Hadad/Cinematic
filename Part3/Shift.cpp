#include "Shift.h"
#include <iostream>

Shift::Shift(const Employee& worker, int shiftLength, const Date& shiftDate)
    : workerRef(worker), shiftLength(shiftLength), shiftDate(shiftDate) {}

Shift::Shift(const Shift& other)
    : workerRef(other.workerRef), shiftLength(other.shiftLength),
      shiftDate(other.shiftDate) {}

Shift::~Shift()
{
}

const Employee& Shift::getWorker() const
{
    return workerRef;
}

int Shift::getShiftLength() const
{
    return shiftLength;
}

const Date& Shift::getShiftDate() const
{
    return shiftDate;
}

void Shift::setShiftLength(int hours)
{
    shiftLength = hours;
}

void Shift::printShift() const {
    std::cout << "Shift | Employee: " << workerRef.getName()
              << " (ID: "             << workerRef.getId() << ")"
              << " | Date: "          << shiftDate
              << " | Hours: "         << shiftLength
              << std::endl;
}
