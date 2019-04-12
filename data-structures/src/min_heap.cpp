#include "min_heap.h"

template <typename T>
void MinHeap<T>::BubbleUp() {
    T temp = (*(this->buffer_))[this->buffer_->size() - 1L];
    unsigned long ind = (this->buffer_->size() - 2L) / 2L;
    unsigned long prev = this->buffer_->size() - 1L;
    while (prev > 0 && temp < (*(this->buffer_))[ind]) {
        prev = ind;
        ind = (ind - 1L) / 2L;
    }
    (*(this->buffer_))[this->buffer_->size() - 1] = (*(this->buffer_))[prev];
    (*(this->buffer_))[prev] = temp;
}

template <typename T>
void MinHeap<T>::BubbleDown() {
    T temp = (*(this->buffer_))[0];
    unsigned long ind = 1;
    bool violated = true;
    while (violated && ind < this->buffer_->size()) {
        violated = false;
        if (temp > (*(this->buffer_))[ind]) {
            (*(this->buffer_))[(ind - 1) / 2] = (*(this->buffer_))[ind];
            (*(this->buffer_))[ind] = temp;
            violated = true;
            ind = 2 * ind + 1;
        } else if (temp > (*(this->buffer_))[ind + 1]) {
            (*(this->buffer_))[(ind - 1) / 2] = (*(this->buffer_))[ind];
            (*(this->buffer_))[ind] = temp;
            violated = true;
            ind = 2 * ind + 3;
        }
    }
}

template class MinHeap<int>; // forward resolution for template type used in unit tests