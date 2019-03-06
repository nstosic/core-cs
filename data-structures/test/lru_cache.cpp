#include "../src/lru_cache.h"
#include <gtest/gtest.h>

TEST(LruCacheSuite, EmptyConstructorCreatesCacheWithCapacityOfOne) {
    // Setup

    // Execution
    LruCache<int> software_under_test;

    // Verification
    char* cache_ptr = (char*)&software_under_test;
    ASSERT_EQ(1, *((int*)(void*)cache_ptr)); // capacity
    ASSERT_EQ(0, *((int*)(void*)(cache_ptr + sizeof(unsigned int)))); // size
    ASSERT_EQ(nullptr, *((DoubleLinkedNode<int>**)(void*)(cache_ptr + sizeof(unsigned int) * 2))); // first
    ASSERT_EQ(nullptr, *((DoubleLinkedNode<int>**)(void*)(cache_ptr + sizeof(unsigned int) * 2 + sizeof(DoubleLinkedNode<int>*)))); // last
}

TEST(LruCacheSuite, ConstructorWithFixedCapacityCreatesCacheWithGivenCapacity) {
    // Setup

    // Execution
    LruCache<int> software_under_test(5);

    // Verification
    char* cache_ptr = (char*)&software_under_test;
    ASSERT_EQ(5, *((int*)(void*)cache_ptr)); // capacity
    ASSERT_EQ(0, *((int*)(void*)(cache_ptr + sizeof(unsigned int)))); // size
    ASSERT_EQ(nullptr, *((DoubleLinkedNode<int>**)(void*)(cache_ptr + sizeof(unsigned int) * 2))); // first
    ASSERT_EQ(nullptr, *((DoubleLinkedNode<int>**)(void*)(cache_ptr + sizeof(unsigned int) * 2 + sizeof(DoubleLinkedNode<int>*)))); // last
}

TEST(LruCacheSuite, PutAddsTheValueToTheUnderlyingCacheDataStructure) {
    // Setup
    LruCache<int> software_under_test(6);

    // Execution
    software_under_test.put(5, 5);

    // Verification
    char* cache_ptr = (char*)&software_under_test;
    std::unordered_map<int, int>* underlying_cache = (std::unordered_map<int, int>*)(void*)(cache_ptr + sizeof(unsigned int) * 2 + sizeof(DoubleLinkedNode<int>*) * 2);
    ASSERT_TRUE(underlying_cache->count(5) > 0);
}