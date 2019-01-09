#include "stack.h"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
Stack<T>::Stack() {
    this->top = nullptr;
    this->count = 0;
}

template <typename T>
Stack<T>::~Stack() {
    Node<T> temp = this->top;
    while(temp != nullptr) {
        this->top = temp->next;
        delete temp;
        temp = this->top;
    }
}

template <typename T>
void Stack<T>::push(T data) {
    Node<T> top = new Node<T>(data);
    top->next = this->top;
    this->top = top;
    this->count++;
}

template <typename T>
T Stack<T>::pop() {
    if (this->top != nullptr) {
        T data = this->top->data;
        this->top = this->top->next;
        this->count--;
        return data;
    } else {
        throw new std::runtime_error("Using Stack::pop() on an empty data structure is forbidden.");
    }
}

template <typename T>
T Stack<T>::peek() {
    if (this->top != nullptr) {
        return this->top->data;
    } else {
        throw new std::runtime_error("Using Stack::pop() on an empty data structure is forbidden.");
    }
}

template <typename T>
bool Stack<T>::isEmpty() {
    return this->count == 0;
}