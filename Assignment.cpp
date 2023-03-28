//
// Created by student on 27.03.23.
//

#include "Assignment.hpp"

#include <iostream>
#include <sstream>
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
  if(points_.find(student) == points_.end())
  {
    addGrade(student, points);
    return ;
  }
  points_.find(student)->second = points;
}
std::string Assignment::getGrade(Student* student)
{
  auto points = points_.find(student);
  if(points == points_.end())
  {
    return "NO POINTS AVAILABLE";
  }
  std::stringstream ss;
  ss << points->second;
  return ss.str();
}
int Assignment::getGradeAsInt(Student* student)
{
  auto points = points_.find(student);
  if(points == points_.end())
  {
    return -1;
  }
  return points->second;
}
void Assignment::removeGrade(Student* student)
{
  points_.erase(student);
}
