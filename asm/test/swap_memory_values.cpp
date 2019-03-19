#include <gtest/gtest.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void SwapTwoValuesInMemory(int *mem_addr_a, int *mem_addr_b);

#ifdef __cplusplus
}
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