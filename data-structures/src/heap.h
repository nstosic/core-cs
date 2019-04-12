#ifndef HEAP_H
#define HEAP_H

#include "tree_node.h"
#include <vector>

template <typename T>
class Heap {
protected:
    std::vector<T> *buffer_;
    virtual void BubbleUp() = 0;
    virtual void BubbleDown() = 0;
public:
    Heap();
    ~Heap();
    void Add(const T value);
    const T GetTop() const;
    void RemoveTop();
    unsigned long Size() const;
};

#endif