# Commands & Command Line Interface

In this part of the description, you can find the details about the classes `Command` and `CommandLine`.

## `Command.hpp` / `Command.cpp`

### Enum (class) `CommandType`

This enum (class) collects all possible command types, that may be entered by a user. Those are `SHOW`, `ADDSTUDENT`, `MODIFYSTUDENT`, `ADDGRADE`, `REMOVEGRADE`, `BACK`, `SAVE`, and `QUIT`. You can add further options like `INVALID` or `UNKNOWN`, if needed.

> **Hint:** It is preferable to use strongly typed enum classes instead of ordinary enums.

### Class `Command`

This class represents a command, consisting of a command type and parameters.

#### Data Members (Member Variables)

- `type_`
  - represents the command type, that was entered by the user. Use the enum `CommandType` here.
- `parameters_`
  - stores all parameters, that were entered by the user (not including the command type) as a `std::vector<std::string>`
  - e.g. for the command `modifystudent Harry Potter`, we would store `Harry` and `Potter` here.

#### Constructor / Copy Constructor / Destructor

- `Command(std::vector<std::string> input)`
  - receives the user input (already split into words)
  - initialises the two data members accordingly
- Suitable copy constructors and destructors should be implemented. If the default ones are used, this should be done explicitly.

#### Methods

- `bool isQuit()`
  - returns `true`, if and only if the command type is `QUIT`
- getter / setter / further methods as needed

---

## `CommandLine.hpp` / `CommandLine.cpp`

### Class `CommandLine`

#### Data Members (Member Variables)

- `user_level_`
  - stores the type of the user. Use the enum `PersonType` here.
- `modification_mode_`
  - indicates, whether the user uses the modification or normal mode
  - can be implemented as a `bool`
  - normal mode is the default option

#### Constructor / Copy Constructor / Destructor

- `CommandLine()`
  - initialises the data member `modification_mode_` to `false`
- The copy constructor should be deleted explicitly.
- A suitable destructor should be implemented. If the default destructor is used, this should be done explicitly.

#### Methods

- `std::string login()`
  - handles the [Login](../README.md#login) and returns the entered username
- `void setUserLevel(PersonType user_level)`
  - setter for the data member `user_level_`
- `Command readCommand()`
  - reads an input from the user and stores it in a `Command` object, if it is valid
- `void setMode(bool modification_mode)`
  - setter for the data member `modification_mode_`
- getter / setter / further methods as needed
