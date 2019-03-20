#include <gtest/gtest.h>
#include "travis_macro.h"

ASSEMBLY_DECLARATION(void, SwapTwoValuesInMemory(int*, int*));

TEST(AsmSuite, AsmSwapTwoValuesInMemory) {
    // Setup
    int *a = (int*)malloc(sizeof(int));
    *a = 1;
    int *b = (int*)malloc(sizeof(int));
    *b = -1;

    // Execution
    ASSEMBLY_CALL(SwapTwoValuesInMemory(a, b));

    // Verification
    ASSERT_EQ(-1, *a);
    ASSERT_EQ(1, *b);
}