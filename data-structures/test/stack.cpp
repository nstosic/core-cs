#include <gtest/gtest.h>
#include "../src/stack.h"

TEST(StackSuite, NewStackIsEmpty) {
    // Setup
    Stack<int> softwareUnderTest;
    
    // Execution
    int count = softwareUnderTest.isEmpty();

    // Verification
    ASSERT_EQ(0, count);
}