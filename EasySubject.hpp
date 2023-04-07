//
// Created by student on 07.04.23.
//

#ifndef OOP1SS23_A1_068_EASYSUBJECT_HPP
#define OOP1SS23_A1_068_EASYSUBJECT_HPP

#include "Subject.hpp"
class EasySubject : public Subject
{
private:
  std::string calculateGrade(Student *student) override;
public:
  [[nodiscard]] std::string getType() const override;
  explicit EasySubject(std::string name);
  EasySubject(EasySubject &) = delete;
};

#endif // OOP1SS23_A1_068_EASYSUBJECT_HPP
