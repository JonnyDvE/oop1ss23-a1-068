//
// Created by student on 23.03.23.
//

#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "Person.hpp"
#include "Subject.hpp"
#include <string>
class Professor :public Person
{
private:
  Subject* subject_;
public:
  Professor(const std::string& name, const std::string& surname, House house, Subject* subject);
  Professor(Professor &) = delete;
  ~Professor() override;
  PersonType getType() override;
  Subject* getSubject() const;
};
#endif // PROFESSOR_HPP
