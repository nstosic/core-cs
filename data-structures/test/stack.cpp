#include <gtest/gtest.h>
#include "../src/stack.h"

TEST(StackSuite, NewStackIsEmpty) {
    // Setup
    Stack<int> softwareUnderTest;
    
    // Execution
    bool empty = softwareUnderTest.isEmpty();

    // Verification
    ASSERT_TRUE(empty);
}
