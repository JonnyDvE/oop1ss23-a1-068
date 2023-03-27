//
// Created by student on 27.03.23.
//

#include "Assignment.hpp"

#include <utility>
Assignment::Assignment(std::string name) : name_(std::move(name)){}
const std::string& Assignment::getName() const
{
  return name_;
}
void Assignment::addGrade(Student* student, unsigned points)
{
  points_.insert({student, points});
}
void Assignment::changeGrade(Student* student, unsigned int points)
{
  points_.find(student)->second = points;
}
