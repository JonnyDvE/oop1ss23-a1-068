//
// Created by student on 23.03.23.
//

#include "DataBase.hpp"


DataBase::DataBase(std::string filename)
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
  return false;
}
bool DataBase::execute(Command command)
{
  return false;
}
bool DataBase::parseFile()
{
  return false;
}
DataBase::~DataBase()
{

}
bool DataBase::open()
{
  return false;
}