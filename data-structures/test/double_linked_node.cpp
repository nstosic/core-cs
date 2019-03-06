#include "../src/double_linked_node.h"
#include <gtest/gtest.h>

TEST(DoubleLinkedNodeSuite, PrimaryConstructorCreatesNodeWithNoPredecessorOrSuccessor) {
    // Setup
    DoubleLinkedNode<int> software_under_test(2);

    // Execution

    // Verification
    ASSERT_EQ(nullptr, software_under_test.getNext());
    ASSERT_EQ(nullptr, software_under_test.getPrev());
}

TEST(DoubleLinkedNodeSuite, ConstructorProperlySetsSuccessorNode) {
    // Setup
    DoubleLinkedNode<int>* successor_node = new DoubleLinkedNode<int>(2);
    DoubleLinkedNode<int> software_under_test(2, successor_node, nullptr);

    // Execution

    // Verification
    ASSERT_EQ(successor_node, software_under_test.getNext());
    ASSERT_EQ(nullptr, software_under_test.getPrev());
}

TEST(DoubleLinkedNodeSuite, ConstructorProperlySetsPredecessorNode) {
    // Setup
    DoubleLinkedNode<int>* predecessor_node = new DoubleLinkedNode<int>(2);
    DoubleLinkedNode<int> software_under_test(2, nullptr, predecessor_node);

    // Execution

    // Verification
    ASSERT_EQ(nullptr, software_under_test.getNext());
    ASSERT_EQ(predecessor_node, software_under_test.getPrev());
}