#include "heap.h"
#include "exceptions.h"
#include <algorithm>

template <typename T>
Heap<T>::Heap() {
    this->buffer_ = new std::vector<T>();
}

template <typename T>
Heap<T>::~Heap() = default;

template <typename T>
void Heap<T>::Add(const T value) {
    this->buffer_->push_back(value);
    this->BubbleUp();
}

template <typename T>
const T Heap<T>::GetTop() const {
    if (this->buffer_->empty()) {
        throw HeapEmptyException("Illegal call to GetTop() on an empty heap");
    }
    return (*(this->buffer_))[0];
}

template <typename T>
void Heap<T>::RemoveTop() {
    if (this->buffer_->empty()) {
        throw HeapEmptyException("Illegal call to RemoveTop() on an empty heap");
    }
    std::iter_swap(this->buffer_->begin(), this->buffer_->begin() + (int)this->buffer_->size() - 1);
    this->buffer_->pop_back();
    this->BubbleDown();
}

template <typename T>
unsigned long Heap<T>::Size() const {
    return this->buffer_->size();
}

template class Heap<int>; // forward resolution for template type used in unit tests