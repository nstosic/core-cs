#include <gtest/gtest.h>
#include "../src/min_heap.h"
#include "../src/max_heap.h"
#include "../src/exceptions.h"

#define ELEMENT_EXISTS_IN_VECTOR(elem, vec) std::find(vec->begin(), vec->end(), elem) != vec->end()

// Non-abstract wrapper around Heap for unit tests
class TestHeap: public Heap<int> {
public:
    unsigned int bubble_up_calls = 0;
    unsigned int bubble_down_calls = 0;

    void BubbleUp() {
        bubble_up_calls++;
    }

    void BubbleDown() {
        bubble_down_calls++;
    }

    std::vector<int>* UnderlyingVector() const {
        return this->buffer_;
    }
};

TEST(HeapSuite, AddingAnElementToTheHeapCallsBubbleUp) {
    // Setup
    TestHeap software_under_test;
    unsigned int previous_number_of_calls = software_under_test.bubble_up_calls;

    // Execution
    software_under_test.Add(0);

    // Verification
    ASSERT_EQ(previous_number_of_calls + 1, software_under_test.bubble_up_calls);
}

TEST(HeapSuite, GetTopElementThrowsExceptionIfHeapIsEmpty) {
    // Setup
    TestHeap software_under_test;

    // Execution
    ASSERT_THROW(software_under_test.GetTop(), HeapEmptyException);

    // Verification
}

TEST(HeapSuite, GetTopElementRetrievesTheRootElement) {
    // Setup
    TestHeap software_under_test;
    std::vector<int>* vec = software_under_test.UnderlyingVector();
    software_under_test.Add(3);
    software_under_test.Add(2);
    software_under_test.Add(1);

    // Execution
    int result = software_under_test.GetTop();

    // Verification
    ASSERT_EQ((*vec)[0], result);
}

TEST(HeapSuite, RemoveTopThrowsExceptionIfHeapIsEmpty) {
    // Setup
    TestHeap software_under_test;

    // Execution
    ASSERT_THROW(software_under_test.RemoveTop(), HeapEmptyException);

    // Verification
}

TEST(HeapSuite, RemoveTopDeletesOneElementFromTheHeap) {
    // Setup
    TestHeap software_under_test;
    std::vector<int>* vec = software_under_test.UnderlyingVector();
    software_under_test.Add(3);
    software_under_test.Add(2);
    software_under_test.Add(1);
    unsigned long original_size = vec->size();

    // Execution
    software_under_test.RemoveTop();

    // Verification
    ASSERT_EQ(original_size, vec->size() + 1L);
}

TEST(HeapSuite, RemoveTopDeletesRootElementFromTheHeap) {
    // Setup
    TestHeap software_under_test;
    std::vector<int>* vec = software_under_test.UnderlyingVector();
    software_under_test.Add(3);
    software_under_test.Add(2);
    software_under_test.Add(1);

    // Execution
    software_under_test.RemoveTop();

    // Verification
    ASSERT_FALSE(ELEMENT_EXISTS_IN_VECTOR(3, vec));
    ASSERT_TRUE(ELEMENT_EXISTS_IN_VECTOR(2, vec));
    ASSERT_TRUE(ELEMENT_EXISTS_IN_VECTOR(1, vec));
}

TEST(HeapSuite, RemoveTopCallsBubbleDown) {
    // Setup
    TestHeap software_under_test;
    software_under_test.Add(3);
    unsigned int previous_number_of_calls = software_under_test.bubble_down_calls;

    // Execution
    software_under_test.RemoveTop();

    // Verification
    ASSERT_EQ(software_under_test.bubble_down_calls, previous_number_of_calls + 1);
}

TEST(HeapSuite, NewlyConstructedHeapHasSizeZero) {
    // Setup
    TestHeap software_under_test;

    // Execution
    unsigned long result = software_under_test.Size();

    // Verification
    ASSERT_EQ(0L, result);
}

TEST(HeapSuite, HeapSizeReturnsNumberOfElementsInTheUnderlyingVector) {
    // Setup
    TestHeap software_under_test;
    std::vector<int>* vec = software_under_test.UnderlyingVector();
    vec->push_back(3);
    vec->push_back(2);
    vec->push_back(10);

    // Execution
    unsigned long result = software_under_test.Size();

    // Verification
    ASSERT_EQ(3L, result);
}