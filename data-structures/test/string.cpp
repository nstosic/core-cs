#include <gtest/gtest.h>
#include "../src/string.h"

TEST(StackSuite, NewStringIsEmpty) {
    // Setup
    String softwareUnderTest;

    // Execution
    int count = softwareUnderTest.length();

    // Verification
    ASSERT_EQ(0, count);
}