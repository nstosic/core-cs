#include <gtest/gtest.h>
#include "../src/circular_buffer.h"

TEST(CircularBufferSuite, ConstructorSpecifiesBufferSize) {
    // Setup
    unsigned int size_param = 5;
    
    // Execution
    CircularBuffer software_under_test(size_param);

    // Verification
    ASSERT_EQ(size_param, software_under_test.Size());
}

TEST(CircularBufferSuite, ProduceUpdatesTailValue) {
    // Setup
    CircularBuffer software_under_test(5);
    char* circular_buffer_pointer = (char*)&software_under_test;
    int original_tail_value = (int)*(circular_buffer_pointer + sizeof(int*) + sizeof(unsigned int) + sizeof(int));

    // Execution
    software_under_test.Produce(3);

    // Verification
    int updated_tail_value = (int)*(circular_buffer_pointer + sizeof(int*) + sizeof(unsigned int) + sizeof(int));
    ASSERT_EQ(original_tail_value + 1, updated_tail_value);
}

TEST(CircularBufferSuite, ProduceUpdatesTailValueToZeroIndexIfTailIsAtLastIndex) {
    // Setup
    CircularBuffer software_under_test(5);
    char* circular_buffer_pointer = (char*)&software_under_test;
    void* head_pointer = (void*)(circular_buffer_pointer + sizeof(int*) + sizeof(unsigned int));
    *(int*)head_pointer = 2; // Update head to free capacity
    void* tail_pointer = (void*)(circular_buffer_pointer + sizeof(int*) + sizeof(unsigned int) + sizeof(int));
    *(int*)tail_pointer = 4;

    // Execution
    software_under_test.Produce(3);

    // Verification
    int updated_tail_value = *(int*)tail_pointer;
    ASSERT_EQ(0, updated_tail_value);
}

TEST(CircularBufferSuite, ProducePersistsCorrectValue) {
    // Setup
    CircularBuffer software_under_test(5);
    void* circular_buffer_pointer = (void*)&software_under_test;
    int** pointer_to_buffer = (int**)circular_buffer_pointer;

    // Execution
    software_under_test.Produce(4);

    // Verification
    int stored_item = **pointer_to_buffer;
    ASSERT_EQ(4, stored_item);
}

TEST(CircularBufferSuite, ConsumeUpdatesHeadValue) {
    // Setup
    CircularBuffer software_under_test(5);
    char* circular_buffer_pointer = (char*)&software_under_test;
    int original_head_value = *(int*)(void*)(circular_buffer_pointer + sizeof(int*) + sizeof(unsigned int));
    software_under_test.Produce(3);
    software_under_test.Produce(3);

    // Execution
    software_under_test.Consume();

    // Verification
    int updated_head_value = *(int*)(void*)(circular_buffer_pointer + sizeof(int*) + sizeof(unsigned int));
    ASSERT_EQ(original_head_value + 1, updated_head_value);
}

TEST(CircularBufferSuite, ConsumeTakesCorrectValue) {
    // Setup
    CircularBuffer software_under_test(5);
    software_under_test.Produce(3);

    // Execution
    int consumed_data = software_under_test.Consume();

    // Verification
    ASSERT_EQ(3, consumed_data);
}
