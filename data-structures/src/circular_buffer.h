#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <mutex>

class CircularBuffer {
private:
    unsigned int size_;
    int head_;
    int tail_;
    int* buffer_;
    std::mutex mutex_;
public:
    CircularBuffer(unsigned int size);
    ~CircularBuffer();
    void Produce(int data);
    int Consume();
    unsigned int Size() const;
    int Available();
};

#endif