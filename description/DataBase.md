# DataBase

The `DataBase` class is the central element of HOGWARTSonline. Here, all data - including students, professors, subjects, assignments, and grades - are stored. Moreover, the database provides functionality to read from and write to a `.csv` file. This document describes this class in detail.

## `DataBase.hpp` / `DataBase.cpp`

### Class `DataBase`

#### Data Members (Member Variables)

- `file_`
  - stores the `.csv` file, where the data is loaded from, as an `std::ifstream`
- `students_`
  - stores all students in a `std::vector<Student*>`
  - it is crucial that the students are stored in the same order, as they appear in the `.csv` file
- `professors_`
  - stores all professors in a `std::vector<Professor*>`
  - it is crucial that the professors are stored in the same order, as they appear in the `.csv` file
- `subjects_`
  - stores all subjects in a `std::vector<Subject*>`
  - it is crucial that the subjects are stored in the same order, as they appear in the `.csv` file
- `active_user_`
  - stores a pointer to the currently logged-in user. Since it can be either a student or a professor, use a `Person*` here.
  - can be initialised with `nullptr` or `NULL` when the program starts

#### Constructor / Copy Constructor / Destructor

- `DataBase(std::string filename)`
  - initialises all data members meaningfully
  - in particular, the `file_` data member should be initialised with `filename`
- The copy constructor should be deleted explicitly.
- A suitable destructor should be implemented. If the default destructor is used, this should be done explicitly.

> **Hint:** Make sure to free all allocated memory in the destructor to avoid memory leaks.

#### Methods

- `PersonType getUserLevel()`
  - returns the type of user, that is currently logged in
- `bool open()`
  - returns `true`, if and only if the file is open
- `bool parseFile()`
  - parses the csv file
  - returns `true`, if and only if the file is valid and parsed successfully
- `bool login(std::string username)`
  - checks, whether a user with that name exists in the database.
    - If so, set the data member `active_user_` to the corresponding user and return `true`,
    - otherwise return `false`
- `bool execute(Command command)`
  - executes the corresponding command within the database
  - the return value determines, in which mode the program continues
    - `true`: the program continues in modification mode
    - `false`: the program continues in normal mode

> Hint: You have to create further (private) methods, for example parsing the `.csv` file or writing to it requires several methods. Additionally, it is recommended to implement each command in a separate (private) method.
