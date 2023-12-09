# Post-Processing Calulator Task Document

## Overview

This document outlines the design of a prototype post-processing system focused on scalar floating-point data manipulation. Primarily aimed at laying the groundwork for more complex image processing tasks in camera software, the system is capable of parsing and evaluating arithmetic expressions involving floating-point data.

## Design

### Objectives

- To evaluate any arithmetic expression involving basic operations (+, -, *, /, %) using floating-point data.
- To allow dynamic expression input, facilitating a range of post-processing operations.
- To create a scalable and extendable framework that can later incorporate image processing functionalities.

### Input

- A scalar floating-point value (`float` or `double`), representing the variable `x` in the expression.
- A user-defined arithmetic expression, capable of including basic arithmetic operators and the variable `x`.
- Command line arguments specifying the expression, the value of `x`, and the data type (`float` or `double`).

### Output

- The result of the evaluated expression, printed to the command line as a scalar floating-point value.

### Components

#### Calculator

A templated class that:

- Parses and evaluates arithmetic expressions.
- Handles different data types (`float`, `double`) for computation.

#### Operation Classes

A series of templated classes for arithmetic operations, each derived from a base `Operation` class:

- **AddOperation**: Performs addition.
- **SubtractOperation**: Performs subtraction.
- **MultiplyOperation**: Performs multiplication.
- **DivideOperation**: Handles division, including division by zero checks.
- **ModuloOperation**: Computes the modulo

#### StringToNumber

A utility class for converting string representations of numbers to their numeric form, supporting different floating-point types.

### Workflow (main.cpp)

1. Parse command-line arguments to extract the expression, the value of `x`, and the data type.
2. Instantiate a `Calculator` object with the appropriate data type.
3. The `Calculator` parses and evaluates the expression using the provided value of `x`.
4. The result of the computation is displayed on the command line.
5. Bonus points in the doc were addressed too.

### Error Handling

- Robust handling of division by zero in the `DivideOperation` class.
- Input validation to ensure the correct format and type of command-line arguments.
- Error messages and exceptions are used to manage and report errors during expression parsing and evaluation.

### Extensibility

- The design allows for easy addition of new arithmetic operations.
- The templated approach in classes ensures compatibility with different data types.
- The system can be extended to handle more complex expressions or different types of post-processing tasks.

## Building the Prototype

### Requirements

- C++ compiler (GCC or Clang) compatible with C++17 standards.
- Standard C++ libraries.
- cmake version `3.27.7` or higher, otherwise gtest fails to build.

### Compilation Instructions

For Linux 64-bit Ubuntu ONLY:

```bash
cd path/to/calculator_task
mkdir build
cd build
cmake .. && make
```
### Runtime usage
```bash
Usage: ./calculator_task <equation> <input x value> <input data type>
Types: float or double
```

### Testing
```bash
cd build
ctest --no-compress-output -T Test
```

### Runtime instructions
```bash
cd build
./calculator_task "((x+1)*2-x/3)/x" 25.0 double
valgrind --leak-check=full ./home/u_kolacs1/host/Downloads/systems_design/build/calculator_task "((x+1)*2-x%3)/x" 25.0 double
```

### Results
* Run 1:
```bash
./calculator_task "((x+1)*2-x/3)/x" 25.0 double
You entered: 25.000000
Expression: ((x+1)*2-x/3)/x
Result: 1.746667
```

* Run 2:
```bash
./calculator_task "((x+1)*2-x/3)/x" 25.0 float 
You entered: 25.000
Expression: ((x+1)*2-x/3)/x
Result: 1.747
```

* Run 3:
```bash
./calculator_task "((x+1)*2-x/3)/x" 5.468 float
You entered: 5.468
Expression: ((x+1)*2-x/3)/x
Result: 2.032
```

* Run 4:
```bash
./calculator_task "((x+1)*2-x/3)/x" -10.2224 double
You entered: -10.222400
Expression: ((x+1)*2-x/3)/x
Result: 1.471018
```

* Run 5:
```bash
./calculator_task "((x+1)*2-x/3))))))/x" 25.0 double
You entered: 25.000000
Expression: ((x+1)*2-x/3))))))/x
Result: Error evaluating expression: Invalid expression: Unmatched parentheses
Error: Invalid expression: Unmatched parentheses
```

* Run 6:
```bash
./calculator_task "((x+1)*2-x/3)/x" 0 double
You entered: 0.000000
Expression: ((x+1)*2-x/3)/x
Result: Error evaluating expression: Division by zero.
Error: Division by zero.
```

*Note* : Ran on gdb and valgrind to ensure no runtime errors/memory leaks.
