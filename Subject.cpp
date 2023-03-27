//
// Created by student on 23.03.23.
//

#include "Subject.hpp"

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
