//
// Created by student on 23.03.23.
//

#include "Student.hpp"
#include <string>

Student::Student(const std::string& name, const std::string& surname, House house) :
    Person(name, surname, house){}
PersonType Student::getType()
{
  return PersonType::Student;
}
