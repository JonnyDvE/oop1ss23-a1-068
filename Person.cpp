//
// Created by student on 23.03.23.
//
#include <map>
#include <sstream>
#include <utility>

#include "Person.hpp"
#include "iostream"
#include "string"

const std::map<std::string, House> houseMap
    {
        {"Slytherin", House::Slytherin},
        {"Hufflepuff", House::Hufflepuff},
        {"Gryffindor", House::Gryffindor},
        {"Ravenclaw", House::Ravenclaw},
        {"Invalid", House::Invalid}
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
    if(houseMap.find(name) != houseMap.end())
      return houseMap.find(name)->second;
    return House::Invalid;
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
  const std::string& Person::getName() const
  {
    return name_;
  }
  const std::string& Person::getSurname() const
  {
    return surname_;
  }
  House Person::getHouse() const
  {
    return house_;
  }
  std::string Person::getFullName() const
  {
    std::stringstream ss;
    ss << name_ << " " << surname_;
    return ss.str();
  }