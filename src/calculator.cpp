#include "calculator.hpp"
#include "string_to_number.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

template<typename T>
Calculator<T>::Calculator() {
    // Initialize the operations map with specific operation objects
    operations['+'] = std::make_unique<AddOperation<T>>();
    operations['-'] = std::make_unique<SubtractOperation<T>>();
    operations['*'] = std::make_unique<MultiplyOperation<T>>();
    operations['/'] = std::make_unique<DivideOperation<T>>();
    operations['%'] = std::make_unique<ModuloOperation<T>>();
}

template<typename T>
T Calculator<T>::calculate(const std::string &s, const T& xValue) {
    // Lambda function to perform calculation based on top of stack values and operator
    auto calc = [&]() {
        // Check for sufficient operands and operators
        if (nums.size() < 2 || ops.empty()) {
            throw std::runtime_error("Invalid expression: Insufficient operands or operators");
        }
        // Pop two operands and one operator to perform operation
        const T b = nums.top(); nums.pop();
        const T a = nums.top(); nums.pop();
        const char op = ops.top(); ops.pop();
        nums.push(operations[op]->execute(a, b));
    };

    try {
        for (size_t i = 0; i < s.length(); ++i) {
            const char c = s[i];
            if (std::isspace(c)) continue; // Skip whitespace

            if (std::isdigit(c) || c == '.' || c == 'x') {
                // Handle numeric values and placeholders
                if (c == 'x') {
                    nums.push(xValue); // Push 'x' value onto stack
                    continue;
                }
                size_t len;
                T num = StringToNumber<T>::convertStringToNumber(s.substr(i), len);
                i += len - 1; // Move index past the parsed number
                nums.push(num); // Push parsed number onto stack
            } else if (c == '(') {
                ops.push(c); // Push opening parenthesis onto stack
            } else if (c == ')') {
                // Resolve operations until matching '('
                while (!ops.empty() && ops.top() != '(')
                    calc();
                if (ops.empty())
                    throw std::runtime_error("Invalid expression: Unmatched parentheses");
                ops.pop(); // Pop the '('
            } else if (operations.find(c) != operations.end()) {
                // Handle operators, considering precedence
                while (!ops.empty() && precedes(ops.top(), c))
                    calc();
                ops.push(c); // Push current operator onto stack
            } else {
                throw std::runtime_error("Invalid expression: Unknown character");
            }
        }

        // Perform remaining calculations
        while (!ops.empty())
            calc();

        // Check for a single result
        if (nums.size() != 1) {
            throw std::runtime_error("Invalid expression: Unprocessed numbers");
        }

        return nums.top(); // Return the final result
    } catch (const std::exception& e) {
        std::cerr << "Error evaluating expression: " << e.what() << std::endl;
        throw;
    }
}

template<typename T>
bool Calculator<T>::precedes(const char& prev, const char& curr) {
    // Determine operator precedence
    if (prev == '(' || prev == ')') return false;
    // Lower precedence for '+' and '-' when compared to '*', '/', and '%'
    if ((curr == '*' || curr == '/' || curr == '%') && (prev == '+' || prev == '-')) return false;
    return true; // Prev has higher or equal precedence
}

// Explicit template instantiation for the types you expect to use
template class Calculator<float>;
template class Calculator<double>;
