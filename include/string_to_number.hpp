#pragma once

#include <string>

/// @brief A template class to convert a string to a numeric value.
/// This class provides a static method to convert a given string
/// to a specified numeric type (float, double).
/// @tparam T The numeric type to which the string will be converted.
template<typename T>
class StringToNumber {
public:
    /// @brief Converts a string to a numeric value of type T.
    /// Parses the input string and converts it to a numeric value of type T.
    /// The function returns the converted number and updates the parsedLength
    /// to indicate how much of the string was used for the conversion.
    /// @param str The string to be converted to a number.
    /// @param parsedLength A reference to a size_t variable that will be updated
    /// with the number of characters processed in the string.
    /// @return The numeric value of type T extracted from the string.
    static T convertStringToNumber(const std::string& str, size_t& parsedLength);
};

// Specialization declarations for float and double

/// @brief Specialization of convertStringToNumber for the float type.
/// @param str The string to be converted to a float.
/// @param parsedLength A reference to a size_t variable that will be updated
/// with the number of characters processed in the string.
/// @return The float value extracted from the string.
template<>
float StringToNumber<float>::convertStringToNumber(const std::string& str, size_t& parsedLength);

/// @brief Specialization of convertStringToNumber for the double type..
/// @param str The string to be converted to a double.
/// @param parsedLength A reference to a size_t variable that will be updated
/// with the number of characters processed in the string.
/// @return The double value extracted from the string.
template<>
double StringToNumber<double>::convertStringToNumber(const std::string& str, size_t& parsedLength);
