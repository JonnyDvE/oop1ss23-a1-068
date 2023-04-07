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
  HARD,
  EASY
};
class Subject
{
private:
protected:
  std::vector<Assignment*> assignments_;
  std::string name_;
public:
  virtual std::string calculateGrade(Student* student) = 0;
  explicit Subject(std::string name);
  Subject(Subject &) = delete;
  void addAssignments(Assignment* assignments);
  void setAssignments(const std::vector<Assignment*>& assignments);
  [[nodiscard]] const std::string& getName() const;
  const std::vector<Assignment*>& getAssignments() const;
  std::string getGradeString(int grade);
  virtual ~Subject();
  virtual std::string getType() const = 0;
  friend std::ostream& operator<<(std::ostream os, const Subject& sub);
  
};

#endif // OOP1SS23_A1_068_SUBJECT_HPP
