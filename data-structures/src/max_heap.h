#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "heap.h"

template <typename T>
class MaxHeap : public Heap<T> {
public:
    using Heap<T>::Heap;
    ~MaxHeap() = default;
    void BubbleUp();
    void BubbleDown();
};

#endif