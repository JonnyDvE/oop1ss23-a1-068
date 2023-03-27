//
// Created by student on 23.03.23.
//
#include <map>
#include <utility>

#include "Person.hpp"
#include "iostream"
#include "string"

const std::map<std::string, House> houseMap
    {
        {"Slytherin", House::Slytherin},
        {"Hufflepuff", House::Hufflepuff},
        {"Gryffindor", House::Gryffindor},
        {"Ravenclaw", House::Ravenclaw}
    };

Person::Person(std::string  name, std::string  surname, House house) : name_(std::move(name)), surname_(std::move(surname)),
    house_(house)
  {}
  PersonType Person::getType()
  {
    return PersonType::Default;
  }
  Person::~Person() {}
  House Person::getHouse(std::string name)
  {
    return houseMap.find(name)->second;
  }
  std::string Person::getHouseString(House house)
  {
    for(const auto& [name, houseObj] : houseMap)
    {
      if (houseObj == house)
      return name;
    }
    return nullptr;
  }
