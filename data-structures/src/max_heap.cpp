#include "max_heap.h"

template <typename T>
void MaxHeap<T>::BubbleUp() {
    if (this->buffer_->size() < 2) {
        return;
    }
    T temp = (*(this->buffer_))[this->buffer_->size() - 1L];
    unsigned long ind = (this->buffer_->size() - 2L) / 2L;
    unsigned long prev = this->buffer_->size() - 1L;
    while (prev > 0 && temp > (*(this->buffer_))[ind]) {
        prev = ind;
        ind = (ind - 1L) / 2L;
    }
    (*(this->buffer_))[this->buffer_->size() - 1] = (*(this->buffer_))[prev];
    (*(this->buffer_))[prev] = temp;
}

template <typename T>
void MaxHeap<T>::BubbleDown() {
    T temp = (*(this->buffer_))[0];
    unsigned long ind = 1;
    unsigned long position = 1;
    T child_value;
    for (; ind < this->buffer_->size(); ind = position) {
        if ((ind + 1 == this->buffer_->size()) || ((*(this->buffer_))[ind] > (*(this->buffer_))[ind + 1])) {
            child_value = (*(this->buffer_))[ind];
            position = 2 * ind + 1;
        } else {
            child_value = (*(this->buffer_))[ind + 1];
            position = 2 * ind + 3;
        }
        if (temp < child_value) {
            (*(this->buffer_))[(ind - 1) / 2] = (*(this->buffer_))[ind + (position - 2 * ind) / 3];
            (*(this->buffer_))[ind + (position - 2 * ind) / 3] = temp;
        } else {
            break;
        }
    }
}

template class MaxHeap<int>; // forward resolution for template type used in unit tests