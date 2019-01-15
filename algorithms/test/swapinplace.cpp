#include <gtest/gtest.h>

extern void SwapInPlace(int &x, int &y);

TEST(SwapInPlaceSuite, VerifyFirstArgumentValueAfterOperation) {
    // Setup
    int x = 3, y = 6;

    // Execution
    SwapInPlace(x, y);

    // Verification
    ASSERT_EQ(6, x);
}

TEST(SwapInPlaceSuite, VerifySecondArgumentValueAfterOperation) {
    // Setup
    int x = 3, y = 6;

    // Execution
    SwapInPlace(x, y);

    // Verification
    ASSERT_EQ(3, y);
}