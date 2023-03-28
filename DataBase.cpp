//
// Created by student on 23.03.23.
//

#include "DataBase.hpp"
#include "Utils.hpp"
#include <iostream>
#include <sstream>
#include <utility>

const std::string ERROR_CODES[]{"[ERROR] Invalid command or invalid number of parameters!",
                  "[ERROR] As a student, you are not allowed to do this!",
                  "[ERROR] You can only do this in modification mode!",
                  "[ERROR] You cannot do this in modification mode!",
                  "[ERROR] This user already exists!",
                  "[ERROR] Invalid house!",
                  "[ERROR] This student does not exist!",
                  "[ERROR] Grade cannot be entered!",
                  "[ERROR] Invalid grade!",
                  "[ERROR] Grade cannot be removed!",
                  "[ERROR] File cannot be opened!"};
enum ERROR_CODE{INVALID, STUDENT, ONLYMOD, NOTMOD, USEREXISTS, INVALIDHOUSE, USERNOEXISTS, CANTGRADE, INVALIDGRADE,
  CANTREMOVE, CANTOPENFILE};

DataBase::DataBase(const std::string& filename)
{
    file_.open(filename, std::ifstream::in);
    active_user_ = nullptr;
}
PersonType DataBase::getUserLevel()
{
  return active_user_->getType();
}
bool DataBase::login(std::string username)
{
  std::vector<std::string> vector;
  Utils::stringToVector(std::move(username), vector, ' ');
  if (vector.size() == 2)
  {
    active_user_ = isInDatabase(vector.at(0), vector.at(1));
    if(active_user_ != nullptr)
      return true;
  }
  return false;
}
bool DataBase::execute(const Command& command)
{
  switch (command.getType())
  {
    case CommandType::SHOW:
      show();
      return false;
    case CommandType::INVALID:
      break;
    case CommandType::ADDSTUDENT:
      addStudent(command.getParameters());
      return false;
    case CommandType::MODIFYSTUDENT:
      return modifyStudent(command.getParameters());
    case CommandType::ADDGRADE:
      addGrade(command.getParameters());
      return true;
    case CommandType::REMOVEGRADE:
      removeGrade(command.getParameters());
    return true;
    case CommandType::BACK:
      back();
    return false;
    case CommandType::SAVE:
      save(command.getParameters());
      return false;
    case CommandType::QUIT:

      break;
  }

  return false;
}
bool DataBase::parseFile()
{
  std::string line;
  std::getline(file_, line);
  std::vector<std::string> vectorisedLine;
  std::vector<Assignment*> assignments;
  Utils::stringToVector(line, vectorisedLine, ';');
  std::vector<std::string> vectorisedAssignments(vectorisedLine.begin() + 5, vectorisedLine.end());
  for (auto &word : vectorisedAssignments)
  {
    for (auto &assignment : assignments)
    {
      if(assignment->getName() == word)
        return false;
    }
    assignments.push_back(new Assignment(word));
  }
  while(!line.empty())
  {
    vectorisedLine.clear();
    std::getline(file_, line);
    if(line.empty())
      break ;
    Utils::stringToVector(line, vectorisedLine, ';');
    std::string name = vectorisedLine.at(0);
    std::string surname = vectorisedLine.at(1);
    House house = Person::getHouse(vectorisedLine.at(2));

    if(isInDatabase(name, surname) != nullptr)
      return false;
    if(subjectInData(vectorisedLine.at(3)) != nullptr)
      return false;
    if(vectorisedLine.at(3).empty() && vectorisedLine.at(4).empty())
    {
      auto * student = new Student(name, surname, house);
      students_.push_back(student);
      std::vector<std::string>points (vectorisedLine.begin() + 5, vectorisedLine.end());
      size_t assignment_count = 0;
      unsigned point_in_unsigned;
      for(auto &point : points)
      {
        Utils::decimalStringToInt(point, point_in_unsigned);
        if(!point.empty())
          assignments.at(assignment_count)->addGrade(student, point_in_unsigned);
        assignment_count++;
      }
    }
    else
    {
      if (vectorisedLine.at(3).empty())
        return false;
      auto * subject = new Subject(vectorisedLine.at(3), vectorisedLine.at(4) == "Hard");
      auto * professor = new Professor(name, surname, house, subject);
      professors_.push_back(professor);
      subjects_.push_back(subject);
      auto counter = -5;
      for (const auto& string : vectorisedLine)
      {
        if(string == "X")
        {
          for(auto &subs : subjects_)
          {
            for (auto &assigned_before : subs->getAssignments())
            {
              if(assigned_before == assignments.at(counter))
              {

                return false;
              }

            }
          }
          subject->addAssignments(assignments.at(counter));
        }
        counter++;
      }
    }
  }
  return true;
}
DataBase::~DataBase()
{
  for (auto studs :students_)
  {
    delete studs;
  }
  for(auto profs : professors_)
  {
    delete profs;
  }
}
bool DataBase::open()
{
  return file_.is_open();
}
Person* DataBase::isInDatabase(const std::string& name, const std::string& surname)
{
  for(auto &prof : professors_)
  {
    if(prof->getName() == name && prof->getSurname() == surname)
      return prof ;
  }
  for(auto &student : students_)
  {
    if(student->getName() == name && student->getSurname() == surname)
      return student ;
  }
  return nullptr;
}
void DataBase::show()
{
  std::cout << std::endl;
  if(active_user_->getType() == PersonType::Professor)
  {
    auto * professor = dynamic_cast<Professor*>(active_user_);
    std::cout << "Professor: " << active_user_->getFullName() << std::endl;
    std::cout << "Subject: " << professor->getSubject()->getName() << std::endl;
    for (auto student : students_)
    {
      std::cout << std::endl;
      std::cout << "  Student: " << student->getFullName() << " - " << professor->getSubject()->calculateGrade(student)
                << std::endl;
      for(auto assignment : professor->getSubject()->getAssignments())
      {
        std::cout << "    " << assignment->getName() << " - " << assignment->getGrade(student) << std::endl;
      }
    }
    std::cout << std::endl;
  }
  else
  {
    auto * student = dynamic_cast<Student*>(active_user_);
    std::cout << "Student: " << active_user_->getFullName() << std::endl;
    for (auto subjects : subjects_)
    {
      std::cout << "  Subject: " << subjects->getName() << " - " << subjects->calculateGrade(student) << std::endl;
      for (auto assignment : subjects->getAssignments())
      {
        std::cout << "    " << assignment->getName() << " - " << assignment->getGrade(student) << std::endl;
      }
      std::cout << std::endl;
    }
  }
}
void DataBase::addStudent(std::vector<std::string> args)
{
  if(isInDatabase(args[0], args[1]) != nullptr)
  {
    std::cout << ERROR_CODES[USEREXISTS] << std::endl;
    return;
  }
  if(Person::getHouse(args[2]) == House::Invalid)
  {
    std::cout << ERROR_CODES[INVALIDHOUSE] << std::endl;
    return;
  }
  students_.push_back(new Student(args[0], args[1],Person::getHouse(args[2])));
  std::cout << "Successfully added student: " << students_.at(students_.size() - 1)->getFullName() << std::endl;
}
bool DataBase::modifyStudent(std::vector<std::string> args)
{
  student_in_editing = dynamic_cast<Student*>(isInDatabase(args[0], args[1]));
  if(student_in_editing == nullptr)
  {
    std::cout << ERROR_CODES[USERNOEXISTS] << std::endl;
    return false;
  }
  std::cout << "Now modifying student: " << student_in_editing->getFullName() << std::endl;
  return true;
}
void DataBase::addGrade(std::vector<std::string> args)
{
  std::string name = parseSubject(std::vector<std::string>(args.begin(), args.end() -1));
  name.pop_back();
  for(auto &subject : subjects_)
  {
    for (auto &assignment : subject->getAssignments())
    {
      if(assignment->getName() == name && dynamic_cast<Professor*>(active_user_)->getSubject() == subject)
      {
        unsigned grade;
        if(Utils::decimalStringToInt(args.at(args.size()-1), grade) && grade <= 100 && grade >= 0)
        {
          assignment->changeGrade(student_in_editing, grade);
          std::cout << "Grade was entered successfully!" << std::endl;
          return ;
        }
        else
        {
          std::cout << ERROR_CODES[INVALIDGRADE] << std::endl;
          return;
        }
      }
    }
  }
  std::cout << ERROR_CODES[CANTGRADE] << std::endl;
}
std::string DataBase::parseSubject(std::vector<std::string> vector)
{
  std::stringstream ss;
  for(auto &string : vector)
  {
    ss << string << " ";
  }
  return ss.str();
}
void DataBase::removeGrade(std::vector<std::string> args)
{
  std::string name = parseSubject(std::vector<std::string>(args.begin(), args.end()));
  name.pop_back();
  for(auto &subject : subjects_)
  {
    for (auto &assignment : subject->getAssignments())
    {
      if(assignment->getName() == name && dynamic_cast<Professor*>(active_user_)->getSubject() == subject)
      {
        if(assignment->getGradeAsInt(student_in_editing) != -1)
        {
          assignment->removeGrade(student_in_editing);
          std::cout << "Grade was removed successfully!" << std::endl;
          return;
        }
      }
    }
  }
  std::cout << ERROR_CODES[CANTREMOVE] << std::endl;
}
void DataBase::back()
{
  student_in_editing = nullptr;
}
void DataBase::save(std::vector<std::string> args)
{
  std::ofstream output(args.at(0));
  if(output.is_open())
  {
    output << firstLineBuilder() << std::endl;
    for (auto prof : professors_)
    {
      output << professorLineBuilder(prof) << std::endl;
    }
    for (auto stud : students_)
    {
      output << studentLineBuilder(stud) << std::endl;
    }
    output.close();
    std::cout << "File saved successfully!" << std::endl;
    return ;
  }
    std::cout << ERROR_CODES[CANTOPENFILE] << std::endl;

}
std::string DataBase::firstLineBuilder()
{
  std::stringstream ss;
  ss << "Name;Surname;House;Subject;Difficulty;";
  for (auto subjects : subjects_)
  {
    for (auto assignments : subjects->getAssignments())
    {
      ss << assignments->getName() << ";";
    }
  }
  std::string output = ss.str();
  output.pop_back();
  return output;
}
std::string DataBase::professorLineBuilder(Professor* professor)
{
  std::stringstream ss;
  ss << professor->getName() << ";" << professor->getSurname() << ";" << professor->getHouseString(professor->getHouse())
     << ";";
  ss << professor->getSubject()->getName() << ";" << professor->getSubject()->difType() << ";";
  for (auto subjects : subjects_)
  {
    for ([[maybe_unused]] auto assignments : subjects->getAssignments())
    {
      if(professor->getSubject() == subjects)
      {
        ss << "X";
      }
      ss << ";";
    }
  }
  std::string output = ss.str();
  output.pop_back();
  return  output;
}
std::string DataBase::studentLineBuilder(Student* student)
{
  std::stringstream ss;
  ss << student->getName() << ";" << student->getSurname() << ";" << student->getHouseString(student->getHouse())
     << ";;;";

  for (auto subjects : subjects_)
  {
    for (auto assignments : subjects->getAssignments())
    {
      if(assignments->getGradeAsInt(student) >= 0)
      {
        ss << assignments->getGradeAsInt(student);
      }
      ss << ";";
    }
  }
  std::string output = ss.str();
  output.pop_back();
  return  output;
}
Subject* DataBase::subjectInData(std::string name)
{
  for(auto &subjects: subjects_)
  {
    if(subjects->getName() == name)
      return subjects;
  }
  return nullptr;
}

