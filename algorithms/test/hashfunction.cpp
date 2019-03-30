#include <gtest/gtest.h>
#include <cstring>
#include "hashfunction_string_test_set.h"

#define INTEGER_HASHES_PER_TEST_COUNT 30000
#define STRING_HASHES_PER_TEST_COUNT STRING_TEST_SET_WORD_COUNT

extern int hash(int value, int slots);
extern int hash(const char* value, int slots);

const char* GetTestWord(int index) {
    index = index % STRING_TEST_SET_WORD_COUNT;
    char* test_set_copy = (char*)malloc(sizeof(char) * strlen(STRING_TEST_SET));
    memcpy((void*)test_set_copy, (void*)STRING_TEST_SET, sizeof(char) * strlen(STRING_TEST_SET));
    char* words = strtok(test_set_copy, " ,.");
    while(--index > 0) {
        words = strtok(nullptr, " ,.");
    }
    char* ret_string = (char*)malloc(sizeof(char) * strlen(words));
    strcpy(ret_string, words);
    delete[] test_set_copy;
    return ret_string;
}

TEST(HashFunctionSuite, IntegerHashFunctionIsDeterministic) {
    // Setup
    int input = 1;
    int output;

    // Execution
    for (int i = 2; i < 100; i++) {
        output = hash(input, i);
        for (int j = 0; j < 100; j++) {
            ASSERT_EQ(output, hash(input, i));
        }
    }
}

TEST(HashFunctionSuite, IntegerHashFunctionIsUniformlyDistributedFor10Slots) {
    // Setup
    int occurrences[10] = {0};

    // Execution
    for (int i = 0; i < INTEGER_HASHES_PER_TEST_COUNT; i++) {
        occurrences[hash(i, 10)]++;
    }

    // Verification
    for (int i = 0; i < 10; i++) {
        ASSERT_GE(1.2 * INTEGER_HASHES_PER_TEST_COUNT / 10, occurrences[i]);
    }
}

TEST(HashFunctionSuite, IntegerHashFunctionIsUniformlyDistributedFor20Slots) {
    // Setup
    int occurrences[20] = {0};

    // Execution
    for (int i = 0; i < INTEGER_HASHES_PER_TEST_COUNT; i++) {
        occurrences[hash(i, 20)]++;
    }

    // Verification
    for (int i = 0; i < 20; i++) {
        ASSERT_GE(1.2 * INTEGER_HASHES_PER_TEST_COUNT / 20, occurrences[i]);
    }
}

TEST(HashFunctionSuite, IntegerHashFunctionIsUniformlyDistributedFor100Slots) {
    // Setup
    int occurrences[100] = {0};

    // Execution
    for (int i = 0; i < INTEGER_HASHES_PER_TEST_COUNT; i++) {
        occurrences[hash(i, 100)]++;
    }

    // Verification
    for (int i = 0; i < 100; i++) {
        ASSERT_GE(1.2 * INTEGER_HASHES_PER_TEST_COUNT / 100, occurrences[i]);
    }
}

TEST(HashFunctionSuite, IntegerHashFunctionIsUniformlyDistributedFor1000Slots) {
    // Setup
    int occurrences[1000] = {0};

    // Execution
    for (int i = 0; i < INTEGER_HASHES_PER_TEST_COUNT; i++) {
        occurrences[hash(i, 1000)]++;
    }

    // Verification
    for (int i = 0; i < 1000; i++) {
        ASSERT_GE(1.2 * INTEGER_HASHES_PER_TEST_COUNT / 1000, occurrences[i]);
    }
}

TEST(HashFunctionSuite, StringHashFunctionIsDeterministic) {
    // Setup
    const char* input = "Hello world";
    int output;

    // Execution
    for (int i = 2; i < 100; i++) {
        output = hash(input, i);
        for (int j = 0; j < 100; j++) {
            ASSERT_EQ(output, hash(input, i));
        }
    }
}

TEST(HashFunctionSuite, StringHashFunctionIsUniformlyDistributedFor10Slots) {
    // Setup
    const char* input;
    int occurrences[10] = {0};

    // Execution
    for (int i = 0; i < STRING_HASHES_PER_TEST_COUNT; i++) {
        input = GetTestWord(i);
        occurrences[hash(input, 10)]++;
    }

    // Verification
    for (int i = 0; i < 10; i++) {
        ASSERT_GE(1.2 * STRING_HASHES_PER_TEST_COUNT / 10, occurrences[i]);
    }
}

TEST(HashFunctionSuite, StringHashFunctionIsUniformlyDistributedFor20Slots) {
    // Setup
    const char* input;
    int occurrences[20] = {0};

    // Execution
    for (int i = 0; i < STRING_HASHES_PER_TEST_COUNT; i++) {
        input = GetTestWord(i);
        occurrences[hash(input, 20)]++;
    }

    // Verification
    for (int i = 0; i < 20; i++) {
        ASSERT_GE(1.2 * STRING_HASHES_PER_TEST_COUNT / 20, occurrences[i]);
    }
}

TEST(HashFunctionSuite, StringHashFunctionIsUniformlyDistributedFor100Slots) {
    // Setup
    const char* input;
    int occurrences[100] = {0};

    // Execution
    for (int i = 0; i < STRING_HASHES_PER_TEST_COUNT; i++) {
        input = GetTestWord(i);
        occurrences[hash(input, 100)]++;
    }

    // Verification
    for (int i = 0; i < 100; i++) {
        ASSERT_GE(1.2 * STRING_HASHES_PER_TEST_COUNT / 100, occurrences[i]);
    }
}

TEST(HashFunctionSuite, StringHashFunctionIsUniformlyDistributedFor1000Slots) {
    // Setup
    const char* input;
    int occurrences[1000] = {0};

    // Execution
    for (int i = 0; i < STRING_HASHES_PER_TEST_COUNT; i++) {
        input = GetTestWord(i);
        occurrences[hash(input, 1000)]++;
    }

    // Verification
    for (int i = 0; i < 1000; i++) {
        ASSERT_GE(10, occurrences[i]);
    }
}