# Assignment

In this part of the description, you can find the details about the `Assignment` class which represents assignments of HOGWARTSonline. This class is responsible for storing the points of all students on the corresponding assignment.

## `Assignment.hpp` / `Assignment.cpp`

### Class `Assignment`

#### Data Members (Member Variables)

- `name_`
    - stores the name of the assignment as `std::string`
- `points_`
    - stores the points reached by the students of this assignment as `std::map<Student*, unsigned>`
    - If a student has not received a grading for the assignment yet, do not add the student to the map.

#### Constructor / Copy Constructor / Destructor

- `Assignment(std::string name)`
    - constructor of the class
    - initialises all data members accordingly
- The copy constructor should be deleted explicitly.
- A suitable destructor should be implemented. If the default destructor is used, this should be done explicitly.

#### Methods

- getter / setter / further methods as needed

> Hint: You may write methods to insert and remove students and their points in / from the map.
