//
// Created by student on 23.03.23.
//

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Person.hpp"
#include "Professor.hpp"
#include "Subject.hpp"
#include "Command.hpp"
#include <fstream>
#include <vector>

class DataBase
{
private:
  std::ifstream file_;
  std::vector<Professor*> professors_;
  std::vector<Subject*> subjects_;
  Person* active_user_;
public:
  DataBase(std::string filename);
  DataBase(DataBase&) = delete;
  ~DataBase();
  PersonType getUserLevel();
  bool login(std::string username);
  bool execute(Command command);
  bool parseFile();
  bool open();




};
#endif // DATABASE_HPP
