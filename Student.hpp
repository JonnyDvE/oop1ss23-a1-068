//
// Created by student on 23.03.23.
//

#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "Person.hpp"
#include <string>
class Student :public Person
{
public:
  Student(const std::string& name, const std::string& surname, House house);
  PersonType getType() override;
};
#endif // STUDENT_HPP
