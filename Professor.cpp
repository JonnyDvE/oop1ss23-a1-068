//
// Created by student on 23.03.23.
//

#include "Professor.hpp"
#include "Person.hpp"
#include <string>

Professor::Professor(const std::string& name, const std::string& surname, House house) :
  Person{name, surname, house} {}
PersonType Professor::getType()
{
  return PersonType::Professor;
}
