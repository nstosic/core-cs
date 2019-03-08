#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>
#include "double_linked_node.h"

class ElementNotFoundException: public std::exception {};

template <typename T>
class LruCache {
private:
    unsigned int capacity_;
    unsigned int size_;
    DoubleLinkedNode<int>* first_;
    DoubleLinkedNode<int>* last_;
    std::unordered_map<int, T> cache_;
    LruCache(unsigned int capacity, unsigned int size, DoubleLinkedNode<int>* first, DoubleLinkedNode<int>* last);
    void moveToFront(int key);
    friend class LruCacheSuite_GetMovesTheObjectToTheFrontOfTheRecentlyUsedList_Test;
    friend class LruCacheSuite_PutPlacesTheObjectToTheFrontOfTheRecentlyUsedList_Test;
    friend class LruCacheSuite_PutPushesTheIndexNodeToTheFrontOfTheRecentlyUsedQueueIfTheSameKeyIsUsed_Test;
public:
    LruCache();
    LruCache(unsigned int capacity);
    ~LruCache();
    T get(int key);
    void put(int key, T value);
    unsigned int capacity() const;
    unsigned int size() const;
};

#endif