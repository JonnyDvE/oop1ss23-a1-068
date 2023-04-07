//
// Created by student on 23.03.23.
//

#include "Subject.hpp"

#include <iostream>
#include <utility>
Subject::Subject(std::string name) : name_(std::move(name)){}
void Subject::addAssignments(Assignment* assignments)
{
  assignments_.push_back(assignments);
}
void Subject::setAssignments(const std::vector<Assignment*>& assignments)
{
  assignments_ = assignments;
}
const std::string& Subject::getName() const
{
  return name_;
}
const std::vector<Assignment*>& Subject::getAssignments() const
{
  return assignments_;
}

#pragma clang diagnostic ignored "-Wgnu-case-range"
std::string Subject::getGradeString(int grade)
{
  switch (grade)
  {
    case 0 ... 16:
      return "Troll";
    case 17 ... 33:
      return "Dreadful";
    case 34 ... 50:
      return "Poor";
    case 51 ... 67:
      return "Acceptable";
    case 68 ... 84:
      return "Exceeds Expectations";
    case 85 ... 100:
      return "Outstanding";
    default:
      return "NO GRADE AVAILABLE";
  }
}
Subject::~Subject()
{
  for(auto assigns : assignments_)
  {
    delete assigns;
  }
}
std::ostream& operator<<(std::ostream& os, const Subject& sub)
{
  os << sub.getType();
  return os;
}
