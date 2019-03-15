#include <gtest/gtest.h>

extern void SwapInPlaceArithmetical(int &x, int &y);
extern void SwapInPlaceXor(int &x, int &y);

TEST(SwapInPlaceSuite, VerifyFirstArgumentValueAfterArithmeticalSwapOperation) {
    // Setup
    int x = 3, y = 6;

    // Execution
    SwapInPlaceArithmetical(x, y);

    // Verification
    ASSERT_EQ(6, x);
}

TEST(SwapInPlaceSuite, VerifySecondArgumentValueAfterArithmeticalSwapOperation) {
    // Setup
    int x = 3, y = 6;

    // Execution
    SwapInPlaceArithmetical(x, y);

    // Verification
    ASSERT_EQ(3, y);
}

TEST(SwapInPlaceSuite, VerifyFirstArgumentValueAfterLogicalSwapOperation) {
    // Setup
    int x = 3, y = 6;

    // Execution
    SwapInPlaceXor(x, y);

    // Verification
    ASSERT_EQ(6, x);
}

TEST(SwapInPlaceSuite, VerifySecondArgumentValueAfterLogicalSwapOperation) {
    // Setup
    int x = 3, y = 6;

    // Execution
    SwapInPlaceXor(x, y);

    // Verification
    ASSERT_EQ(3, y);
}

TEST(SwapInPlaceSuite, VerifyFirstArgumentValueAfterLogicalSwapOperationForLargeInput) {
    // Setup
    int x = 2147483647, y = -2147483648; // 2 ^ 31 = 2147483648

    // Execution
    SwapInPlaceXor(x, y);

    // Verification
    ASSERT_EQ(-2147483648, x);
}

TEST(SwapInPlaceSuite, VerifySecondArgumentValueAfterLogicalSwapOperationForLargeInput) {
    // Setup
    int x = 2147483647, y = -2147483648; // 2 ^ 31 = 2147483648

    // Execution
    SwapInPlaceXor(x, y);

    // Verification
    ASSERT_EQ(2147483647, y);
}