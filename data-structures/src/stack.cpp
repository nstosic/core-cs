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
    Node<T> *temp = this->top;
    while(temp != nullptr) {
        this->top = temp->getNext();
        delete temp;
        temp = this->top;
    }
}

template <typename T>
void Stack<T>::push(T data) {
    Node<T> *temp = new Node<T>(data);
    temp->next = this->top;
    this->top = temp;
    this->count++;
}

template <typename T>
T Stack<T>::pop() {
    if (this->top != nullptr) {
        T data = this->top->data;
        this->top = this->top->getNext();
        this->count--;
        return data;
    } else {
        throw new std::runtime_error("Using Stack::pop() on an empty data structure is forbidden.");
    }
}

template <typename T>
T Stack<T>::peek() const {
    if (this->top != nullptr) {
        return this->top->data;
    } else {
        throw new std::runtime_error("Using Stack::pop() on an empty data structure is forbidden.");
    }
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return this->count == 0;
}