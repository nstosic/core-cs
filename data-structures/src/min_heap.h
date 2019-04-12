#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "heap.h"

template <typename T>
class MinHeap : public Heap<T> {
public:
    using Heap<T>::Heap;
    ~MinHeap() = default;
    void BubbleUp();
    void BubbleDown();
};

#endif