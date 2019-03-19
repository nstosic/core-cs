#include <gtest/gtest.h>

#ifdef __cplusplus
extern "C" int FibonacciNaive(int);
#else
extern int FibonacciNaive(int a);
#endif

TEST(AsmSuite, FibonacciNaiveReturnsCorrectValueForZero) {
    // Setup

    // Execution
    int computed_result = FibonacciNaive(0);

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
        computed_result = FibonacciNaive(i);
        actual_result = actual_result * i;
        ASSERT_EQ(actual_result, computed_result);
    }
}

TEST(AsmSuite, FibonacciNaiveReturnsMinusOneIfArgumentIsNegative) {
    // Setup

    // Execution
    int result = FibonacciNaive(-33);

    // Verification
    ASSERT_EQ(-1, result);
}