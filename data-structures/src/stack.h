#ifndef STACK_H
#define STACK_H

#include "node.h"

template <typename T>
class Stack {
private:
    Node<T> *top;
    int count;
public:
    Stack();
    ~Stack();
    void push(T data);
    T pop();
    T peek() const;
    bool isEmpty() const;
};

#endif