#include <gtest/gtest.h>
#include "travis_macro.h"

ASSEMBLY_DECLARATION(int, FibonacciNaive(int));

TEST(AsmSuite, FibonacciNaiveReturnsCorrectValueForZero) {
    // Setup

    // Execution
    int computed_result = ASSEMBLY_CALL(FibonacciNaive(0));

    // Verification
    ASSERT_EQ(1, computed_result);
}

TEST(AsmSuite, FibonacciNaiveReturnsCorrectValueForArgumentsGreaterThanZero) {
    // Setup
    int start_value = 1;
    int final_value = 10;
    int actual_result = 1;
    int computed_result;

    // Execution
    for (int i = start_value; i < final_value; i++) {
        computed_result = ASSEMBLY_CALL(FibonacciNaive(i));
        actual_result = actual_result * i;
        ASSERT_EQ(actual_result, computed_result);
    }
}

TEST(AsmSuite, FibonacciNaiveReturnsMinusOneIfArgumentIsNegative) {
    // Setup

    // Execution
    int result = ASSEMBLY_CALL(FibonacciNaive(-33));

    // Verification
    ASSERT_EQ(-1, result);
}