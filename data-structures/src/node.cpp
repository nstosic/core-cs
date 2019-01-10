#include "node.h"

template <typename T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = nullptr;
}

template <typename T>
Node<T>::~Node() {
    delete this->next;
}

template <typename T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template<typename T>
void Node<T>::setNext(T data) {
    this->next = new Node(data);
}

template<typename T>
Node<T>* Node<T>::getNext() const {
    return this->next;
}