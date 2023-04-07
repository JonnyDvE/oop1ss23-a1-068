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
  Student* student_in_editing{};
  Person* isInDatabase(const std::string& name, const std::string& surname);
  Subject* subjectInData(const std::string& name);
  void show();
  void addStudent(std::vector<std::string> args);
  bool modifyStudent(std::vector<std::string> args);
  void addGrade(std::vector<std::string> args);
  void removeGrade(std::vector<std::string> args);
  void back();
  void save(std::vector<std::string> args);
public:
  explicit DataBase(const std::string& filename);
  DataBase(DataBase&) = delete;
  ~DataBase();
  PersonType getUserLevel();
  bool login(const std::string& username);
  bool execute(const Command& command);
  bool parseFile();
  bool open();

  static std::string parseSubject(const std::vector<std::string>& vector);
  std::string firstLineBuilder();
  std::string studentLineBuilder( Student* student);
  std::string professorLineBuilder(Professor* professor);
};
#endif // DATABASE_HPP
