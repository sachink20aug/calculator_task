#include "operation.hpp"

#include <cmath>
#include <stdexcept>

template <typename T>
T AddOperation<T>::execute(T a, T b) const {
    return a + b;
}

template <typename T>
T SubtractOperation<T>::execute(T a, T b) const {
    return a - b;
}

template <typename T>
T MultiplyOperation<T>::execute(T a, T b) const {
    return a * b;
}

template <typename T>
T DivideOperation<T>::execute(T a, T b) const {
    if (b == static_cast<T>(0)) {
        throw std::runtime_error("Division by zero.");
    }
    return a / b;
}

template <typename T>
T ModuloOperation<T>::execute(T a, T b) const {
    if (b == static_cast<T>(0)) {
        throw std::runtime_error("Division by zero in modulo operation");
    }
    return std::fmod(a, b);
}

// Explicit template instantiation
template class AddOperation<float>;
template class SubtractOperation<float>;
template class MultiplyOperation<float>;
template class DivideOperation<float>;
template class ModuloOperation<float>;

template class AddOperation<double>;
template class SubtractOperation<double>;
template class MultiplyOperation<double>;
template class DivideOperation<double>;
template class ModuloOperation<double>;