#include <gtest/gtest.h>
#include "../src/binary_search_tree.h"
#include <random>
#include <queue>

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

TEST(BinarySearchTreeSuite, InsertingArbitraryValuesPreservesBSTPropertyForImmediateChildren) {
    // Setup
    BinarySearchTree<int> software_under_test;
    std::random_device random;
    std::mt19937 generator(random());
    std::uniform_int_distribution<> random_initializer(-100, 100);
    
    // Execution
    for (int i = 0; i < 15; i++) {
        software_under_test.Insert(random_initializer(generator));
    }

    // Verification
    std::queue<TreeNode<int>*> inorder_queue;
    inorder_queue.push(software_under_test.GetRoot());
    TreeNode<int> *ptr;
    while (!inorder_queue.empty()) {
        ptr = inorder_queue.front();
        inorder_queue.pop();
        if (ptr->GetChildren()[0] != nullptr) {
            ASSERT_TRUE(ptr->GetData() > ptr->GetChildren()[0]->GetData());
        }
        if (ptr->GetChildren()[1] != nullptr) {
            ASSERT_TRUE(ptr->GetData() < ptr->GetChildren()[1]->GetData());
        }
    }
}

TEST(BinarySearchTreeSuite, SearchReturnsNullptrIfTheTreeIsEmpty) {
    // Setup
    BinarySearchTree<int> software_under_test;

    // Execution
    TreeNode<int>* test = software_under_test.Search(2);

    // Verification
    ASSERT_EQ(nullptr, test);
}

TEST(BinarySearchTreeSuite, SearchReturnsCorrectTreeNode) {
    // Setup
    BinarySearchTree<int> software_under_test;
    software_under_test.Insert(1);
    software_under_test.Insert(2);
    software_under_test.Insert(3);

    // Execution
    TreeNode<int>* test = software_under_test.Search(2);

    // Verification
    ASSERT_EQ(software_under_test.GetRoot()->GetChildren()[1], test);
}

TEST(BinarySearchTreeSuite, RemoveReturnsFalseWhenCalledOnAnEmptyTree) {
    // Setup
    BinarySearchTree<int> software_under_test;

    // Execution
    bool test = software_under_test.Remove(2);

    // Verification
    ASSERT_FALSE(test);
}

TEST(BinarySearchTreeSuite, RemoveReturnsTrueIfTheDataIsFoundInTheTree) {
    // Setup
    BinarySearchTree<int> software_under_test;
    software_under_test.Insert(2);
    software_under_test.Insert(3);
    software_under_test.Insert(4);
    software_under_test.Insert(1);

    // Execution
    bool test = software_under_test.Remove(3);

    // Verification
    ASSERT_TRUE(test);
}

TEST(BinarySearchTreeSuite, RemovePreservesTreeStructureIfTheDataIsFoundInTheRoot) {
    // Setup
    BinarySearchTree<int> software_under_test;
    software_under_test.Insert(2);
    software_under_test.Insert(3);
    software_under_test.Insert(4);
    software_under_test.Insert(1);

    // Execution
    software_under_test.Remove(2);

    // Verification
    ASSERT_EQ(3, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(1, software_under_test.GetRoot()->GetChildren()[0]->GetData());
    ASSERT_EQ(4, software_under_test.GetRoot()->GetChildren()[1]->GetData());
}

TEST(BinarySearchTreeSuite, SeriesOfInsertionAndRemovalsPreserveTreeStructure) {
    // Setup
    BinarySearchTree<int> software_under_test;

    /*
    // Expected tree:
    //     10
    */
    software_under_test.Insert(10);
    ASSERT_EQ(10, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]);

    /*
    // Expected tree:
    //     10
    //       \
    //        20
    */
    software_under_test.Insert(20);
    ASSERT_EQ(10, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]);
    ASSERT_EQ(20, software_under_test.GetRoot()->GetChildren()[1]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[1]);

    /*
    // Expected tree:
    //     10
    //    /  \
    //   5    20
    */
    software_under_test.Insert(5);
    ASSERT_EQ(10, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(5, software_under_test.GetRoot()->GetChildren()[0]->GetData());
    ASSERT_EQ(20, software_under_test.GetRoot()->GetChildren()[1]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[1]);

    /*
    // Expected tree:
    //     10
    //    /  \
    //   5    20
    //    \
    //     9
    */
    software_under_test.Insert(9);
    ASSERT_EQ(10, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(5, software_under_test.GetRoot()->GetChildren()[0]->GetData());
    ASSERT_EQ(20, software_under_test.GetRoot()->GetChildren()[1]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]);
    ASSERT_EQ(9, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[1]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]->GetChildren()[1]);

    /*
    // Expected tree:
    //     20
    //    /
    //   5
    //    \
    //     9
    */
    software_under_test.Remove(10);
    ASSERT_EQ(20, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(5, software_under_test.GetRoot()->GetChildren()[0]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]);
    ASSERT_EQ(9, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]->GetChildren()[1]);

    /*
    // Expected tree:
    //     20
    //    /
    //   5
    //  / \
    // 2   9
    */
    software_under_test.Insert(2);
    ASSERT_EQ(20, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(5, software_under_test.GetRoot()->GetChildren()[0]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]);
    ASSERT_EQ(2, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]->GetData());
    ASSERT_EQ(9, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]->GetChildren()[1]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]->GetChildren()[1]);

    /*
    // Expected tree:
    //     20
    //    /
    //   9
    //  /
    // 2
    */
    software_under_test.Remove(5);
    ASSERT_EQ(20, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(9, software_under_test.GetRoot()->GetChildren()[0]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]);
    ASSERT_EQ(2, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]->GetChildren()[1]);

    /*
    // Expected tree:
    //     9
    //    /
    //   2
    */
    software_under_test.Remove(20);
    ASSERT_EQ(9, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(2, software_under_test.GetRoot()->GetChildren()[0]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]);

    /*
    // Expected tree:
    //     9
    //    /  \
    //   2    18
    */
    software_under_test.Insert(18);
    ASSERT_EQ(9, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(2, software_under_test.GetRoot()->GetChildren()[0]->GetData());
    ASSERT_EQ(18, software_under_test.GetRoot()->GetChildren()[1]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[1]);

    /*
    // Expected tree:
    //     9
    //    /  \
    //   2    18
    //          \
    //           22
    */
    software_under_test.Insert(22);
    ASSERT_EQ(9, software_under_test.GetRoot()->GetData());
    ASSERT_EQ(2, software_under_test.GetRoot()->GetChildren()[0]->GetData());
    ASSERT_EQ(18, software_under_test.GetRoot()->GetChildren()[1]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[0]->GetChildren()[1]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[0]);
    ASSERT_EQ(22, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[1]->GetData());
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[1]->GetChildren()[0]);
    ASSERT_EQ(nullptr, software_under_test.GetRoot()->GetChildren()[1]->GetChildren()[1]->GetChildren()[1]);
}