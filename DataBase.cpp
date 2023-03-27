//
// Created by student on 23.03.23.
//

#include "DataBase.hpp"
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
  std::vector<std::string> vectorisedAssignments;
  int counter = 0;
  while(!line.empty())
  {
    Utils::stringToVector(line, vectorisedLine, ';');
    if(counter == 0)
    {
      vectorisedAssignments = vectorisedLine;
    }
    else
    {
      std::string name = vectorisedLine.at(1);
      std::string surname = vectorisedLine.at(2);
      std::cout << name << " " << surname << std::endl;
      House house = Person::getHouse(vectorisedLine.at(3));
      if(vectorisedLine.at(4).empty())
      {
        auto * student = new Student(name, surname, house);
        students_.push_back(student);
      }
      else
      {
        auto * professor = new Professor(name, surname, house);
        professors_.push_back(professor);
      }
    }

    counter++;
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
