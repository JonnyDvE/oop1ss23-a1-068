# Assignment 1 - HOGWARTSonline

In Assignment 1 (A1) of the Design Practical (KU), you write a program to support the administration of Hogwarts School of Witchcraft and Wizardry. All students of Hogwarts have to attend several courses and receive a grade in each of them. Now it is your job, to keep track of all grades and allow professors to enter, adapt and remove grades for their students.

---

## Learning Goals

- Foundations of Classes:
  - Attributes, methods
  - Constructor, copy-constructor, destructor
- Inheritance:
  - Virtual methods
  - Abstract classes
- Strings & streams (Note: these topics are covered in the lecture on March 30):
  - `std::string`
  - Files
- Some data structures of the Standard Template Library:
  - e.g. `std::vector`, `std::map`

---

## Specification

- Publication: 23/03/2023
- Official Deadline (Soft-Deadline): 11/04/2023 at 14:00 (time valid in Austria)
- Second Chance (Hard-Deadline): 15/04/2023 at 14:00 (time valid in Austria)
- _The final submission must be done on a branch called `a1`._ (You learn, how to create and push to a branch in the KU, when the assignment is published.)
- If you submit a solution to this assignment which passes at least 50 % of the public test cases and if you signal after A1 that you want to take part in A2, then you will receive a grade for the KU OOP1; otherwise you will not receive a grade. So you definitely will not have any disadvantages if you commit and push your code often.
- **Assignment 1 is solo work!** See our [Guidelines on Plagiarism](https://tc.tugraz.at/main/mod/page/view.php?id=256924#Plagiate).
- You have to use all learning goals mentioned above in your program. (If you follow the task description closely, this criterion is automatically fulfilled.) 
- You must implement and use all described classes in your assignment. If you store the CSV file only as a two-dimensional array of strings (or in a similar way to avoid the class structure), this criterion is not fulfilled!
- The provided `main.cpp` must not be changed and is replaced with the original version in our test system. The existing functionalities in `Utils.hpp` and `Utils.cpp` should not be changed, however, you are allowed to add further methods.
- In this assignment (_but only in this one_), you do not have to check, if memory was allocated successfully. In Hogwarts, there is always enough memory. :)
- Follow all further specifications listed in the [TeachCenter](https://tc.tugraz.at/main/mod/book/view.php?id=341979&chapterid=1248).

---

## Grading

**Attention: To be able to receive a positive grade in the Design Practicals (=KU), you have to pass at least half of the publicly available test cases.**

This assignment is assessed according to the guidelines documented in the [TeachCenter](https://tc.tugraz.at/main/mod/book/view.php?id=341979&chapterid=1230). However, there are two exceptions for A1:

1. Only the _functionality_ of your submission is graded. The _coding standard_ will not be assessed.
2. There will not be any assignment interviews for A1.

---

## General Hints

- In case we need to adapt the description, the framework, or the tests, we will do so only in the [upstream repository](https://gitlab.tugraz.at/oop1_ss2023/upstream/upstream-a1), but not your personal assignment repository. This way your repository stays unaffected, however, you have the possibility to get the latest changes from the upstream repository by executing the commands:

```bash
git remote add upstream git@gitlab.tugraz.at:oop1_ss2023/upstream/upstream-a1.git
```

```bash
git pull upstream main
```

> **Note:** The first of these two commands has to be executed only once. Then, you can always update your repository by pulling from the upstream using the second command.

> **Note:** Any changes made to the upstream repository will be announced in the TeachCenter forum. Please make sure to read the forum and make sure to pull updates.

- The database is stored as a CSV file. For better readability, you may use a dedicated program to inspect the file (e.g., an editor extension) instead of using the plain text format. For VSCode / VSCodium, we recommend the extension `Rainbow CSV`. With <kbd>CTRL</kbd>+<kbd>SHIFT</kbd>+<kbd>P</kbd> you can open a command interface in VSCode. Using the command `Rainbow CSV: Set separator - Basic`, you can select the separator character which is a semicolon (`;`) in this assignment. By executing the command `Rainbow CSV: Align CSV Columns`, you get a more readable view of the file.

- Although the style is not graded in Assignment 1, it is strongly recommended to follow the coding guidelines documented [here](https://tc.tugraz.at/main/mod/book/view.php?id=341979) and [here](https://tc.tugraz.at/main/mod/book/view.php?id=341931).

- If you think that your program behaves correctly, but you encounter timeouts in any of the provided testcases, this may be caused by a lot of memory allocation. Try to use call-by-reference over call-by-value, in particular, for more complex data structures (e.g., `std::vector<std::string>`) to avoid the creation of many copies.

- This assignment comes with a [questionnaire (Fragebogen 3)](https://tc.tugraz.at/main/mod/feedback/view.php?id=349370) for you to fill out. This questionnaire is only open for a few days. So if want to help us understand our students better and improve our design practicals, please go through the rest of the assignment description and then reply to the questionnaire – it only takes ten minutes.

- One last remark before the detailed task description starts: We are currently working on a new feature for the testrunner that will give our students the opportunity to obtain test results of *private* test cases by running make test. Such a feature would still require the private test cases to be run on our test server (as it is now the case). Since our test server is not very performant (rather the opposite, unfortunately), we need to know how many test runs we can expect before upgrading our test server and then offering such a service. Therefore, in this assignment running make test will also push your current code to Gitlab. You can switch off this behavior (see the KU stream where A1 is presented), however, we *beg* you not to because we need this information to add quality of life improvements for our students as the one mentioned above.

---

## Description

### Own Data Types

It is recommended to start with the definition of the custom data types used in this program. Descriptions for all of these data types can be found in the `description` folder. In this first step, it is not required to actually implement any of the described methods in detail, but they should be declared at least. Keep in mind that all data members (member variables) of all classes should be declared as `private` (or `protected` in case of inheritance). You are allowed to add further methods to all classes. Moreover, you do not need to implement the methods exactly as they are described, if you think they do not fit well in your solution. The provided class `Utils` can be extended with methods, that are used by several of your other classes, e. g. for converting a string to lowercase. Existing methods provided in the framework must not be changed!

### CSV-File and Parsing

In order to save and load course data we make use of a CSV file. Here is a small example of such a file:

#### CSV View

```text
Name;Surname;House;Subject;Difficulty;Levitation Charm;Mandrakes
Filius;Flitwick;Ravenclaw;Charms;Hard;X;
Pomona;Sprout;Hufflepuff;Herbology;Easy;;X
Hermione;Granger;Gryffindor;;;95;90
Ginny;Weasley;Gryffindor;;;;84
Luna;Lovegood;Ravenclaw;;;94;85
```

#### Table View

|   Name   | Surname  |   House    | Subject   | Difficulty | Levitation Charm | Mandrakes |
| :------: | :------: | :--------: | --------- | ---------- | ---------------- | --------- |
|  Filius  | Flitwick | Ravenclaw  | Charms    | Hard       | X                |           |
|  Pomona  |  Sprout  | Hufflepuff | Herbology | Easy       |                  | X         |
| Hermione | Granger  | Gryffindor |           |            | 95               | 90        |
|  Ginny   | Weasley  | Gryffindor |           |            |                  | 84        |
|   Luna   | Lovegood | Ravenclaw  |           |            | 94               | 85        |

#### Description

The following list describes the individual parts of the CSV file:

- The cells of a row are separated by semicolons (`;`). Each row has the same number of columns.
- The header row in the CSV file always comprises the column headers `Name`, `Surname`, `House`, `Subject`, and `Difficulty`. They are followed by the names of all assignments which are column headers as well. Each column header is a cell, hence they are separated by a semicolon.
- Valid houses are `Gryffindor`, `Hufflepuff`, `Ravenclaw` or `Slytherin`; see [`description/Persons.md`](description/Persons.md#enum-house) for more information. Houses are always stored case-sensitive.
- After the header row, all professors are listed. Each professor has a `Name`, `Surname`, and a `House`. Furthermore, a professors teaches a `Subject`, which has a `Difficulty`. Valid difficulty levels are `Easy` and `Hard`; see [`description/Subjects.md`](description/Subjects.md) for more information. In the remaining columns, the assignments that are taught by this professor (and therefore are worked on in the professor's `Subject`) are marked with a cross (`X`). All other cells are empty.
- The list of the professors is followed by a list of students. Each student has a `Name`, `Surname`, and a `House`. The columns `Subject` and `Difficulty` are empty for students. In each remaining column the student's achieved points in the respective assignment are stored. Valid points are integers from `0` to `100`, however a cell is empty, if the student does not have a grading for that assignment yet.
- There is no restriction on the number of assignments, professors and students. In particular, a CSV file is also valid if it does not contain any professors, students or assignments. However, you may assume that each subject has at least one assignment.

You can assume that the CSV files provided in the test cases are 'well-formed', that is, all the points above are fulfilled. However, you have to check the following cases:

- Each assignment must have a unique name. Spaces may be included in their names.
- Each subject must have a unique name. Spaces may be included in their names.
- Each person (!) must have a unique name (i.e., a unique combination of name and surname). You can assume that name and surname of a person do not contain any whitespace characters.
- Each professor teaches exactly one subject and each subject is taught by exactly one professor.
- Each assignment is carried out in exactly one subject.

If parsing the file fails, HOGWARTSonline terminates (done in `main.cpp`).

#### Parsing

On startup, HOGWARTSonline first parses the CSV file. It is important to keep track of the sorting (top to bottom, left to right). This is needed to ensure that your outputs match our test cases. By appending rows and columns to a suitable data structure, the sorting can easily be preserved.

### Login

Once the CSV file was parsed successfully, HOGWARTSonline greets its user kindly (done in `main.cpp`) and asks for the user's username (which should be implemented in the `login` method of `CommandLine`):

```
Enter your username:\n
 > 
```

> Note the leading and trailing spaces! You can make it visible by selecting the textfield.

The username consists of name and surname of the respective user, separated by a space. In the `login` method of [`DataBase`](description/DataBase.md#methods), the program checks whether the entered username corresponds to a person in the database. This check is performed in a case-sensitive way. If the entered username corresponds to a person in the database, the user is logged in successfully and a message is displayed by the `main`-function, otherwise, the program terminates (also done in `main.cpp`).

### Input of Commands

After logging in, the user can enter commands. In the first column of the table below, you can find a list of all possible commands.

| Command                               | Parameters | Student | Professor (normal mode) | Professor (modification mode) |
|---------------------------------------| :--------: | :-----: | :---------------------: | :---------------------------: |
| SHOW                                  |     0      |    X    |            X            |               -               |
| ADDSTUDENT <name> <surname> <house>   |     3      |    -    |            X            |               -               |
| MODIFYSTUDENT <name> <surname>        |     2      |    -    |            X            |               -               |
| ADDGRADE <assignment name> <points>   |     2+     |    -    |            -            |               X               |
| REMOVEGRADE <assignment name>         |     1+     |    -    |            -            |               X               |
| BACK                                  |     0      |    -    |            -            |               X               |
| SAVE <filename>                       |     1      |    -    |            X            |               -               |
| QUIT                                  |     0      |    X    |            X            |               X               |

In HOGWARTSonline, different users have different permissions. Whether a command is executable or not, depends on the user level (_student_ vs. _professor_) of the current user as well as the current mode (_normal_ vs. _modification mode_). A cross (`X`) in the table above indicates that a user (indicated by the corresponding column header) has the permission to execute a command (indicated by the first cell of the corresponding row). Note that there are two columns for professors, specifying which commands are allowed in which mode of the program.

Using the command `MODIFYSTUDENT`, a professor can enter the modification mode with a selected student. With `ADDGRADE` and `REMOVEGRADE` the points / grades of this pre-selected student are modified. With `BACK`, the program switches back to normal mode. Every time a professor logs into HOGWARTSonline, the program starts in normal mode.

Once a user is logged in, the prompt

```
 > 
```

is shown and the user can type commands.

> **Note:** Mind the leading and trailing space!

If the user's input is empty or consists of whitespace only, it is ignored and the prompt is printed again.

> **Hint:** We only test for spaces as whitespace.

Assuming the user entered at least one non-whitespace character, the input is split into words based on the whitespace, e.g. `modifystudent Harry    Potter ` splits into `modifystudent`, `Harry` and `Potter`. The first word determines the command type and all remaining words represent the command's parameters. If the command type provided by the user does not match any valid command type (first column in the table above) or the number of parameters is wrong (second column in the table above), the error message

```
[ERROR] Invalid command or invalid number of parameters!\n
```

is displayed and the prompt is printed again. The command itself is case-insensitive, whereas all parameters are case-sensitive.

If a student is logged-in, and they try to enter a command, that can only be used by a professor, the error message

```
[ERROR] As a student, you are not allowed to do this!\n
```

is displayed and the prompt is printed again.

If a professor tries to enter a command in normal mode, that can only be accessed in modification mode, the error message

```
[ERROR] You can only do this in modification mode!\n
```

is displayed and the prompt is printed again. Vice Versa, the error message

```
[ERROR] You cannot do this in modification mode!\n
```

is shown, if the command requires a professor to be in normal mode but the modification mode is active.

#### Command: SHOW

This command takes no parameters and can be used by students and by professors in normal mode.

For a student, this command prints an overview of all grades, that the student has received so far. It is displayed in the following format:

```
\n
Student: <name> <surname>, <house>\n
  Subject: <name of subject> - <grade>\n
    <name of assignment> - <points>\n
    <name of assignment> - <points>\n
    ...
    <name of assignment> - <points>\n
\n
  Subject: <name of subject> - <grade>\n
    <name of assignment> - <points>\n
    <name of assignment> - <points>\n
    ...
    <name of assignment> - <points>\n
\n
  ...
\n
  Subject: <name of subject> - <grade>\n
    <name of assignment> - <points>\n
    <name of assignment> - <points>\n
    ...
    <name of assignment> - <points>\n
\n
```

`<name>`, `<surname>`, and `<house>` are to be substituted with the name, surname, and house affiliation of the logged-in student. The subjects and assignments are listed in the order they appear in the underlying CSV file. The listing always includes all subjects and assignments, no matter if the student has received a grading or not. Of course, the `<name ...>` placeholders are substituted with the names of the subjects and assignments. The grades are calculated and printed as described [below](#grading-system). The placeholder `<points>` is replaced by the points, the student has received for the assignment (an integer from `0` to `100`). If a student has not received a grading for an assignment yet, the string `NO POINTS AVAILABLE` is printed instead. The three dots (`...`) only serve as placeholders (for assignments or subjects) and should not be part of your output. The `\n` in the example output above and below stands for a newline character (and not the two characters `\` and `n`).

For a professor, the `SHOW` command prints an overview of all grades, that their students have received in their subject so far. It is displayed in the following format:

```
\n
Professor: <name> <surname>\n
Subject: <name of subject>\n
\n
  Student: <student name> <student surname> - <grade>\n
    <name of assignment> - <points>\n
    <name of assignment> - <points>\n
    ...
    <name of assignment> - <points>\n
\n
  Student: <student name> <student surname> - <grade>\n
    <name of assignment> - <points>\n
    <name of assignment> - <points>\n
    ...
    <name of assignment> - <points>\n
\n
  ...
\n
  Student: <student name> <student surname> - <grade>\n
    <name of assignment> - <points>\n
    <name of assignment> - <points>\n
    ...
    <name of assignment> - <points>\n
\n
```

`<name>` and `<surname>` are to be substituted with the name and surname of the logged-in professor. The students and assignments are listed in the order they appear in the underlying CSV file. The listing always includes all students and assignments, not matter if the student has received a grading or not. Of course, the `<name ...>` placeholders are substituted with the names of the students and assignments. The grades are calculated and printed as described [below](#grading-system). The placeholder `<points>` is replaced by the points, the student has received for the assignment (an integer from `0` to `100`). If a student has not received a grading for an assignment yet, the string `NO POINTS AVAILABLE` is printed instead. Again, the three dots (`...`) only serve as placeholders (representing assignments or students).

##### Grading System

In Hogwarts, there exist the following grades:

| Passing Grades       | Percentage |
|----------------------|:----------:|
| Outstanding          |  100 - 85  |
| Exceeds Expectations |  84 - 68   |
| Acceptable           |  67 - 51   |

| Failing Grades | Percentage |
|----------------|:----------:|
| Poor           |  50 - 34   |
| Dreadful       |  33 - 17   |
| Troll          |   16 - 0   |

In general, the subjects are divided into `EASY`s and `HARD`s.

For easy ones, the grade is computed by taking the integer part of the mean of all assignment.

> **Example:** Assignment 1: 50, Assignment 2: 51 -> Mean: 50.5 -> Integer Part of Mean: 50 -> Grade: Poor.

For hard subjects, the grade is computed by taking the worst number of points among all assignments.

> **Example:** Assignment 1: 34, Assignment 2: 61 -> Resulting points: 34 -> Grade: Poor.

Based on these rules a grade can be calculated for a student in a subject. In the output of the command `SHOW`, the placeholder `<grade>` is replaced by the calculated grade. However, if a student has not received a grading of at least one assignment yet, the whole subject cannot be graded and its `<grade>` placeholder is substituted with `NO GRADE AVAILABLE`.

#### Command: ADDSTUDENT

This command takes exactly three parameters and can be used only by professors in normal mode. It adds a student to the database. The first two parameters contain the name and surname, respectively. The name and surname of the student are stored in a case-sensitive way. (This means, for instance, that both capital letters in the surname of the new student Cormac McLaggen are stored in the database.) If there already exists a person with the same name in the database, the error message

```
[ERROR] This user already exists!\n
```

is shown. The third parameter contains the house of the student, again case-sensitive. If the house is neither `Gryffindor`, `Hufflepuff`, `Ravenclaw` nor `Slytherin`, you should output the error message:

```
[ERROR] Invalid house!\n
```

If no error occurs, the student is inserted at the end of the database and the message

```
Successfully added student: <name> <surname>\n
```

is displayed.

#### Command: MODIFYSTUDENT

This command takes exactly two parameters and can be used only by professors in normal mode. The first two parameters contain the name and surname of a student, respectively. These names are treated in a case-sensitive way. If no such student exists in the database, the error message

```
[ERROR] This student does not exist!\n
```

is shown. Otherwise, the program switches to the modification mode with the chosen student selected. This means that all further commands will be executed based on this student until the `BACK` command is entered. If no error was encountered, the `MODIFYSTUDENT` command prints the following message:

```
Now modifying student: <name> <surname>\n
```

#### Command: ADDGRADE

This command takes at least two parameters and can be used only by professors in modification mode. Thus, a student was already selected in a preceding `MODIFYSTUDENT` command. All parameters, except for the last one, form the name of an assignment (case-sensitive). (The name might be split into multiple parameters, as it may contain spaces.) If no assignment with that name exists or the currently logged-in professor does not teach the subject where the assignment is conducted, the error message

```
[ERROR] Grade cannot be entered!\n
```

is shown. The last parameter contains the number of points reached in the assignment.

> **Hint:** Use the function provided in `Utils` to convert the string into an integer.

If the last parameter does not contain an integer from `0` to `100`, the error message

```
[ERROR] Invalid grade!\n
```

is displayed. If no error occurs, the points of the selected student are changed to the inserted number for the assignment specified by the command's parameters and the message

```
Grade was entered successfully!\n
```

is shown. Note that the number of points provided by the user is inserted regardless of whether a value was already present. This means that points may be overwritten by this command. After the execution of the `ADDGRADE` command, the program stays in modification mode with the same student selected as before.

#### Command: REMOVEGRADE

This command takes at least one parameter and can only be used by professors in modification mode. Thus, a student was already selected in a preceding `MODIFYSTUDENT` command. The parameters form the name of an assignment (case-sensitive). (The name might be split among several parameters, as it may contain spaces.) If

- no assignment with that name exists,
- the currently logged-in professor does not teach the subject where the assignment is carried out or
- the student does not have a grading yet,

the error message

```
[ERROR] Grade cannot be removed!\n
```

is shown. Otherwise, the student's points in the assignment specified by the user are removed and the message

```
Grade was removed successfully!\n
```

is shown. After the execution of the `REMOVEGRADE` command, the program stays in modification mode with the same student selected as before.

#### Command: BACK

This command does not take any parameters and can only be used by professors in modification mode. Upon execution of this command, the program switches back to normal mode. That is, all further commands will not be based on a specific student, until the professor switches back to modification mode using the `MODIFYSTUDENT` command.

#### Command: SAVE

This command takes exactly one parameter and can only be used by professors in normal mode. The parameter contains the name of the file, in which the current state of the database should be saved.
In case the file cannot be opened (for writing), the error message

```
[ERROR] File cannot be opened!\n
```

is shown.
If the file is successfully opened, the database is written to that file, according to the description of the CSV file format shown in the [CSV-File and Parsing](#csv-file-and-parsing) section. Then, the file is closed and the message

```
File saved successfully!\n
```

is shown.

> **Hint:** You may wonder, in which order you should store the assignments. For all test cases, you can assume that iteration over all subjects and within each subject iteration over all assignments gives you the correct order (given that you store the subjects and assignments in the same order as they appear in the CSV file).

#### Command: QUIT

This command does not take any parameters. It can be used by students and professors in all modes. With this command, the program terminates with a log-out message (done in `main.cpp`).
