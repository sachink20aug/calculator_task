#include "calculator.hpp"
#include "operation.hpp"
#include "string_to_number.hpp"

#include <cmath>
#include <gtest/gtest.h>
#include <stdexcept>

// Define types to be used in templated tests
using TestTypes = ::testing::Types<float, double>;

// Fixture for testing Operation classes
template <typename T>
class OperationTest : public ::testing::Test {
protected:
    std::unique_ptr<Operation<T>> add_op;
    std::unique_ptr<Operation<T>> sub_op;
    std::unique_ptr<Operation<T>> mult_op;
    std::unique_ptr<Operation<T>> div_op;

    void SetUp() override {
        add_op = std::make_unique<AddOperation<T>>();
        sub_op = std::make_unique<SubtractOperation<T>>();
        mult_op = std::make_unique<MultiplyOperation<T>>();
        div_op = std::make_unique<DivideOperation<T>>();
    }

    void TearDown() override {
        add_op.reset();
        sub_op.reset();
        mult_op.reset();
        div_op.reset();
    }
};

TYPED_TEST_SUITE(OperationTest, TestTypes);

// Test cases for each operation
TYPED_TEST(OperationTest, HandlesAddition) {
    EXPECT_NEAR(this->add_op->execute(1.0, 1.0), 2.0, 0.001);
}

TYPED_TEST(OperationTest, HandlesSubtraction) {
    EXPECT_NEAR(this->sub_op->execute(5.0, 3.0), 2.0, 0.001);
}

TYPED_TEST(OperationTest, HandlesMultiplication) {
    EXPECT_NEAR(this->mult_op->execute(3.0, 2.0), 6.0, 0.001);
}

TYPED_TEST(OperationTest, HandlesDivision) {
    EXPECT_NEAR(this->div_op->execute(6.0, 2.0), 3.0, 0.001);
}

// Fixture for testing Calculator class
template <typename T>
class CalculatorTest : public ::testing::Test {
protected:
    Calculator<T> calculator;
};

TYPED_TEST_SUITE(CalculatorTest, TestTypes);

// Calculator tests for basic expressions
TYPED_TEST(CalculatorTest, HandlesSimpleAddition) {
    TypeParam xValue = 10.0;
    const std::string expression = "x + 5";
    auto result = this->calculator.calculate(expression, xValue);
    TypeParam expected = xValue + 5.0;
    EXPECT_NEAR(result, expected, 0.001);
}

TYPED_TEST(CalculatorTest, HandlesSimpleDivision) {
    TypeParam xValue = 20.0;
    const std::string expression = "x / 4";
    auto result = this->calculator.calculate(expression, xValue);
    TypeParam expected = xValue / 4.0;
    EXPECT_NEAR(result, expected, 0.001);
}

TYPED_TEST(CalculatorTest, CalculatesExpression) {
    TypeParam xValue = 5.0;
    const std::string expression = "((x+1)*2-x%3)/x";
    auto result = this->calculator.calculate(expression, xValue);
    TypeParam expected = ((xValue + 1.0) * 2.0 - std::fmod(xValue, 3.0)) / xValue;
    EXPECT_NEAR(result, expected, 0.001);
}

// Fixture for testing StringToNumber class
template <typename T>
class StringToNumberTest : public ::testing::Test {};

TYPED_TEST_SUITE(StringToNumberTest, TestTypes);

// Test case for string to number conversion
TYPED_TEST(StringToNumberTest, ConvertsStringToNumber) {
    size_t parsedLength;
    TypeParam number = StringToNumber<TypeParam>::convertStringToNumber("123.45", parsedLength);
    EXPECT_NEAR(number, static_cast<TypeParam>(123.45), 0.001);
    EXPECT_EQ(parsedLength, 6U);
}