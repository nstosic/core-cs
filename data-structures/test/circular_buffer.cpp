#include <gtest/gtest.h>
#include "../src/circular_buffer.h"

TEST(CircularBufferSuite, ConstructorSpecifiesBufferSize) {
    // Setup
    int size_param = 5;
    
    // Execution
    CircularBuffer software_under_test(size_param);

    // Verification
    ASSERT_EQ(size_param, software_under_test.Size());
}

TEST(CircularBufferSuite, ProduceUpdatesTailValue) {
    // Setup
    CircularBuffer software_under_test(5);
    char* circular_buffer_pointer = (char*)&software_under_test;
    int original_tail_value = (int)(*(int*)(circular_buffer_pointer + sizeof(unsigned int) + sizeof(int)));

    // Execution
    software_under_test.Produce(3);
    int updated_tail_value = (int)(*(int*)(circular_buffer_pointer + sizeof(unsigned int) + sizeof(int)));

    // Verification
    ASSERT_EQ(original_tail_value + 1, updated_tail_value);
}

TEST(CircularBufferSuite, ConsumeUpdatesHeadValue) {
    // Setup
    CircularBuffer software_under_test(5);
    char* circular_buffer_pointer = (char*)&software_under_test;
    int original_head_value = (int)(*(int*)(circular_buffer_pointer + sizeof(unsigned int)));
    software_under_test.Produce(3);
    software_under_test.Produce(3);

    // Execution
    
    int updated_head_value = (int)(*(int*)(circular_buffer_pointer + sizeof(unsigned int)));

    // Verification
    ASSERT_EQ(original_head_value + 1, updated_head_value);
}