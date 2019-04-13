#include <gtest/gtest.h>
#include "../src/exceptions.h"

extern int Kth_Smallest(int* array, unsigned int n, unsigned int k);
extern int Kth_Largest(int* array, unsigned int n, unsigned int k);
extern int Kth_Element(int* array, unsigned int n, unsigned int k, int smallest_or_largest);

TEST(KthElementSuite, KthSmallestThrowsExceptionIfKIsGreaterOrEqualToN) {
    // Setup
    int* array = new int[1];
    
    // Execution
    ASSERT_THROW(Kth_Smallest(array, 1, 2), IllegalArgumentException);
}

TEST(KthElementSuite, KthLargestThrowsExceptionIfKIsGreaterOrEqualToN) {
    // Setup
    int* array = new int[1];
    
    // Execution
    ASSERT_THROW(Kth_Largest(array, 1, 2), IllegalArgumentException);
}

TEST(KthElementSuite, KthSmallestReturnsProperResult) {
    // Setup
    int array[7] = {0, 1, 2, 3, 4, 5, 6};

    // Execution
    int result = Kth_Smallest(array, 7, 5);

    // Verification
    ASSERT_EQ(4, result);
}

TEST(KthElementSuite, KthLargestReturnsProperResult) {
    // Setup
    int array[7] = {0, 1, 2, 3, 4, 5, 6};

    // Execution
    int result = Kth_Largest(array, 7, 5);

    // Verification
    ASSERT_EQ(2, result);
}

TEST(KthElementSuite, KthElementCallsKthSmallesMethodIfFourthParamIsLessThanOrEqualToZero) {
    // Setup
    int array[11] = {3, 17, 41, 45, 52, 59, 64, 60, 64, 92, 82};

    // Execution
    int expected_result = Kth_Smallest(array, 7, 5);
    int result = Kth_Element(array, 7, 5, -1);

    // Verification
    ASSERT_EQ(expected_result, result);
}

TEST(KthElementSuite, KthElementCallsKthLargestMethodIfFourthParamIsGreaterThanZero) {
    // Setup
    int array[11] = {3, 17, 41, 45, 52, 59, 64, 60, 64, 92, 82};

    // Execution
    int expected_result = Kth_Largest(array, 7, 5);
    int result = Kth_Element(array, 7, 5, 1);

    // Verification
    ASSERT_EQ(expected_result, result);
}