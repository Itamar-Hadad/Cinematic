#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int id;

public:
    Person(const std::string& name, int id);
    Person(const Person& other) = delete;
    Person& operator=(const Person& other) = delete;
    virtual ~Person() = default;

    const std::string& getName() const;
    int getId() const;

    void setName(const std::string& newName);

    virtual void printDetails() const = 0;
};

#endif
