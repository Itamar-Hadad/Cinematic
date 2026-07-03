#include "Employee.h"
#include <iostream>

const double Employee::PROMOTION_PERCENTAGE = 0.10;

Employee::Employee(const char* name, int id, const Date& birthDate, double salary)
    : Person(name, id), birthDate(birthDate), salary(salary) {}

Employee::~Employee() {}

const Date& Employee::getBirthDate() const { return birthDate; }
double      Employee::getSalary()    const { return salary;    }

void Employee::setSalary(double newSalary) { salary = newSalary; }

Employee& Employee::operator++() {
    salary *= (1.0 + PROMOTION_PERCENTAGE);
    return *this;
}

void Employee::printDetails() const {
    std::cout << "Employee: " << getName()
              << " | ID: "     << getId()
              << " | DOB: "    << birthDate
              << " | Salary: " << salary
              << std::endl;
}
