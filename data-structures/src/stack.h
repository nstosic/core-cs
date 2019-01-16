#ifndef STACK_H
#define STACK_H

#include "node.h"

template <typename T>
class Stack {
private:
    Node<T> *top_;
    int count_;
public:
    Stack();
    ~Stack();
    void Push(T data);
    T Pop();
    T Peek() const;
    int Size() const;
    bool IsEmpty() const;
};

#endif