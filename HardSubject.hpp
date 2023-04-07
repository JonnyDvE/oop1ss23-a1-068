//
// Created by student on 07.04.23.
//

#ifndef OOP1SS23_A1_068_HARDSUBJECT_HPP
#define OOP1SS23_A1_068_HARDSUBJECT_HPP

#include "Subject.hpp"
class HardSubject : public Subject
{
private: 

  std::string calculateGrade(Student *student) override;
public:
  explicit HardSubject(std::string name);
  HardSubject(HardSubject &) = delete;
  //friend std::ostream operator<<(std::ostream& os, const HardSubject& sub);
  [[nodiscard]] std::string getType() const override;
};

#endif // OOP1SS23_A1_068_HARDSUBJECT_HPP
