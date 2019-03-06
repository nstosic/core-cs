#include "double_linked_node.h"

template <typename T>
DoubleLinkedNode<T>::DoubleLinkedNode(T data) : DoubleLinkedNode(data, nullptr, nullptr) {}

template <typename T>
DoubleLinkedNode<T>::DoubleLinkedNode(T data, DoubleLinkedNode<T>* next, DoubleLinkedNode<T>* prev) {
    this->data_ = data;
    this->next_ = next;
    this->prev_ = prev;
}

template <typename T>
void DoubleLinkedNode<T>::setData(T data) {
    this->data_ = data;
}

template <typename T>
T DoubleLinkedNode<T>::getData() const {
    return this->data_;
}

template <typename T>
void DoubleLinkedNode<T>::setNext(DoubleLinkedNode<T>* next) {
    this->next_ = next;
}

template <typename T>
DoubleLinkedNode<T>* DoubleLinkedNode<T>::getNext() const {
    return this->next_;
}

template <typename T>
void DoubleLinkedNode<T>::setPrev(DoubleLinkedNode<T>* prev) {
    this->prev_ = prev;
}

template <typename T>
DoubleLinkedNode<T>* DoubleLinkedNode<T>::getPrev() const {
    return this->prev_;
}

template class DoubleLinkedNode<int>; // forward resolution for template type used in unit tests