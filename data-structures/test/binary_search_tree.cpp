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