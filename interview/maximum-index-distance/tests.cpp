#include <gtest/gtest.h>

extern int* initializeArray(unsigned int param_count...);
extern unsigned int MaximumIndexDistance(int* a, unsigned int n);

TEST(MaximumIndexDistanceSuite, MaximumIndexDistanceForEmptyCollectionIsZero) {
    // Setup
    int* input = new int[0];

    // Execution
    unsigned int result = MaximumIndexDistance(input, 0);

    // Verification
    ASSERT_EQ(0, result);
}

TEST(MaximumIndexDistanceSuite, MaximumIndexDistanceForCollectionInDescendingOrderReturnsZero) {
    // Setup
    int* input = initializeArray(5, 5, 4, 3, 2, -1);

    // Execution
    unsigned int result = MaximumIndexDistance(input, 5);

    // Verification
    ASSERT_EQ(0, result);
}

TEST(MaximumIndexDistanceSuite, MaximumIndexDistanceForCollectionInAscendingOrderReturnsNMinusOne) {
    // Setup
    int* input = initializeArray(5, 1, 2, 3, 4, 5);

    // Execution
    unsigned int result = MaximumIndexDistance(input, 5);

    // Verification
    ASSERT_EQ(4, result);
}

TEST(MaximumIndexDistanceSuite, MaximumIndexDistanceForArbitraryCollectionReturnsCorrectValue) {
    // Setup
    int* input = initializeArray(9, 34, 8, 10, 3, 2, 80, 30, 33, 1);

    // Execution
    unsigned int result = MaximumIndexDistance(input, 9);

    // Verification
    ASSERT_EQ(6, result);
}