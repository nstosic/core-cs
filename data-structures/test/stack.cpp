#include <gtest/gtest.h>
#include "../src/stack.h"
#include <cstdarg>

// Initializes the stack with the arguments in LIFO order
Stack<int> initializeStack(const int param_count...) {
    Stack<int> stack;
    va_list args;
    va_start(args, param_count);
    for (int i = 0; i < param_count; i++) {
        int arg = va_arg(args, int);
        stack.Push(arg);
    }
    va_end(args);
    return stack;
}

TEST(StackSuite, NewStackIsEmpty) {
    // Setup
    Stack<int> software_under_test;
    
    // Execution
    bool empty = software_under_test.IsEmpty();

    // Verification
    ASSERT_TRUE(empty);
}

TEST(StackSuite, PushUpdatesStackSize) {
    // Setup
    Stack<int> software_under_test;
    int previous_count = software_under_test.Size();

    // Execution
    software_under_test.Push(0);
    int new_count = software_under_test.Size();

    // Verification
    ASSERT_EQ(previous_count, new_count - 1);
}

TEST(StackSuite, PeekRetrievesTopElement) {
    // Setup
    Stack<int> software_under_test = initializeStack(3, 1, 2, 3);
    // Manually retrieve top element
    Node<int>** indirect_head_pointer = (Node<int>**)&software_under_test;
    int actual_top_value = (*indirect_head_pointer)->GetData();

    // Execution
    int peek_result = software_under_test.Peek();

    // Verification
    ASSERT_EQ(actual_top_value, peek_result);
}

TEST(StackSuite, PushPlacesDataToTheTop) {
    // Setup
    Stack<int> software_under_test = initializeStack(2, -1, 0);

    // Execution
    software_under_test.Push(1);

    // Verification
    ASSERT_EQ(1, software_under_test.Peek());
}

TEST(StackSuite, PopRetrievesTopElement) {
    // Setup
    Stack<int> software_under_test = initializeStack(3, 1, 2, -1);

    // Execution
    int poppedElement = software_under_test.Pop();

    ASSERT_EQ(-1, poppedElement);
}

TEST(StackSuite, PopRemovesTopElement) {
    // Setup
    Stack<int> software_under_test = initializeStack(3, 1, 2, 3);
    Node<int>** stack_head_pointer = (Node<int>**)&software_under_test;
    Node<int>* old_head = *stack_head_pointer;

    // Execution
    software_under_test.Pop();
    
    // Verification
    Node<int>* temp = *stack_head_pointer;
    while (temp != nullptr) {
        ASSERT_NE(old_head, temp);
        temp = temp->GetNext();
    }
}

TEST(StackSuite, SizeReturnsProperCount) {
    // Setup
    Stack<int> software_under_test = initializeStack(6, 2, 2, 3, 5, -1, -2);

    // Execution
    int original_count = software_under_test.Size();

    // Verification
    ASSERT_EQ(6, original_count);
}