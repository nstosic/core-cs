#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <mutex>

class CircularBuffer {
private:
    int* buffer_;
    unsigned int size_;
    int head_;
    int tail_;
    std::mutex mutex_;
public:
    CircularBuffer(unsigned int size);
    ~CircularBuffer();
    bool Produce(int data);
    int Consume();
    unsigned int Size() const;
    int Available();
};

#endif