//
// Created by student on 24.03.23.
//

#include "CommandLine.hpp"
#include "Command.hpp"
#include "Utils.hpp"
#include <iostream>
#include <regex>
#include <string>
CommandLine::CommandLine() : user_level_(PersonType::Default), modification_mode_(false) {}
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
  std::cout << "Enter your username:" << std::endl;
  std::cout << " > ";
  std::string username;
  std::getline(std::cin, username);
  return username;
}
Command CommandLine::readCommand()
{
  std::cout << " > ";
  std::string input;
  std::getline(std::cin, input);
  std::vector<std::string> vectorised_string;
  Utils::stringToVector(input, vectorised_string, ' ');
  Command command(vectorised_string);
  if(vectorised_string.empty())
  {
    command.setType(CommandType::INVALID);
    return command;
  }
  switch (command.getType())
  {
    case CommandType::SHOW:
    case CommandType::QUIT:
    case CommandType::BACK:
      if(!command.getParameters().empty())
        command.setType(CommandType::INVALID);
      break;
    case CommandType::INVALID:
      break;
    case CommandType::ADDSTUDENT:
      if(command.getParameters().size() != 3 )
        command.setType(CommandType::INVALID);
      break;
    case CommandType::MODIFYSTUDENT:
      if(command.getParameters().size() != 2)
        command.setType(CommandType::INVALID);
      break;
    case CommandType::ADDGRADE:
      if(command.getParameters().size() < 2)
        command.setType(CommandType::INVALID);
      break;
    case CommandType::REMOVEGRADE:
      if(command.getParameters().empty())
        command.setType(CommandType::INVALID);
      break;
    case CommandType::SAVE:
      if(command.getParameters().size() != 1)
        command.setType(CommandType::INVALID);
      break;
  }
  if(command.getType() == CommandType::INVALID)
  {
    std::cout << "[ERROR] Invalid command or invalid number of parameters!" << std::endl;
    return command;
  }
  if(!command.isStudentUsable() && user_level_ == PersonType::Student)
  {
    std::cout << "[ERROR] As a student, you are not allowed to do this!" << std::endl;
    command.setType(CommandType::INVALID);
    return command;
  }
  if(command.isModificationModeOnly() && !modification_mode_)
  {
    std::cout << "[ERROR] You can only do this in modification mode!" << std::endl;
    command.setType(CommandType::INVALID);
  }
  if(!command.isModificationModeOnly() && modification_mode_ && command.getType() != CommandType::QUIT)
  {
    std::cout << "[ERROR] You cannot do this in modification mode!" << std::endl;
    command.setType(CommandType::INVALID);
  }
  return command;
}
