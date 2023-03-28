//
// Created by student on 23.03.23.
//

#ifndef OOP1SS23_A1_068_SUBJECT_HPP
#define OOP1SS23_A1_068_SUBJECT_HPP

#include "Assignment.hpp"
#include "Student.hpp"
#include <vector>

enum class SubjectType
{
  HardSubject,
  EasySubjecct
};
class Subject
{
private:
  std::string name_;
  std::vector<Assignment*> assignments_;
  bool is_hard;
public:
  bool isHard() const;
  std::string calculateGrade(Student* student);
  SubjectType getType();
  Subject(std::string name, bool is_hard);
  Subject(Subject &) = delete;
  void addAssignments(Assignment* assignments);
  void setAssignments(const std::vector<Assignment*>& assignments);
  [[nodiscard]] const std::string& getName() const;
  const std::vector<Assignment*>& getAssignments() const;
  std::string getGradeString(int grade);
};

#endif // OOP1SS23_A1_068_SUBJECT_HPP
