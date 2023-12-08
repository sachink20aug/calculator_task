#pragma once

#include "operation.hpp"

#include <memory>
#include <stack>
#include <string>
#include <unordered_map>

/// @brief The Calculator class template for performing arithmetic calculations.
/// This class provides functionality to calculate arithmetic expressions
/// based on the operations defined in the Operation class template.
/// It supports custom data types as specified by the template parameter.
/// @tparam T The data type for the calculation (float, double).
template<typename T>
class Calculator {
public:
    /// @brief Constructor for the Calculator class.
    /// Initializes the calculator with necessary data structures and
    /// prepares it for calculation.
    Calculator();

    /// @brief Calculates the result of an arithmetic expression.
    /// Parses the provided string as an arithmetic expression and computes its result.
    /// The expression can contain basic arithmetic operators and is evaluated using the
    /// standard rules of precedence.
    /// @param s The string representing the arithmetic expression to be calculated.
    /// @param x A value of type T that can be used in the expression.
    /// @return The result of the calculation as a value of type T.
    T calculate(const std::string &s, const T& x);

private:
    std::unordered_map<char, std::unique_ptr<Operation<T>>> operations; ///< Stores the available arithmetic operations.
    std::stack<T> nums; ///< A stack used to store numbers during the calculation process.
    std::stack<char> ops; ///< A stack used to store operators during the calculation process.

    /// @brief Determines the precedence of arithmetic operators.
    /// Compares the precedence of two operators and returns true if the
    /// first operator has higher or equal precedence as compared to the second.
    /// @param prev The previous operator in the expression.
    /// @param curr The current operator in the expression.
    /// @return True if 'prev' has higher or equal precedence than 'curr', false otherwise.
    bool precedes(const char& prev, const char& curr);
};
