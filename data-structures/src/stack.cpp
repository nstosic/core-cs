#include "stack.h"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
Stack<T>::Stack() {
    this->top_ = nullptr;
    this->count_ = 0;
}

template <typename T>
Stack<T>::~Stack() {
    Node<T> *temp = this->top_;
    while(temp != nullptr) {
        this->top_ = temp->GetNext();
        delete temp;
        temp = this->top_;
    }
}

template <typename T>
void Stack<T>::Push(T data) {
    Node<T> *temp = new Node<T>(data);
    temp->SetNext(this->top_);
    this->top_ = temp;
    this->count_++;
}

template <typename T>
T Stack<T>::Pop() {
    if (this->top_ != nullptr) {
        T data = this->top_->GetData();
        this->top_ = this->top_->GetNext();
        this->count_--;
        return data;
    } else {
        throw new std::runtime_error("Using Stack::pop() on an empty data structure is forbidden.");
    }
}

template <typename T>
T Stack<T>::Peek() const {
    if (this->top_ != nullptr) {
        return this->top_->GetData();
    } else {
        throw new std::runtime_error("Using Stack::pop() on an empty data structure is forbidden.");
    }
}

template <typename T>
int Stack<T>::Size() const {
    return this->count_;
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return this->count_ == 0;
}

template class Stack<int>; // forward resolution for template type used in unit tests
template class Stack<const char*>; // forward resolution for template type used in unit tests
