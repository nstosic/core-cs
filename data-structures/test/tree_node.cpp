#include <gtest/gtest.h>
#include "../src/tree_node.h"

TEST(TreeNodeSuite, ConstructorSetsNodeValueProperly) {
    // Setup
    TreeNode<int> software_under_test(12, 2);

    // Execution
    int test = software_under_test.GetData();

    // Verification
    ASSERT_EQ(12, test);
}

TEST(TreeNodeSuite, ConstructorSetsNodeMaximumNumberOfChildrenProperly) {
    // Setup
    TreeNode<int> software_under_test(12, 2);

    // Execution
    unsigned int test = software_under_test.GetMaximumNumberOfChildren();

    // Verification
    ASSERT_EQ(2, test);
}

TEST(TreeNodeSuite, ConstructorInitializesNumberOfChildrenToZero) {
    // Setup
    TreeNode<int> software_under_test(12, 2);

    // Execution
    unsigned int number_of_children = software_under_test.GetNumberOfChildren();

    // Verification
    ASSERT_EQ(0, number_of_children);
}

TEST(TreeNodeSuite, AddChildReturnsTrueIfChildrenBufferIsNotFull) {
    // Setup
    TreeNode<int> software_under_test(12, 2);

    // Execution
    bool test = software_under_test.AddChild(new TreeNode<int>(122, 2));

    // Verification
    ASSERT_TRUE(test);
}

TEST(TreeNodeSuite, AddChildAddsNodeToTheChildrenBuffer) {
    // Setup
    TreeNode<int> software_under_test(12, 2);
    TreeNode<int>* child = new TreeNode<int>(2, 2);

    // Execution
    software_under_test.AddChild(child);

    // Verification
    ASSERT_EQ(child, software_under_test.GetChildren()[0]);
}