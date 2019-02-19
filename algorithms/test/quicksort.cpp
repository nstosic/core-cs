#include "../src/quicksort.h"
#include <gtest/gtest.h>
#include <cstdarg>
#include <cstring> // For memcpy

extern void quicksort(int* array_pointer, unsigned int number_of_elements, int quicksort_scheme);

int* initializeArray(const unsigned int param_count...) {
    int* array = new int[param_count];
    va_list args;
    va_start(args, param_count);
    for (unsigned int i = 0; i < param_count; i++) {
        array[i] = va_arg(args, int);
    }
    va_end(args);
    return array;
}

TEST(QuicksortLomutoTestSuite, QuicksortOnEmptyArrayIsSafe) {
    // Setup
    int* array = new int[0];

    // Execution
    

    // Verification
    ASSERT_NO_THROW(quicksort(array, 0, QS_LOMUTO));
}

TEST(QuicksortLomutoTestSuite, QuicksortReturnsElementsInNonDescendingOrder) {
    // Setup
    unsigned int length = 10;
    int* array = initializeArray(length, 0, 3, 0, 1, 9, 9, 4, 7, 1, 0);

    // Execution
    quicksort(array, length, QS_LOMUTO);

    // Verification
    for (unsigned int i = 0; i < length - 1; i++) {
        ASSERT_LE(array[i], array[i+1]);
    }
}

TEST(QuicksortLomutoTestSuite, QuicksortReturnsTheSameOrderAfterMultipleConsecutiveRuns) {
    // Setup
    unsigned int length = 10;
    int* array = initializeArray(length, 0, 3, 0, 1, 9, 9, 4, 7, 1, 0);
    quicksort(array, length, QS_LOMUTO);
    
    for (int i = 0; i < 10; i++) {
        int* copied_array_before_quicksort = new int[length];
        std::memcpy((void*)copied_array_before_quicksort, (void*)array, sizeof(int) * length);
        quicksort(array, length, QS_LOMUTO);
        for (unsigned int j = 0; j < length; j++) {
            ASSERT_EQ(array[j], copied_array_before_quicksort[j]);
        }
    }
}

TEST(QuicksortHoareTestSuite, QuicksortOnEmptyArrayIsSafe) {
    // Setup
    int* array = new int[0];

    // Execution
    

    // Verification
    ASSERT_NO_THROW(quicksort(array, 0, QS_HOARE));
}

TEST(QuicksortHoareTestSuite, QuicksortReturnsElementsInNonDescendingOrder) {
    // Setup
    unsigned int length = 10;
    int* array = initializeArray(length, 0, 3, 0, 1, 9, 9, 4, 7, 1, 0);

    // Execution
    quicksort(array, length, QS_HOARE);

    // Verification
    for (unsigned int i = 0; i < length - 1; i++) {
        ASSERT_LE(array[i], array[i+1]);
    }
}

TEST(QuicksortHoareTestSuite, QuicksortReturnsTheSameOrderAfterMultipleConsecutiveRuns) {
    // Setup
    unsigned int length = 10;
    int* array = initializeArray(length, 0, 3, 0, 1, 9, 9, 4, 7, 1, 0);
    quicksort(array, length, QS_HOARE);
    
    for (int i = 0; i < 10; i++) {
        int* copied_array_before_quicksort = new int[length];
        std::memcpy((void*)copied_array_before_quicksort, (void*)array, sizeof(int) * length);
        quicksort(array, length, QS_HOARE);
        for (unsigned int j = 0; j < length; j++) {
            ASSERT_EQ(array[j], copied_array_before_quicksort[j]);
        }
    }
}