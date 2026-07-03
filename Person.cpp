#include "Person.h"

Person::Person(const std::string& name, int id) : name(name), id(id) {}

const std::string& Person::getName() const { return name; }
int                Person::getId()   const { return id;   }

void Person::setName(const std::string& newName) { name = newName; }
