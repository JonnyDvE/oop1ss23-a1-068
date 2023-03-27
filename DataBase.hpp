//
// Created by student on 23.03.23.
//

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Command.hpp"
#include "Person.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "Subject.hpp"
#include <fstream>
#include <vector>

class DataBase
{
private:
  std::ifstream file_;
  std::vector<Student*> students_;
  std::vector<Professor*> professors_;
  std::vector<Subject*> subjects_;
  Person* active_user_;
public:
  explicit DataBase(std::string filename);
  DataBase(DataBase&) = delete;
  ~DataBase();
  PersonType getUserLevel();
  bool login(std::string username);
  bool execute(Command command);
  bool parseFile();
  bool open();




};
#endif // DATABASE_HPP
