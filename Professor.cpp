//
// Created by student on 23.03.23.
//

#include "Professor.hpp"
#include "Person.hpp"
#include <string>
#include <utility>

Professor::Professor(const std::string& name, const std::string& surname, House house, Subject* subject) :
  Person{name, surname, house}, subject_(subject) {}
PersonType Professor::getType()
{
  return PersonType::Professor;
}
Subject* Professor::getSubject() const
{
  return subject_;
}
