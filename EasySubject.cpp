//
// Created by student on 07.04.23.
//

#include "EasySubject.hpp"

#include <iostream>
#include <utility>

std::string EasySubject::calculateGrade(Student* student)
{
  int total = 0;
  int count = 0;
  for(auto assignments : assignments_)
  {
    int current = assignments->getGradeAsInt(student);
    if(current < 0)
      return getGradeString(current);
    total += current;
    count++;
  }
  total /= count;
  return getGradeString(total);
}
std::string EasySubject::getType() const
{
  return "Easy";
}
EasySubject::EasySubject(std::string name) : Subject(std::move(name)) {}
