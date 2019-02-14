#include <gtest/gtest.h>
#include "../src/binary_search_tree.h"

TEST(BinarySearchTreeSuite, InitialTreeIsEmpty) {
    // Setup
    BinarySearchTree<int> software_under_test;

    // Execution
    TreeNode<int>* root = software_under_test.GetRoot();

    // Verification
    ASSERT_EQ(nullptr, root);
}

TEST(BinarySearchTreeSuite, NodeAddedToEmptyTreeBecomesItsRoot) {
    // Setup
    BinarySearchTree<int> software_under_test;

    // Execution
    software_under_test.Insert(2);

    // Verification
    ASSERT_EQ(2, software_under_test.GetRoot()->GetData());
}

TEST(BinarySearchTreeSuite, NodeAddedToRootBecomesItsLeftChildIfSmaller) {
    // Setup
    BinarySearchTree<int> software_under_test;
    software_under_test.Insert(5);

    // Execution
    software_under_test.Insert(2);

    // Verification
    ASSERT_EQ(2, software_under_test.GetRoot()->GetChildren()[0]->GetData());
}

TEST(BinarySearchTreeSuite, ValueAddedToRootBecomesItsRightChildIfGreater) {
    // Setup
    BinarySearchTree<int> software_under_test;
    software_under_test.Insert(5);

    // Execution
    software_under_test.Insert(22);

    // Verification
    ASSERT_EQ(22, software_under_test.GetRoot()->GetChildren()[1]->GetData());
}

TEST(BinarySearchTreeSuite, InsertReturnsFalseIfValueAlreadyExistsInTheTree) {
    // Setup
    BinarySearchTree<int> software_under_test;
    software_under_test.Insert(5);

    // Execution
    bool test = software_under_test.Insert(5);

    // Verification
    ASSERT_FALSE(test);
}

TEST(BinarySearchTreeSuite, RemovingFromEmptyTreeReturnsFalse) {
    // Setup
    BinarySearchTree<int> software_under_test;

    // Execution
    bool test = software_under_test.Remove(2);

    // Verification
    ASSERT_FALSE(test);
}