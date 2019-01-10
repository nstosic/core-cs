#include "list.h"

template <typename T>
List<T>::List() {
    this->head = nullptr;
}

template <typename T>
List<T>::~List() {
    Node<T>* temp = this->head;
    while (temp != nullptr) {
        this->head = this->head->getNext();
        delete temp;
        temp = this->head;
    }
}

template <typename T>
Node<T>* List<T>::getHead() const {
    return this->head;
}

template <typename T>
void List<T>::add(Node<T>* node) {
    if (this->head == nullptr) {
        this->head = node;
    } else {
        Node<T>* temp = this->head;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(node);
    }
}

template <typename T>
void List<T>::add(T data) {
    if (this->head == nullptr) {
        this->head = new Node<T>(data);
    } else {
        Node<T>* temp = this->head;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(new Node<T>(data));
    }
}

template <typename T>
bool List<T>::isEmpty() const {
    return this->head == nullptr;
}

template <typename T>
int List<T>::size() const {
    Node<T>* temp = this->head;
    int count = 0;
    while(temp != nullptr) {
        count++;
        temp = temp->getNext();
    }
}