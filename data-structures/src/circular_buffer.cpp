#include "circular_buffer.h"

CircularBuffer::CircularBuffer(unsigned int size) {
    this->size_ = size;
    this->head_ = -1;
    this->tail_ = 0;
    this->buffer_ = new int[size_];
}

CircularBuffer::~CircularBuffer() {
    delete[] this->buffer_;
}

bool CircularBuffer::Produce(int data) {
    std::lock_guard<std::mutex> lock(this->mutex_);
    if (this->tail_ != this->head_) {
        this->buffer_[this->tail_] = data;
        if (this->head_ == -1) {
            this->head_ = this->tail_;
        }
        this->tail_ = (this->tail_ + 1) % (int)this->size_;
        return true;
    }
    return false;
}

int CircularBuffer::Consume() {
    std::lock_guard<std::mutex> lock(this->mutex_);
    int data = -1;
    if (this->head_ != -1) {
        data = this->buffer_[this->head_];
        this->head_ = (this->head_ + 1) % (int)this->size_;
        if (this->head_ == this->tail_) {
            this->head_ = -1;
        }
    }
    return data;
}

unsigned int CircularBuffer::Size() const {
    return this->size_;
}

int CircularBuffer::Available() {
    std::lock_guard<std::mutex> lock(this->mutex_);
    if (this->head_ == -1) {
        return (int)this->size_;
    }
    if (this->head_ >= this->tail_) {
        return this->head_ - this->tail_;
    } else {
        return (int)this->size_ - this->tail_ + this->head_;
    }
}