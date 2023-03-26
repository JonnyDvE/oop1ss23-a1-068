//
// Created by student on 24.03.23.
//

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>
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
  std::vector<std::string> parameters_;
public:
  Command(std::vector<std::string> input);
  bool isQuit();
  CommandType getCommandType(std::string);

};

#endif // COMMAND_HPP
