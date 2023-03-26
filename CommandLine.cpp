//
// Created by student on 24.03.23.
//

#include "CommandLine.hpp"
#include "Command.hpp"
#include <iostream>
#include <string>
#include "Utils.hpp"
CommandLine::CommandLine() : modification_mode_(false), user_level_(PersonType::Default) {}
CommandLine::~CommandLine() {}
void CommandLine::setUserLevel(PersonType user_level)
{
  user_level_ = user_level;
}
void CommandLine::setMode(bool modification_mode)
{
  modification_mode_ = modification_mode;
}
std::string CommandLine::login()
{
  std::string username;
  std::cin >> username;
  return username;
}
Command CommandLine::readCommand()
{
  std::string input;
  std::cin >> input;
  std::vector<std::string> vectorised_string;
  Utils::stringToVector(input, vectorised_string);
  Command command = Command(vectorised_string);
  return command;
}