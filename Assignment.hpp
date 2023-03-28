//
// Created by student on 27.03.23.
//

#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include <map>
#include "Student.hpp"
class Assignment
{
public:
  Assignment(std::string name);
  Assignment(Assignment & ) = delete;
  [[nodiscard]] const std::string& getName() const;
  void addGrade(Student* student, unsigned points);
  void changeGrade(Student* student, unsigned points);
  void removeGrade(Student* student);
  int getGradeAsInt(Student* student);
  std::string getGrade(Student* student);

private:
  std::string name_;
  std::map<Student*, unsigned> points_;
};

#endif // ASSIGNMENT_HPP
