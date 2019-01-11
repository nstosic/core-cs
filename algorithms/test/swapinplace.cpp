#include <gtest/gtest.h>

extern void swapInPlace(int &x, int &y);

TEST(SwapInPlaceSuite, VerifyFirstArgumentValueAfterOperation) {
    // Setup
    int x = 3, y = 6;

    // Execution
    swapInPlace(x, y);

    // Verification
    ASSERT_EQ(6, x);
}

TEST(SwapInPlaceSuite, VerifySecondArgumentValueAfterOperation) {
    // Setup
    int x = 3, y = 6;

    // Execution
    swapInPlace(x, y);

    // Verification
    ASSERT_EQ(3, y);
}