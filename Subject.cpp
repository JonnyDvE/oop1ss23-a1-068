//
// Created by student on 23.03.23.
//

#include "Subject.hpp"

#include <iostream>
#include <utility>
Subject::Subject(std::string name, bool is_hard) : name_(std::move(name)), is_hard(is_hard) {}
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
std::string Subject::calculateGrade(Student* student)
{
  int grade = 1000;
  int total = 0;

  for(auto assignments : assignments_)
  {
    int current = assignments->getGradeAsInt(student);
    if(current < 0)
      return getGradeString(current);
    if(current < grade)
    {
      grade = current;
    }
    if(current > 0)
      total += current;
  }
  if(is_hard)
  {
    return getGradeString(grade);
  }
  return getGradeString(total/(assignments_.size()));
}
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
bool Subject::isHard() const
{
  return is_hard;
}
