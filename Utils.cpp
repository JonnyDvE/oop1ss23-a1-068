#include "Utils.hpp"

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
