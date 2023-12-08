#include "calculator.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

/// Executes the calculation based on the provided expression and input value.
/// The function handles both float and double types as specified by the template parameter.
template<typename T>
void executeCalculation(const std::string& expression, std::istringstream& iss) {
    T x;
    if (!(iss >> x)) {
        std::cerr << "Invalid number. Please provide a valid number." << std::endl;
        throw std::runtime_error("Invalid number");
    }

    const int precision = std::is_same<T, float>::value ? 3 : 6;
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "You entered: " << x << std::endl;
    std::cout << "Expression: " << expression << std::endl;

    Calculator<T> calc;
    try {
        std::cout << "Result: " << calc.calculate(expression, x) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

/// The main entry point of the application.
/// This main function parses the command line arguments to determine the
/// expression to calculate, the input value, and its type.
/// Returns 0 on successful execution, 1 on error.
int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <equation> <input x value> <input data type>" << std::endl;
        std::cerr << "Types: float, double" << std::endl;
        return 1;
    }

    const std::string expression = argv[1];
    const std::string type = argv[3];
    std::istringstream iss(argv[2]);

    /// Calculations with either float or double types.
    try {
        if (type == "float") {
            executeCalculation<float>(expression, iss);
        } else if (type == "double") {
            executeCalculation<double>(expression, iss);
        } else {
            std::cerr << "Invalid input type. Please specify 'float' or 'double'." << std::endl;
            return 1;
        }
    } catch (const std::exception& e) {
        return 1;
    }

    return 0;
}
