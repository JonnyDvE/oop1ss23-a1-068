//----------------------------------------------------------------------------------------------------------------------
// HOGWARTSonline
//
// DO NOT CHANGE THIS FILE! IT WILL BE REPLACED IN THE TEST SYSTEM.
//
// Author: Tutors :)
//
#include "Command.hpp"
#include "CommandLine.hpp"
#include "DataBase.hpp"
#include "Utils.hpp"
#include <iostream>

enum ReturnValues
{
  SUCCESSFUL = 0,
  WRONG_NUMBER_OF_PARAMETERS = 1,
  CANNOT_OPEN_FILE = 2,
  INVALID_FILE = 3,
  LOGIN_ERROR = 4
};

//----------------------------------------------------------------------------------------------------------------------
// The main program. Controls the application on a high level view.
// Creates the database and a command line interface, handles the login of a user
// and the input and execution of commands.
//
//
// @param argc, argument count, has to be exactly 2
// @param argv, argument vector, contains the name of the csv-file
// @return 0 (SUCCESSFUL), if the application was closed without errors
//         a non-zero number is returned in the case of failure
//
int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "[ERROR] Wrong number of parameters!" << std::endl;
    return WRONG_NUMBER_OF_PARAMETERS;
  }
  DataBase db(argv[1]);
  if (!db.open())
  {
    std::cout << "[ERROR] Cannot open file!" << std::endl;
    return CANNOT_OPEN_FILE;
  }

  if (!db.parseFile())
  {
    std::cout << "[ERROR] File is invalid!" << std::endl;
    return INVALID_FILE;
  }

  std::cout << "Welcome to HOGWARTSonline!" << std::endl;

  CommandLine cli;
  std::string username = cli.login();
  if (!db.login(username))
  {
    std::cout << "[ERROR] Invalid login credentials!" << std::endl;
    return LOGIN_ERROR;
  }
  std::cout << "Login successful!\n" << std::endl;
  cli.setUserLevel(db.getUserLevel());

  while (true)
  {
    Command command = cli.readCommand();

    if (command.isQuit())
    {
      break;
    }
    bool modification_mode = db.execute(command);
    cli.setMode(modification_mode);
  }

  std::cout << "Log Out complete." << std::endl;
  return SUCCESSFUL;
}
