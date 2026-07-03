#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Date.h"

class Employee : public Person {
private:
    Date birthDate;
    double salary;

    static const double PROMOTION_PERCENTAGE;

public:
    Employee(const std::string& name, int id, const Date& birthDate, double salary);
    Employee(const Employee& other) = delete;
    Employee& operator=(const Employee& other) = delete;
    ~Employee() override = default;

    const Date& getBirthDate() const;
    double getSalary() const;

    void setSalary(double newSalary);

    Employee& operator++();

    void printDetails() const override;
};

#endif
