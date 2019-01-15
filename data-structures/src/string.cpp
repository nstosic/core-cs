#include "string.h"
#include <stdio.h>
#include <cstring>

String::String() {
    this->buffer_ = nullptr;
    this->count_ = 0L;
}

String::~String() {
    delete[] this->buffer_;
}

unsigned long String::Length() const {
    return this->count_;
}

void String::Print() const {
    int index = 0;
    while(buffer_[index] != '\0') {
        printf("%c", buffer_[index]);
    }
}

const char* String::UnsafePointer() const {
    return this->buffer_;
}

// Operator overloading
void String::operator= (const char* data) {
    delete[] this->buffer_;
    count_ = sizeof(data);
    this->buffer_ = new char[count_];
    memcpy(this->buffer_, data, count_);
}