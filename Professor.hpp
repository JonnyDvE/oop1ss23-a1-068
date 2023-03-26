//
// Created by student on 23.03.23.
//

#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "Person.hpp"
#include <string>
class Professor :public Person
{
public:
  Professor(const std::string& name, const std::string& surname, House house);
  PersonType getType() override;
};
#endif // PROFESSOR_HPP
