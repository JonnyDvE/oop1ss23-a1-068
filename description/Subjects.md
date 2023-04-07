# Subject / EASY / HARD

This document describes all the classes responsible for representing subjects and calculating grades: the base class `Subject` and the two derived classes `EASY` and `HARD`.

## `Subject.hpp` / `Subject.cpp`

### Enum `SubjectType`

HOGWARTSonline distinguishes between easy and hard subjects. To this end, define an enumeration data type called `SubjectType` which comprises the values `EASY` and `HARD`.

> Hint: It is preferable to use strongly typed enum classes instead of ordinary enums.

### Class `Subject`

The class `Subject` represents a course at Hogwarts and serves as the base class for `EASY` and `HARD`. Thus, it should be implemented as an abstract class.

#### Data Members (Member Variables)

- `name_`
    - stores the name of the subject as an `std::string`.
- `assignments_`
    - stores all assignments of this subject as an `std::vector<Assignment*>`.
    - It is crucial that the assignments are stored in the same order, as they appear in the csv file

#### Constructor / Copy Constructor / Destructor

- `Subject(std::string name)`
    - constructor of the class
    - initialises all data members accordingly
- The copy constructor should be deleted explicitly.
- A suitable destructor should be implemented. If the default destructor is used, this should be done explicitly.

> Hint: Take a close look at how to declare the destructor in a base class.

#### Methods

- `SubjectType getType()`
    - pure virtual method, which is implemented in derived classes
- `std::string calculateGrade(Student* student)`
  - pure virtual method, which is implemented in derived classes
- getter / setter / further methods as needed

> Hint: You may write methods to add an assignments to a subject, add / change / remove a student's points on an assignment.

---

## `EASY.hpp` / `EASY.cpp`

### Class `EASY`

The class `EASY` is a derived class from `Subject`. This class does not contain any further data members.

#### Constructor / Copy Constructor / Destructor

- `EASY(std::string name)`
    - constructor of the class
    - calls the constructor of `Subject`
- The copy constructor should be deleted explicitly.
- A suitable destructor should be implemented. If the default destructor is used, this should be done explicitly.

### Methods

- `SubjectType getType() override`
    - implementation of the pure virtual methods of the base class
- `std::string calculateGrade(Student* student) override`
    - implementation of the pure virtual methods of the base class
    - takes a student and returns the grade as a string
    - see [Grading System](#grading-system) for `EASY`s

---

## `HARD.hpp` / `HARD.cpp`

### Class `HARD`

The class `HARD` is a derived class from `Subject`. This class does not contain any further data members.

#### Constructor / Copy-Constructor / Destructor

- `HARD(std::string name)`
    - constructor of the class
    - calls the constructor of `Subject`
- The Copy-Constructor should be deleted explicitly.
- A suitable Destructor should be implemented. If the default one is used, this should be done explicitly.

#### Methods

- `SubjectType getType() override`
    - implementation of the pure virtual methods of the base class
- `std::string calculateGrade(Student* student) override`
    - implementation of the pure virtual methods of the base class
    - takes a student and returns the grade as a string
    - see [Grading System](#grading-system) for `HARD`s
