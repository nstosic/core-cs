#include <gtest/gtest.h>
#include "../src/string.h"

TEST(StringSuite, NewStringIsEmpty) {
    // Setup
    String softwareUnderTest;

    // Execution
    unsigned long count = softwareUnderTest.Length();

    // Verification
    ASSERT_EQ(0L, count);
}

TEST(StringSuite, UnsafePointerReturnsCorrectAddress) {
    // Setup
    String *softwareUnderTest = new String();
    char *pointer = (char *)softwareUnderTest;
    // Manually fill memory location for String::buffer
    *pointer = 0x01;
    *(pointer + 1) = 0x02;
    *(pointer + 2) = 0x03;
    *(pointer + 3) = 0x04;
    unsigned long address;

    // Execution
    address = (unsigned long)softwareUnderTest->UnsafePointer();

    // Verification
    ASSERT_EQ(0x04030201, address);
}

TEST(StringSuite, RValueIsAssignedToLValueInEqualOperator) {
    // Setup
    const char *testString = "test";
    String softwareUnderTest;

    // Execution
    softwareUnderTest = testString;

    // Verification
    for (unsigned long i = 0; i < sizeof(testString); i++) {
        ASSERT_EQ(
            (unsigned char)*(testString + i),
            (unsigned char)*(softwareUnderTest.UnsafePointer() + i)
            );
    }
}