#include "Person.h"
#include <cstring>

Person::Person(const char* name, int id) : id(id) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Person::~Person() {
    delete[] name;
}

const char* Person::getName() const { return name; }
int         Person::getId()   const { return id;   }

void Person::setName(const char* newName) {
    delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}
