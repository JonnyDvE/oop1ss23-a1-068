//
// Created by student on 24.03.23.
//

#ifndef COMMANDLINE_HPP
#define COMMANDLINE_HPP

#include "Person.hpp"
#include "Command.hpp"
class CommandLine
{
public:
  CommandLine();
  CommandLine(const CommandLine&) = delete;
  ~CommandLine();
  void setUserLevel(PersonType user_level);
  void setMode(bool modification_mode);
  std::string login();
  Command readCommand();

private:
  PersonType user_level_;
  bool modification_mode_;

};

#endif // COMMANDLINE_HPP
