#include <gtest/gtest.h>
#include <cstring> // For memcpy

extern void radixsort(int* array, unsigned int number_of_elements);
extern int* initializeArray(const unsigned int param_count...);

TEST(RadixSortSuite, RadixsortOnEmptyArrayIsSafe) {
    // Setup
    int* array = new int[0];

    // Execution

    // Verification
    ASSERT_NO_THROW(radixsort(array, 0));
}

TEST(RadixSortSuite, RadixsortReturnsElementsInNonDescendingOrder) {
    // Setup
    unsigned int length = 6;
    int* array = initializeArray(length, 3, 1, 1994, 994, 71, 222);

    // Execution
    radixsort(array, length);

    // Verification
    for (unsigned int i = 0; i < length - 1; i++) {
        ASSERT_LE(array[i], array[i + 1]);
    }
}

TEST(RadixSortSuite, RadixsortReturnsTheSameOrderAfterMultipleConsecutiveRuns) {
    // Setup
    unsigned int length = 6;
    int* array = initializeArray(length, 3, 1, 1994, 994, 71, 222);
    radixsort(array, length);

    for (unsigned int i = 0; i < 10; i++) {
        int* copied_array_before_quicksort = new int[length];
        std::memcpy((void*)copied_array_before_quicksort, (void*)array, sizeof(int) * length);
        radixsort(array, length);
        for (unsigned int j = 0; j < length; j++) {
            ASSERT_EQ(array[j], copied_array_before_quicksort[j]);
        }
    }
}