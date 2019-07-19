#include <gtest/gtest.h>
#include "../../data-structures/src/list.h"
#include "../src/reverseeveryknodes.h"

extern List<int>* initializeList(const unsigned int param_count...);

TEST(ReverseEveryKNodeSuite, CallingFunctionOnEmptyListReturnsInput) {
    // Setup
    List<int> empty_list;

    // Execution
    List<int> result = ReverseEveryKNodes(empty_list, 3);

    // Verification
    ASSERT_EQ(empty_list, result);
}

TEST(ReverseEveryKNodeSuite, CallignFunctionOnNonEmptyListWithTupleSize1ReturnsListInOriginalOrder) {
    // Setup
    List<int>* input = initializeList(6, 1, 2, 3, 4, 5, 6);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 1);

    // Verification
    ASSERT_EQ(*input, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample1TupleSize2) {
    // Setup
    List<int>* input = initializeList(6, 1, 2, 3, 4, 5, 6);
    List<int>* expected = initializeList(6, 2, 1, 4, 3, 6, 5);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 2);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample1TupleSize3) {
    // Setup
    List<int>* input = initializeList(6, 1, 2, 3, 4, 5, 6);
    List<int>* expected = initializeList(6, 3, 2, 1, 6, 5, 4);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 3);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample1TupleSize4) {
    // Setup
    List<int>* input = initializeList(6, 1, 2, 3, 4, 5, 6);
    List<int>* expected = initializeList(6, 4, 3, 2, 1, 5, 6);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 4);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample1TupleSize5) {
    // Setup
    List<int>* input = initializeList(6, 1, 2, 3, 4, 5, 6);
    List<int>* expected = initializeList(6, 5, 4, 3, 2, 1, 6);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 5);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample1TupleSize6) {
    // Setup
    List<int>* input = initializeList(6, 1, 2, 3, 4, 5, 6);
    List<int>* expected = initializeList(6, 6, 5, 4, 3, 2, 1);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 6);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample2TupleSize2) {
    // Setup
    List<int>* input = initializeList(8, 1, 2, 2, 4, 5, 6, 7, 8);
    List<int>* expected = initializeList(8, 2, 1, 4, 2, 6, 5, 8, 7);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 2);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample2TupleSize3) {
    // Setup
    List<int>* input = initializeList(8, 1, 2, 2, 4, 5, 6, 7, 8);
    List<int>* expected = initializeList(8, 2, 2, 1, 6, 5, 4, 7, 8);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 3);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample2TupleSize4) {
    // Setup
    List<int>* input = initializeList(8, 1, 2, 2, 4, 5, 6, 7, 8);
    List<int>* expected = initializeList(8, 4, 2, 2, 1, 8, 7, 6, 5);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 4);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample2TupleSize5) {
    // Setup
    List<int>* input = initializeList(8, 1, 2, 2, 4, 5, 6, 7, 8);
    List<int>* expected = initializeList(8, 5, 4, 2, 2, 1, 6, 7, 8);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 5);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample2TupleSize6) {
    // Setup
    List<int>* input = initializeList(8, 1, 2, 2, 4, 5, 6, 7, 8);
    List<int>* expected = initializeList(8, 6, 5, 4, 2, 2, 1, 7, 8);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 6);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample2TupleSize7) {
    // Setup
    List<int>* input = initializeList(8, 1, 2, 2, 4, 5, 6, 7, 8);
    List<int>* expected = initializeList(8, 7, 6, 5, 4, 2, 2, 1, 8);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 7);

    // Verification
    ASSERT_EQ(*expected, result);
}

TEST(ReverseEveryKNodeSuite, ReverseEveryKNodeSample2TupleSize8) {
    // Setup
    List<int>* input = initializeList(8, 1, 2, 2, 4, 5, 6, 7, 8);
    List<int>* expected = initializeList(8, 8, 7, 6, 5, 4, 2, 2, 1);

    // Execution
    List<int> result = ReverseEveryKNodes(*input, 8);

    // Verification
    ASSERT_EQ(*expected, result);
}