#include <gtest/gtest.h>
#include "travis_macro.h"

#include <algorithm>

ASSEMBLY_DECLARATION(int, BinarySearch(int, int*, unsigned int));
ASSEMBLY_DECLARATION(int, FibonacciNaive(int));

TEST(AsmSuite, BinarySearchForAnEmptyArrayReturnsMinusOne) {
    // Setup
    int value_to_look_for = 1;
    int array_param[1];
    unsigned int array_size = 0;

    // Execution
    int result = ASSEMBLY_CALL(BinarySearch(value_to_look_for, array_param, array_size));

    // Verification
    ASSERT_EQ(-1, result);
}

TEST(AsmSuite, BinarySearchForAnArrayOfSizeOneReturnsMinusOneIfTheElementDoesNotEqualSearchParameter) {
    // Setup
    int value_to_look_for = 1;
    int array_param[1];
    array_param[0] = -1;
    unsigned int array_size = 1;

    // Execution
    int result = ASSEMBLY_CALL(BinarySearch(value_to_look_for, array_param, array_size));

    // Verification
    ASSERT_EQ(-1, result);
}

TEST(AsmSuite, BinarySearchForAnArrayOfSizeOneReturnsZeroIndexIfTheElementIsEqualToSearchParameter) {
    // Setup
    int value_to_look_for = 1;
    int array_param[1];
    array_param[0] = 1;
    unsigned int array_size = 1;

    // Execution
    int result = ASSEMBLY_CALL(BinarySearch(value_to_look_for, array_param, array_size));

    // Verification
    ASSERT_EQ(0, result);
}

TEST(AsmSuite, BinarySearchForAnArbitraryNonDescendingArrayReturnsIndexWithSearchParamValue0) {
    // Setup
    int value_to_look_for = -1;
    int array_param[5];
    array_param[0] = -1;
    array_param[1] = 11;
    array_param[2] = 22;
    array_param[3] = 22;
    array_param[4] = 23;
    unsigned int array_size = 5;

    // Execution
    int result = ASSEMBLY_CALL(BinarySearch(value_to_look_for, array_param, array_size));

    // Verification
    ASSERT_EQ(0, result);
}

TEST(AsmSuite, BinarySearchForAnArbitraryNonDescendingArrayReturnsIndexWithSearchParamValue1) {
    // Setup
    int value_to_look_for = 11;
    int array_param[5];
    array_param[0] = -1;
    array_param[1] = 11;
    array_param[2] = 22;
    array_param[3] = 22;
    array_param[4] = 23;
    unsigned int array_size = 5;

    // Execution
    int result = ASSEMBLY_CALL(BinarySearch(value_to_look_for, array_param, array_size));

    // Verification
    ASSERT_EQ(1, result);
}

TEST(AsmSuite, BinarySearchForAnArbitraryNonDescendingArrayReturnsIndexWithSearchParamValue2) {
    // Setup
    int value_to_look_for = 22;
    int array_param[5];
    array_param[0] = -1;
    array_param[1] = 11;
    array_param[2] = 22;
    array_param[3] = 22;
    array_param[4] = 23;
    unsigned int array_size = 5;

    // Execution
    int result = ASSEMBLY_CALL(BinarySearch(value_to_look_for, array_param, array_size));

    // Verification
    ASSERT_EQ(2, result);
}

TEST(AsmSuite, BinarySearchForAnArbitraryNonDescendingArrayReturnsIndexWithSearchParamValue4) {
    // Setup
    int value_to_look_for = 23;
    int array_param[5];
    array_param[0] = -1;
    array_param[1] = 11;
    array_param[2] = 22;
    array_param[3] = 22;
    array_param[4] = 23;
    unsigned int array_size = 5;

    // Execution
    int result = ASSEMBLY_CALL(BinarySearch(value_to_look_for, array_param, array_size));

    // Verification
    ASSERT_EQ(4, result);
}

TEST(AsmSuite, BinarySearchReturnsSameIndexValueAsSTLLowerBoundImplementation) {
    int value_to_look_for, result_stl, result_of_software_in_test;
    int a[] = {-1, 1, 2, 3, 4, 5, 8, 12, 13, 21, 25, 26, 51, 88, 89, 90, 122, 144, 155};
    unsigned int array_size = sizeof(a) / sizeof(a[0]);
    std::vector<int> vector_a(a, a + array_size);
    std::vector<int>::iterator result_stl_iterator;

    for (int i = 0; i < 10; i++) {
        value_to_look_for = ASSEMBLY_CALL(FibonacciNaive(i));
        result_stl = -1;
        result_stl_iterator = std::lower_bound(vector_a.begin(), vector_a.end(), value_to_look_for);
        if (*result_stl_iterator == value_to_look_for) {
            result_stl = (int)(result_stl_iterator - vector_a.begin());
        }
        result_of_software_in_test = ASSEMBLY_CALL(BinarySearch(value_to_look_for, a, array_size));
        ASSERT_EQ(result_stl, result_of_software_in_test);
    }
}