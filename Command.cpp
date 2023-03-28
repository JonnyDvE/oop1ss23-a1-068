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
  is_student_usable_ = (type_ == CommandType::QUIT || type_ == CommandType::SHOW);
  is_modification_mode_only_ =(type_ == CommandType::ADDGRADE || type_ == CommandType::REMOVEGRADE || type_
                                                                                                           ==CommandType::BACK);
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
  Utils::stringToUpperCase(input);
  auto result = allTypes.find(input);
  if(result != allTypes.end())
  {
    return result->second;
  }
  return CommandType::INVALID;
}
CommandType Command::getType() const
{
  return type_;
}
const std::vector<std::string>& Command::getParameters() const
{
  return parameters_;
}
void Command::setType(CommandType type)
{
  type_ = type;
}
bool Command::isStudentUsable() const
{
  return is_student_usable_;
}
bool Command::isModificationModeOnly() const
{
  return is_modification_mode_only_;
}
Command::Command(CommandType type) : type_(type){};
