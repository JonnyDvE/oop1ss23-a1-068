//
// Created by student on 23.03.23.
//
#include <utility>

#include "iostream"
#include "string"
#include "Person.hpp"

  Person::Person(std::string  name, std::string  surname, House house) : name_(std::move(name)), surname_(std::move(surname)),
    house_(house)
  {}
  PersonType Person::getType()
  {
    return PersonType::Default;
  }
  Person::~Person() {}
