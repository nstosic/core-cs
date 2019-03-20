#include <gtest/gtest.h>

#if BUILD_ON_TRAVIS == 1
extern "C" void _SwapTwoValuesInMemory(int*, int*);
#else
extern "C" void SwapTwoValuesInMemory(int*, int*);
#endif

TEST(AsmSuite, AsmSwapTwoValuesInMemory) {
    // Setup
    int *a = (int*)malloc(sizeof(int));
    *a = 1;
    int *b = (int*)malloc(sizeof(int));
    *b = -1;

    // Execution
    SwapTwoValuesInMemory(a, b);

    // Verification
    ASSERT_EQ(-1, *a);
    ASSERT_EQ(1, *b);
}