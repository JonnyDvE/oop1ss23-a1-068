//
// Created by student on 23.03.23.
//

#include "DataBase.hpp"
#include "HardSubject.hpp"
#include "Utils.hpp"
#include <iostream>

DataBase::DataBase(std::string filename)
{
    file_.open(filename, std::ifstream::in);
    active_user_ = nullptr;
}
PersonType DataBase::getUserLevel()
{
  return active_user_->getType();
}
bool DataBase::login(std::string username)
{
  return false;
}
bool DataBase::execute(Command command)
{
  return false;
}
bool DataBase::parseFile()
{
  std::string line;
  std::getline(file_, line);
  std::vector<std::string> vectorisedLine;
  std::vector<Assignment*> assignments;
  Utils::stringToVector(line, vectorisedLine, ';');
  {
    std::vector<std::string> vectorisedAssignments(vectorisedLine.begin() + 5, vectorisedLine.end());
    for (auto &word : vectorisedAssignments)
    {
      assignments.push_back(new Assignment(word));
    }
  }
  while(!line.empty())
  {
    std::getline(file_, line);
    if(line.empty())
      break ;
    Utils::stringToVector(line, vectorisedLine, ';');
//    for(auto &x : vectorisedLine)
//    {
//      std::cout << x << std::endl;
//    }

    std::string name = vectorisedLine.at(0);
    std::string surname = vectorisedLine.at(1);
    House house = Person::getHouse(vectorisedLine.at(2));
    if(vectorisedLine.at(3).empty())
    {
      auto * student = new Student(name, surname, house);
      students_.push_back(student);
      std::vector<std::string>points (vectorisedLine.begin() + 5, vectorisedLine.end());
      std::cout << student->getFullName();
      int count = 0;
      size_t assignment_count = 0;
      unsigned point_in_unsigned;
      for(auto &point : points)
      {
        std::cout << point << std::endl;
        Utils::decimalStringToInt(point, point_in_unsigned);
        if(assignment_count >= subjects_[count]->getAssignments().size())
        {
          count++;
          assignment_count = 0;
        }
        if(!point.empty())
        subjects_[count]->getAssignments().at(assignment_count)->addGrade(student, point_in_unsigned);
      }
    }
    else
    {
      auto * subject = new Subject(vectorisedLine.at(3), vectorisedLine.at(4) == "Hard");
      auto * professor = new Professor(name, surname, house, subject);
      professors_.push_back(professor);
      subjects_.push_back(subject);
      std::vector<Assignment*> current_assignments;
      for(auto &x : vectorisedLine)
      {
        if(x == "X")
        {
          current_assignments.push_back(assignments.front());
          if(assignments.size() != 1)
            assignments.erase(assignments.begin());
          else
            assignments.clear();
        }
      }
      subject->setAssignments(current_assignments);

    }
    vectorisedLine.clear();
  }
  return true;
}
DataBase::~DataBase()
{

}
bool DataBase::open()
{
  return file_.is_open();
}
