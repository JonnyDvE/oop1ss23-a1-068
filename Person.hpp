//
// Created by student on 23.03.23.
//

#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
enum class House
{
  Gryffindor,
  Ravenclaw,
  Hufflepuff,
  Slytherin,
  Invalid
};
enum class PersonType
{
  Student, Professor, Default
};
class Person
{
private:
  std::string name_;
  std::string surname_;
  House house_;

public:
  Person(std::string  name, std::string  surname, House house);
  Person(const Person&) = delete;
  virtual ~Person();
  virtual PersonType getType();
  static House getHouse(std::string name);
  const std::string& getName() const;
  const std::string& getSurname() const;
  House getHouse() const;
  std::string getFullName() const;
  std::string getHouseString();
};

#endif // PERSON_HPP
