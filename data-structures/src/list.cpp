#include "list.h"

template <typename T>
List<T>::List() {
    this->head_ = nullptr;
}

template <typename T>
List<T>::~List() {
    Node<T>* temp = this->head_;
    while (temp != nullptr) {
        this->head_ = this->head_->GetNext();
        delete temp;
        temp = this->head_;
    }
}

template <typename T>
Node<T>* List<T>::GetHead() const {
    return this->head_;
}

template <typename T>
void List<T>::Add(Node<T>* node) {
    if (this->head_ == nullptr) {
        this->head_ = node;
    } else {
        Node<T>* temp = this->head_;
        while (temp->GetNext() != nullptr) {
            temp = temp->GetNext();
        }
        temp->SetNext(node);
    }
}

template <typename T>
void List<T>::Add(T data) {
    if (this->head_ == nullptr) {
        this->head_ = new Node<T>(data);
    } else {
        Node<T>* temp = this->head_;
        while (temp->GetNext() != nullptr) {
            temp = temp->GetNext();
        }
        temp->SetNext(new Node<T>(data));
    }
}

template <typename T>
bool List<T>::IsEmpty() const {
    return this->head_ == nullptr;
}

template <typename T>
int List<T>::Size() const {
    Node<T>* temp = this->head_;
    int count = 0;
    while(temp != nullptr) {
        count++;
        temp = temp->GetNext();
    }
    return count;
}

template <typename T>
bool operator==(const List<T>& lhs, const List<T>& rhs) {
    if (lhs.Size() != rhs.Size()) {
        return false;
    }
    Node<T>* lhs_node = lhs.GetHead();
    Node<T>* rhs_node = rhs.GetHead();
    while (lhs_node != nullptr) {
        if (*lhs_node != *rhs_node) {
            return false;
        }
        lhs_node = lhs_node->GetNext();
        rhs_node = rhs_node->GetNext();
    }
    return true;
}

template class List<int>; // forward resolution for template type used in unit tests
template bool operator==<int>(const List<int>&, const List<int>&);