#include "../src/lru_cache.h"
#include "../src/exceptions.h"
#include <gtest/gtest.h>

TEST(LruCacheSuite, EmptyConstructorCreatesCacheWithCapacityOfOne) {
    // Setup

    // Execution
    LruCache<int> software_under_test;

    // Verification
    char* cache_ptr = (char*)&software_under_test;
    ASSERT_EQ(1, *((int*)(void*)cache_ptr)); // capacity
}

TEST(LruCacheSuite, ConstructorWithFixedCapacityCreatesCacheWithGivenCapacity) {
    // Setup

    // Execution
    LruCache<int> software_under_test(5);

    // Verification
    char* cache_ptr = (char*)&software_under_test;
    ASSERT_EQ(5, *((int*)(void*)cache_ptr)); // capacity
}

TEST(LruCacheSuite, GetReturnsTheObjectCorrespondingToTheKey) {
    // Setup
    LruCache<int> software_under_test(6);
    software_under_test.put(3, 33);

    // Execution
    int test = software_under_test.get(3);

    // Verification
    ASSERT_EQ(33, test);
}

TEST(LruCacheSuite, GetMovesTheObjectToTheFrontOfTheRecentlyUsedList) {
    // Setup
    LruCache<int> software_under_test(6);
    software_under_test.put(3, 33);
    software_under_test.put(1, 11);
    software_under_test.put(2, 22);

    // Execution
    software_under_test.get(3);
    software_under_test.get(2);
    software_under_test.get(1);
    software_under_test.get(3);
    
    // Verification
    ASSERT_EQ(3, software_under_test.first_->getData());
    ASSERT_EQ(2, software_under_test.last_->getData());
}

TEST(LruCacheSuite, GetThrowsAnExceptionIfNoObjectForTheGivenKeyExistsInTheCache) {
    // Setup
    LruCache<int> software_under_test(6);

    // Execution

    // Verification
    ASSERT_THROW(software_under_test.get(6), ElementNotFoundException);
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

TEST(LruCacheSuite, PutPlacesTheObjectToTheFrontOfTheRecentlyUsedList) {
    // Setup
    LruCache<int> software_under_test(6);

    // Execution
    software_under_test.put(4, 4);
    software_under_test.put(3, 3);
    software_under_test.get(4);
    software_under_test.put(5, 5);
    software_under_test.get(4);
    software_under_test.put(6, 6);
    software_under_test.put(66, 66);

    // Verification
    ASSERT_EQ(66, software_under_test.first_->getData());
}

TEST(LruCacheSuite, PutReplacesTheValueOfThePreviouslyCachedObjectIfTheSameKeyIsUsed) {
    // Setup
    LruCache<int> software_under_test(6);

    // Execution
    software_under_test.put(4, 4);
    software_under_test.put(4, 14);

    // Verification
    ASSERT_EQ(1, software_under_test.size());
    ASSERT_EQ(14, software_under_test.get(4));
}

TEST(LruCacheSuite, PutPushesTheIndexNodeToTheFrontOfTheRecentlyUsedQueueIfTheSameKeyIsUsed) {
    // Setup
    LruCache<int> software_under_test(6);

    // Execution
    software_under_test.put(4, 4);
    software_under_test.put(55, 5);
    software_under_test.put(5, 55);
    software_under_test.get(55);
    software_under_test.put(4, 14);

    // Verification
    ASSERT_EQ(4, software_under_test.first_->getData());
}

TEST(LruCacheSuite, PutDoesNotRemoveAnyCachedObjectsIfCacheIsNotFull) {
    // Setup
    LruCache<int> software_under_test(6);
    software_under_test.put(5, 6);
    software_under_test.put(4, 5);

    // Execution
    software_under_test.put(6, 6);

    // Verification
    char* cache_ptr = (char*)&software_under_test;
    std::unordered_map<int, int>* underlying_cache = (std::unordered_map<int, int>*)(void*)(cache_ptr + sizeof(unsigned int) * 2 + sizeof(DoubleLinkedNode<int>*) * 2);
    ASSERT_TRUE(underlying_cache->count(4) > 0);
    ASSERT_TRUE(underlying_cache->count(5) > 0);
}

TEST(LruCacheSuite, PutRemovesLastRecentlyUsedObjectIfCacheIsFull) {
    // Setup
    LruCache<int> software_under_test(2);
    software_under_test.put(5, 6);
    software_under_test.put(4, 5);

    // Execution
    software_under_test.put(6, 6);

    // Verification
    char* cache_ptr = (char*)&software_under_test;
    std::unordered_map<int, int>* underlying_cache = (std::unordered_map<int, int>*)(void*)(cache_ptr + sizeof(unsigned int) * 2 + sizeof(DoubleLinkedNode<int>*) * 2);
    ASSERT_TRUE(underlying_cache->count(4) > 0);
    ASSERT_TRUE(underlying_cache->count(5) == 0);
}

TEST(LruCacheSuite, CapacityReturnsProperValue) {
    // Setup
    LruCache<int> software_under_test(3);

    // Execution
    unsigned int capacity = software_under_test.capacity();

    // Verification
    ASSERT_EQ(3, capacity);
}

TEST(LruCacheSuite, CapacityReturnsZeroForNewlyCreatedLruCache) {
    // Setup
    LruCache<int> software_under_test(3);

    // Execution
    unsigned int size = software_under_test.size();

    // Verification
    ASSERT_EQ(0, size);
}