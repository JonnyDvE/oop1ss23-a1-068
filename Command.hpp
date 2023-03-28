//
// Created by student on 24.03.23.
//

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>
#include "Utils.hpp"
enum class CommandType
{
  INVALID,
  SHOW,
  ADDSTUDENT,
  MODIFYSTUDENT,
  ADDGRADE,
  REMOVEGRADE,
  BACK,
  SAVE,
  QUIT
};
class Command
{
private:
  CommandType type_;
  bool is_student_usable_;
  bool is_modification_mode_only_;
  std::vector<std::string> parameters_;
public:
  Command(std::vector<std::string> input);
  bool isQuit();
  CommandType getCommandType(std::string);
  CommandType getType() const;
  const std::vector<std::string>& getParameters() const;
  void setType(CommandType type);
  bool isStudentUsable() const;
  bool isModificationModeOnly() const;
};

#endif // COMMAND_HPP
