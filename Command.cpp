//
// Created by student on 24.03.23.
//

#include "Command.hpp"
#include <map>
bool Command::isQuit()
{
  //TODO free mem
  return this->type_ == CommandType::QUIT;
}
Command::Command(std::vector<std::string> input)
{
  type_ = getCommandType(input.front());
  input.erase(input.begin());
  parameters_ = input;
}
CommandType Command::getCommandType(std::string input)
{
  const std::map<std::string, CommandType> allTypes
  {
    {"INVALID", CommandType::INVALID},
    {"SHOW", CommandType::SHOW},
    {"ADDSTUDENT", CommandType::ADDSTUDENT},
    {"MODIFYSTUDENT", CommandType::MODIFYSTUDENT},
    {"ADDGRADE" , CommandType::ADDGRADE},
    {"REMOVEGRADE", CommandType::REMOVEGRADE},
    {"BACK", CommandType::BACK},
    {"SAVE", CommandType::SAVE},
    {"QUIT", CommandType::QUIT}
  };
  auto result = allTypes.find(input);
  if(result != allTypes.end())
  {
    return result->second;
  }
  return CommandType::INVALID;
}
