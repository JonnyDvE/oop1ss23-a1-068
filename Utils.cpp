#include "Utils.hpp"
#include <iostream>

//----------------------------------------------------------------------------------------------------------------------
bool Utils::decimalStringToInt(const std::string& str, unsigned& number)
{
  size_t position = 0;

  try
  {
    number = std::stoul(str, &position, 10);
  }
  catch (std::exception&)
  {
    return false;
  }

  return position == str.length();
}
void Utils::stringToVector(std::string string, std::vector<std::string>& vector, char delimiter)
{
  size_t position = 0;
  size_t position2;
  std::string split_word;
  while((position2 = string.find(delimiter, position)) != std::string::npos)
  {
    split_word = string.substr(position, position2 - position);
    position = position2 + 1;
    vector.push_back(split_word);
  }
  vector.push_back(string.substr(position));
}
void Utils::stringToUpperCase(std::string& string)
{
  for (auto &ch : string)
  {
    if(ch >= 97 && ch <= 122)
    {
      ch = ch - 32;
    }
  }
}
