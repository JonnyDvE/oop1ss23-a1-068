#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

class Utils
{
  public:
    //------------------------------------------------------------------------------------------------------------------
    // Constructor, Copy-Constructor and Destructor are deleted, as this class should never be instantiated.
    //
    Utils() = delete;
    Utils(const Utils&) = delete;
    ~Utils() = delete;

    //------------------------------------------------------------------------------------------------------------------
    // This function converts a string into an unsigned integer. The conversion is only successful, if all
    // elements of the string are converted.
    //
    // @param str - string that should be converted
    // @param number - the converted number
    // @return true, if conversion was successful, false otherwise
    //
    static bool decimalStringToInt(const std::string& str, unsigned& number);
    static void stringToVector(const std::string& string, std::vector<std::string>& vector, char delimiter);
    static void stringToUpperCase(std::string& string);
    static std::string removeLeadingWhitespace(std::string& string);
    static enum ERROR();
};

#endif // UTILS_HPP
