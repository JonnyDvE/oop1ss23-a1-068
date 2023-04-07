//
// Created by student on 07.04.23.
//

#include "HardSubject.hpp"

#include <iostream>
#include <utility>
std::string HardSubject::getType() const
{
  return "Hard";
}
std::string HardSubject::calculateGrade(Student* student)
{
  {
    int min = 101;
    for(auto assignments : assignments_)
    {
      int current = assignments->getGradeAsInt(student);
      if(current < 0)
        return getGradeString(current);
      if(current < min)
        min = current;
    }
    return getGradeString(min);
  }
}
HardSubject::HardSubject(std::string name) : Subject(std::move(name)) {}
std::ostream& operator<<(std::ostream& os, const HardSubject& sub)
{
  os << sub.getType();
  return os;
}
