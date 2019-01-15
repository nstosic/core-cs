#include "list.h"

template <typename T>
List<T>::List() {
    this->head = nullptr;
}

template <typename T>
List<T>::~List() {
    Node<T>* temp = this->head_;
    while (temp != nullptr) {
        this->head_ = this->head_->getNext();
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
        temp = temp->getNext();
    }
    return count;
}
