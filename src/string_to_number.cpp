#include "string_to_number.hpp"

#include <stdexcept>

// Template function definition
template<typename T>
T StringToNumber<T>::convertStringToNumber(const std::string& str, size_t& len) {
    // Generic implementation (if possible) or throw an error
    throw std::logic_error("Not implemented for this type");
}

// Specializations
// Specialization for float
template<>
float StringToNumber<float>::convertStringToNumber(const std::string& str, size_t& parsedLength) {
    try {
        const float value = std::stof(str, &parsedLength);
        return value;
    } catch (const std::invalid_argument& ia) {
        throw std::runtime_error("Invalid argument for conversion to float: " + str);
    } catch (const std::out_of_range& oor) {
        throw std::runtime_error("Out of range for conversion to float: " + str);
    }
}

// Specialization for double
template<>
double StringToNumber<double>::convertStringToNumber(const std::string& str, size_t& parsedLength) {
    try {
        const double value = std::stod(str, &parsedLength);
        return value;
    } catch (const std::invalid_argument& ia) {
        throw std::runtime_error("Invalid argument for conversion to double: " + str);
    } catch (const std::out_of_range& oor) {
        throw std::runtime_error("Out of range for conversion to double: " + str);
    }
}

// Explicit template instantiations
template class StringToNumber<float>;
template class StringToNumber<double>;