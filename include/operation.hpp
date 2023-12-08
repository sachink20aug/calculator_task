#pragma once

/// @brief Template abstract base class for arithmetic operations.
/// 
/// This is an abstract base class for different arithmetic operations.
/// It defines a virtual execute method that derived classes must implement.
///
/// @tparam T The data type for the operation (e.g., float, double).
template <typename T>
class Operation {
public:
    /// @brief Executes the arithmetic operation. 
    /// This is a pure virtual function that performs an arithmetic operation
    /// on two values of type T and returns the result.
    /// @param a The first operand.
    /// @param b The second operand.
    /// @return The result of the arithmetic operation.
    virtual T execute(T a, T b) const = 0;

    /// @brief Virtual destructor.
    virtual ~Operation() {}
};

/// @brief Derived class for addition operation.
/// Implements the execute function to perform addition.
template <typename T>
class AddOperation : public Operation<T> {
public:
    T execute(T a, T b) const override;
};

/// @brief Derived class for subtraction operation.
/// Implements the execute function to perform subtraction.
template <typename T>
class SubtractOperation : public Operation<T> {
public:
    T execute(T a, T b) const override;
};

/// @brief Derived class for multiplication operation.
/// Implements the execute function to perform multiplication.
template <typename T>
class MultiplyOperation : public Operation<T> {
public:
    T execute(T a, T b) const override;
};

/// @brief Derived class for division operation.
/// Implements the execute function to perform division.
/// @note Division by zero should be handled appropriately.
template <typename T>
class DivideOperation : public Operation<T> {
public:
    T execute(T a, T b) const override;
};

/// @brief Derived class for modulo operation.
/// Implements the execute function to perform modulo operation.
/// @note Modulo by zero should be handled appropriately.
template <typename T>
class ModuloOperation : public Operation<T> {
public:
    T execute(T a, T b) const override;
};