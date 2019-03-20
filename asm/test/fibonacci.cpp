#include <gtest/gtest.h>
#include "travis_macro.h"

ASSEMBLY_DECLARATION(int, FibonacciNaive(int));

TEST(AsmSuite, FibonacciNaiveReturnsCorrectValueForOne) {
    // Setup

    // Execution
    int computed_result = ASSEMBLY_CALL(FibonacciNaive(1));

    // Verification
    ASSERT_EQ(1, computed_result);
}

TEST(AsmSuite, FibonacciNaiveReturnsCorrectValueForTwo) {
    // Setup

    // Execution
    int computed_result = ASSEMBLY_CALL(FibonacciNaive(2));

    // Verification
    ASSERT_EQ(1, computed_result);
}

TEST(AsmSuite, FibonacciNaiveReturnsCorrectValueForArgumentsGreaterThanTwo) {
    // Setup
    int start_value = 3;
    int final_value = 10;
    int actual_result[9]{2, 3, 5, 8, 13, 21, 34, 55};
    int computed_result;

    // Execution
    for (int i = start_value; i < final_value; i++) {
        computed_result = ASSEMBLY_CALL(FibonacciNaive(i));
        ASSERT_EQ(actual_result[i - start_value], computed_result);
    }
}

TEST(AsmSuite, FibonacciNaiveReturnsMinusOneIfArgumentIsNonPositive) {
    // Setup

    // Execution
    int result = ASSEMBLY_CALL(FibonacciNaive(-33));

    // Verification
    ASSERT_EQ(-1, result);
}