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


TEST(TreeNodeSuite, AddChildReturnsFalseIfChildrenBufferIsFull) {
    // Setup
    TreeNode<int> software_under_test(12, 2);
    TreeNode<int>* child = new TreeNode<int>(2, 2);
    software_under_test.AddChild(child);
    software_under_test.AddChild(child);

    // Execution
    bool test = software_under_test.AddChild(child);

    // Verification
    ASSERT_FALSE(test);
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

TEST(TreeNodeSuite, SetChildReturnsTrueIfTheChildNodeIsSet) {
    // Setup
    TreeNode<int> software_under_test(12, 2);
    TreeNode<int>* child = new TreeNode<int>(2, 2);

    // Execution
    bool test = software_under_test.SetChild(child, 1);

    // Verification
    ASSERT_TRUE(test);
}

TEST(TreeNodeSuite, SetChildReturnsFalseIfIllegalIndexIsSet) {
    // Setup
    TreeNode<int> software_under_test(12, 2);
    TreeNode<int>* child = new TreeNode<int>(2, 2);

    // Execution
    bool test = software_under_test.SetChild(child, 2);

    // Verification
    ASSERT_FALSE(test);
}

TEST(TreeNodeSuite, SetChildUpdatesOnlyChildWithCorrespondingIndex) {
    // Setup
    TreeNode<int> software_under_test(12, 2);
    TreeNode<int>* child = new TreeNode<int>(2, 2);

    // Execution
    software_under_test.SetChild(child, 1);

    // Verification
    ASSERT_EQ(nullptr, software_under_test.GetChildren()[0]);
    ASSERT_EQ(child, software_under_test.GetChildren()[1]);
}

TEST(TreeNodeSuite, RemoveChildReturnsTrueIfChildNodeIsDeleted) {
    // Setup
    TreeNode<int> software_under_test(12, 2);
    TreeNode<int>* child = new TreeNode<int>(2, 2);
    software_under_test.AddChild(child);

    // Execution
    bool test = software_under_test.RemoveChild(0);

    // Verification
    ASSERT_TRUE(test);
}

TEST(TreeNodeSuite, RemoveChildReturnsFalseIfThereIsNoNodeAtSetIndex) {
    // Setup
    TreeNode<int> software_under_test(12, 2);
    TreeNode<int>* child = new TreeNode<int>(2, 2);
    software_under_test.AddChild(child);

    // Execution
    bool test = software_under_test.RemoveChild(1);

    // Verification
    ASSERT_FALSE(test);
}

TEST(TreeNodeSuite, RemoveChildDeletesChildNode) {
    // Setup
    TreeNode<int> software_under_test(12, 2);
    TreeNode<int>* child = new TreeNode<int>(2, 2);
    software_under_test.AddChild(child);
    ASSERT_EQ(child, software_under_test.GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetChildren()[1]);

    // Execution
    software_under_test.RemoveChild(0);

    // Verification
    ASSERT_EQ(nullptr, software_under_test.GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetChildren()[1]);
}

TEST(TreeNodeSuite, RemoveChildHasNoSideEffectsOnNodeDataOrOtherChildrenNodes) {
    // Setup
    TreeNode<int> software_under_test(12, 4);
    TreeNode<int>* child0 = new TreeNode<int>(2, 2);
    TreeNode<int>* child1 = new TreeNode<int>(4, 2);
    TreeNode<int>* child2 = new TreeNode<int>(8, 2);
    software_under_test.AddChild(child0);
    software_under_test.AddChild(child1);
    software_under_test.SetChild(child2, 3);
    ASSERT_EQ(child0, software_under_test.GetChildren()[0]);
    ASSERT_EQ(child1, software_under_test.GetChildren()[1]);
    ASSERT_EQ(nullptr, software_under_test.GetChildren()[2]);
    ASSERT_EQ(child2, software_under_test.GetChildren()[3]);

    // Execution
    software_under_test.RemoveChild(1);

    // Verification
    ASSERT_EQ(child0, software_under_test.GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetChildren()[1]);
    ASSERT_EQ(nullptr, software_under_test.GetChildren()[2]);
    ASSERT_EQ(child2, software_under_test.GetChildren()[3]);
}