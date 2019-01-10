#include "node.h"

template <typename T>
Node<T>::Node(T t) {
    this->data = t;
    this->next = nullptr;
}

template <typename T>
Node<T>::~Node() {
    delete this->next;
}

template <typename T>
void Node<T>::setData(T t) {
    this->data = t;
}

template <typename T>
T Node<T>::getData() const {
    return this->data;
}

template<typename T>
void Node<T>::setNext(Node<T>* node) {
    this->next = node;
}

template<typename T>
void Node<T>::setNext(T t) {
    this->next = new Node(t);
}

template<typename T>
Node<T>* Node<T>::getNext() const {
    return this->next;
}

template class Node<int>; // forward resolution for template type used in unit tests
