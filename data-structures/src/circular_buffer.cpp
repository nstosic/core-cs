#include "circular_buffer.h"

CircularBuffer::CircularBuffer(unsigned int size) {
    this->size_ = size;
    this->head_ = 0;
    this->tail_ = 0;
    this->buffer_ = new int[size_];
}

CircularBuffer::~CircularBuffer() {
    delete[] this->buffer_;
}

void CircularBuffer::Produce(int data) {
    std::lock_guard<std::mutex> lock(mutex_);
    if ((tail_ + 1) % size_ != head_) {
        buffer_[tail_] = data;
        tail_ = (tail_ + 1) % size_;
    }
}

int CircularBuffer::Consume() {
    std::lock_guard<std::mutex> lock(mutex_);
    int data;
    if (head_ != tail_) {
        data = buffer_[head_];
        head_ = (head_ + 1) % size_;
    }
    return data;
}

unsigned int CircularBuffer::Size() const {
    return this->size_;
}

int CircularBuffer::Available() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (head_ > tail_) {
        return head_ - tail_ - 1;
    } else {
        return size_ = tail_ + head_ - 1;
    }
}