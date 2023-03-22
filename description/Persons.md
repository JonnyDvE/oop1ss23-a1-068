# Person / Student / Professor

Students, professors, and persons in general, are represented by the classes `Student`, `Professor`, and `Person`, respectively. This document describes these classes and related enumeration data types in detail.

## `Person.hpp` / `Person.cpp`

#### Enum (class) `PersonType`

In the program, we distinguish `Student`s and `Professor`s. In order to do so, you implement an enum (class) `PersonType`.

### Enum (class) `House`

Hogwarts School of Witchcraft and Wizardry is divided into four Houses, `Gryffindor`, `Hufflepuff`, `Ravenclaw` and `Slytherin`. These departments should be represented by the enum (class) `House` in your program.

> Hint: It is preferable to use strongly typed enum classes instead of ordinary enums.

### Class `Person`

The class `Person` serves as the base class for students and professors. Since only students and professors use HOGWARTSonline (and no other `Person`s), this class should be implemented as an abstract class.

#### Data members (member variables)

- `name_`
  - stores the first name as an `std::string`
- `surname_`
  - stores the surname as an `std::string`
- `house_`
  - stores the affiliation with a house as an instance of enum (class) `House`

#### Constructor / Copy Constructor / Destructor

- `Person(std::string name, std::string surname, House house)`
  - constructor of the class
  - initialises all data members accordingly
  - **If you prefer to pass a `std::string` for the house and do the conversion in the constructor, feel free to do so. Just do not forget, to adapt the constructors of the derived classes as well.**
- The copy constructor should be deleted explicitly.
- A suitable destructor should be implemented. If the default destructor is used, this should be done explicitly.

> Hint: Take a close look at how to declare the destructor in a base class.

#### Methods

- `PersonType getType()`
    - pure virtual method, which is implemented in derived classes
- getter / setter / further methods as needed

You may have noticed that there is no member related to a person's gender. That's because the OOP1 team does not want HOGWARTSonline to be abused to discriminate people based on their gender. All people are equally valuable :rainbow:

---

## `Student.hpp` / `Student.cpp`

### Class `Student`

The class `Student` is derived from `Person`. This class does not contain any further data members.

#### Constructor / Copy-Constructor / Destructor

- `Student(std::string name, std::string surname, House house)`
  - constructor of the class
  - calls the constructor of `Person`
- The copy constructor should be deleted explicitly.
- A suitable destructor should be implemented. If the default destructor is used, this should be done explicitly.

#### Methods

- `PersonType getType() override`
  - implementation of the pure virtual method of the base class
- getter / setter / further methods as needed

---

## `Professor.hpp` / `Professor.cpp`

### Class `Professor`

The class `Professor` is derived from `Person`.

#### Data members (member variables)

- `subject_`
    - stores the class taught by a professor as `Subject*`

#### Constructor / Copy-Constructor / Destructor

- `Professor(std::string name, std::string surname, House house, Subject* subject)`
    - constructor of the class
    - calls the constructor of `Person`
    - initialises the data member `subject_`
- The copy constructor should be deleted explicitly.
- A suitable destructor should be implemented. If the default destructor is used, this should be done explicitly.

#### Methods

- `PersonType getType() override`
  - implementation of the pure virtual method of the base class
- getter / setter / further methods as needed
