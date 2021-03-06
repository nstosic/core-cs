#include "node.h"

template <typename T>
Node<T>::Node(T t) {
    this->data_ = t;
    this->next_ = nullptr;
}

template <typename T>
void Node<T>::SetData(T t) {
    this->data_ = t;
}

template <typename T>
T Node<T>::GetData() const {
    return this->data_;
}

template<typename T>
void Node<T>::SetNext(Node<T>* node) {
    this->next_ = node;
}

template<typename T>
void Node<T>::SetNext(T t) {
    this->next_ = new Node(t);
}

template<typename T>
Node<T>* Node<T>::GetNext() const {
    return this->next_;
}

template <typename T>
bool operator==(const Node<T>& lhs, const Node<T>& rhs) {
    return lhs.GetData() == rhs.GetData();
}

template <typename T>
bool operator!=(const Node<T>& lhs, const Node<T>& rhs) {
    return !(lhs==rhs);
}

template class Node<int>; // forward resolution for template type used in unit tests
template class Node<const char*>; // forward resolution for template type used in unit tests
template bool operator==<int>(const Node<int>& lhs, const Node<int>& rhs);
template bool operator!=<int>(const Node<int>& lhs, const Node<int>& rhs);